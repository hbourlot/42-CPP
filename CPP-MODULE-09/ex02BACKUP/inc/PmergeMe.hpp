#pragma once

#include <ctime>
#include <deque>
#include <exception>
#include <iomanip> // for std::fixed and std::setprecision
#include <iostream>
#include <list>
#include <string>
#include <utility>
#include <vector>

#define RED "\033[31m"
#define RESET "\033[0m"

#ifndef BONUS
#define BONUS false
#endif

struct DijkstraBlock {
		int distance;
		std::string rep;
		int x, y;
		DijkstraBlock *previous;
};

struct Pair {
		int a; // larger
		int b; // smaller
};

// ---------- Ford-Johnson sequence ----------
// Book's formula => t_k = (2^(k+1) + (-1)^k) / 3
template < typename Int > Int fordJohnsonTk( Int k ) {
	return ( pow( 2, ( k + 1 ) ) + ( ( k % 2 == 0 ) ? 1 : -1 ) ) / 3;
};

// Generate sequence up to n
template < typename IntContainer > IntContainer fordJohnsonSeq( int n ) {

	int tk, k;
	IntContainer seq;

	k = 1;

	while ( true ) {
		tk = fordJohnsonTk( k );
		if ( tk > n )
			break;
		seq.push_back( tk );
		k++;
	}
	return seq;
};

// ---------- Pairing Step ----------

template < typename IntContainer, typename PairContainer >
PairContainer makePairs( IntContainer &input, bool &hasLeftover, int &leftover ) {

	int first, second;
	PairContainer pairs;
	Pair uniquePair;

	typename IntContainer::iterator it = input.begin();
	typename IntContainer::iterator end = input.end();

	hasLeftover = false;

	while ( it != input.end() ) {

		first = *it++;
		if ( it == end ) {
			leftover = first;
			hasLeftover = true;
			break;
		}
		second = *it++;
		if ( first > second ) {
			uniquePair.a = first;
			uniquePair.b = second;
		} else {
			uniquePair.a = second;
			uniquePair.b = first;
		}
		pairs.push_back( uniquePair );
	}
	return pairs;
};

// ---------- Recursive sort of the a's ----------
template < typename IntContainer, typename PairContainer > IntContainer mergeInsertionAlgorithm( IntContainer input );

// ---------- Main merge-insertion algorithm ----------
template < typename IntContainer, typename PairContainer > IntContainer recursiveSortA( const PairContainer &pairs ) {

	IntContainer listA;
	typename PairContainer::const_iterator it = pairs.begin();
	typename PairContainer::const_iterator end = pairs.end();

	for ( ; it != end; ++it ) {
		const Pair &uniquePair = *it;
		listA.push_back( uniquePair.a );
	}
	listA = mergeInsertionAlgorithm< IntContainer, PairContainer >( listA );
	return IntContainer( listA.begin(), listA.end() );
};

// ---------- Insert b's ----------
template < typename IntContainer, typename PairContainer >
IntContainer insertBs( IntContainer mainChain, const PairContainer &pairs ) {

	int n, start, end, bj;
	IntContainer tks;

	n = pairs.size();
	tks = fordJohnsonSeq< IntContainer >( n );

	if ( tks.size() < 2 )
		return mainChain;

	typename IntContainer::const_iterator prev = tks.begin();
	typename IntContainer::const_iterator curr = ++tks.begin();

	for ( ; curr != tks.end(); ++curr, ++prev ) {
		start = *prev + 1;
		end = *curr;

		typename PairContainer::const_iterator it = pairs.begin();
		std::advance( it, end - 1 );

		for ( int j = end; j >= start; --j, --it ) {
			bj = it->b;
			typename IntContainer::iterator pos = std::lower_bound( mainChain.begin(), mainChain.end(), bj );
			mainChain.insert( pos, bj );
		}
	}

	if ( !tks.empty() && *std::prev( tks.end() ) < n ) {
		typename PairContainer::const_iterator it = pairs.end();
		--it;
		for ( int j = n; j > *std::prev( tks.end() ); --j ) {
			--it;
			bj = it->b;

			typename IntContainer::iterator pos = std::lower_bound( mainChain.begin(), mainChain.end(), bj );
			mainChain.insert( pos, bj );
		}
	}

	return mainChain;
};

// ---------- Main merge-insertion algorithm ----------

/// @brief Performs the full merge-insertion sort on a container of integers.
/// @tparam IntContainer Container type for integers (e.g., std::list<int>)
/// @tparam PairContainer Container type for pairs (e.g., std::list<Pair>)
/// @param input Container of integers to sort
/// @return Sorted container
template < typename IntContainer, typename PairContainer > IntContainer mergeInsertionAlgorithm( IntContainer input ) {

	bool hasLeftover;
	int leftover, a;
	PairContainer pairs;

	if ( input.size() <= 1 )
		return input;

	hasLeftover = false;
	leftover = 0;
	pairs = makePairs< IntContainer, PairContainer >( input, hasLeftover, leftover );

	// Step 2 : recursively sort A
	IntContainer sortedA = recursiveSortA< IntContainer, PairContainer >( pairs );

	// Step 3: build main chain = {b1} U {sorted a’s}
	IntContainer mainChain;
	mainChain.push_back( pairs.front().b ); // first b
	mainChain.insert( mainChain.end(), sortedA.begin(), sortedA.end() );

	// Step 4: insert b's
	mainChain = insertBs( mainChain, pairs );

	// Step 5: insert leftover if odd
	if ( hasLeftover ) {
		typename IntContainer::iterator pos = std::lower_bound( mainChain.begin(), mainChain.end(), leftover );

		mainChain.insert( pos, leftover );
	}

	return mainChain;
};

/// @brief Converts terminal input arguments into a container of integers.
/// @tparam Container Container type to fill (e.g., std::list<int>, std::deque<int>)
/// @param av Array of terminal arguments
/// @return Container filled with integers parsed from av
template < typename Container > Container convertInputToContainer( char **av ) {

	int i = 1;
	int startIdx, j;
	Container container;

	while ( av && av[i] ) {
		j = 0;
		while ( av[i][j] ) {

			while ( av[i][j] && av[i][j] == ' ' ) // skipping spaces
				j++;

			startIdx = j;

			while ( av[i][j] && isdigit( av[i][j] ) ) // move j until non-digit
				j++;

			if ( startIdx < j ) {
				std::string valueStr( av[i] + startIdx, j - startIdx );
				container.push_back( std::stoi( valueStr ) );
			}
		}
		i++;
	}

	return container;
}

/// @brief Displays the elements of a container.
/// @tparam Container Container type
/// @param container Container to display
/// @param limit Maximum number of elements to display (-1 = all)
template < typename Container > void displayContainer( Container &container, int limit = -1 ) {

	int tot = 0;

	typename Container::iterator it = container.begin();
	while ( it != container.end() ) {
		if ( limit != -1 && tot == limit ) {
			std::cout << "[...]";
			break;
		}
		std::cout << *it << " ";
		it++;
		tot++;
	}
	std::cout << std::endl;
}

/// @brief Measures and displays the execution time of a function applied to a container.
/// @tparam Container Container type
/// @tparam Function Function type taking Container and returning Container
/// @param container Container to process
/// @param classType Name of the container class (e.g., "std::list")
/// @param Function Function to apply to the container
template < typename Container, typename Function >
void processContainerDisplay( Container container, std::string classType, Function( Container ) ) {

	long elapsed_us;
	double display_us;

	std::clock_t start = std::clock();
	Container sorted = Function( container );
	std::clock_t end = std::clock();

	elapsed_us = ( end - start ) * 1000000 / CLOCKS_PER_SEC;
	display_us = double( elapsed_us ) / 1000.0;

	std::cout << "Time to process a range of " << container.size() << " elements with " << classType << " : "
			  << std::fixed << std::setprecision( 5 ) << display_us << "us\n";
};

void readTerminal( int ac, char **av );
void parseInput( char **av );
int pMergeMe( int ac, char **av );

//  --- Dijkstra Functions

/// @brief Checks if the given command represents a special block (Start "S" or End "E")
///        that already exists in the container.
/// @param container The list of existing DijkstraBlocks.
/// @param command The block type to check (e.g., "S", "E", ".", "#").
/// @return true if the block already exists (for "S" or "E"), false otherwise.
void addBlock( const std::string &command, std::list< DijkstraBlock > &container );

/// @brief Creates and initializes a DijkstraBlock based on its representation.
///        - "S" (Start) is initialized with distance = 0.
///        - All other blocks are initialized with distance = INT_MAX.
/// @param representation The string identifier of the block (e.g., "S", "E", ".", "#", "N").
/// @return A new DijkstraBlock with default properties set.
DijkstraBlock createDijkstraBlock( std::string representation );

/// @brief Executes Dijkstra's algorithm on the given container.
///        Updates the distance and previous pointers of each block to compute
///        the shortest path from Start ("S") to End ("E").
/// @param container The container of DijkstraBlocks representing the grid.
void displayBlocks( std::list< DijkstraBlock > &container );

/// @brief Displays the rules and key representations used in the Dijkstra grid.
///        Shows the meaning of each symbol (S, E, F, N, B) for user reference.
void displayRules();

/// @brief Executes Dijkstra's algorithm on the given container.
///        Updates the distance and previous pointers of each block to compute
///        the shortest path from Start ("S") to End ("E").
/// @param container The container of DijkstraBlocks representing the grid.
void performDijkstra( std::list< DijkstraBlock > &container );

/// @brief Prints the grid of Dijkstra blocks with the shortest path highlighted.
///        Blocks on the shortest path from Start ("S") to End ("E") are printed
///        in red, using the same layout style as displayBlocks.
/// @param container The container of DijkstraBlocks representing the grid.
void printShortestPath( const std::list< DijkstraBlock > &container );

/// @brief Runs the complete Dijkstra pathfinding process:
///        - Reads user input for blocks
///        - Displays rules
///        - Performs Dijkstra’s algorithm
///        - Prints the shortest path result
void dijkstra();
