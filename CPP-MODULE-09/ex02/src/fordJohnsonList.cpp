#include "PmergeMe.hpp"

std::list< Pair > makePairs( std::list< int > &containerList, bool &hasLeftOver, int &leftover ) {

	int first, second;
	std::list< Pair > pairs;
	Pair uniquePair;

	std::list< int >::iterator it = containerList.begin();
	std::list< int >::iterator end = containerList.end();

	hasLeftOver = false;

	while ( it != end ) {
		first = *it++;
		if ( it == end ) {
			leftover = first;
			hasLeftOver = true;
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
}

std::list< int > recursiveSortA( std::list< Pair > &pairs ) {
	std::list< int > listA;
	std::list< Pair >::iterator it = pairs.begin();
	std::list< Pair >::iterator end = pairs.begin();

	for ( ; it != end; ++it ) {
		const Pair &uniquePair = *it;
		listA.push_back( uniquePair.a );
	}
	listA = fordJohnsonList( listA );
	return std::list< int >( listA.begin(), listA.end() );
}

std::list< int > fordJohnsonList( std::list< int > containerList ) {

	bool hasLeftOver;
	int leftover;
	std::list< Pair > pairs;

	if ( containerList.size() <= 1 )
		return containerList;

	hasLeftOver = false;
	leftover = 0;
	pairs = makePairs( containerList, hasLeftOver, leftover );

	// Step 2 : recursively sort A
	std::list< int > sortedA = recursiveSortA( pairs );

	// Step 3 : build main chain = {b1} U {sorted a's}
	std::list< int > mainChain;
	mainChain.push_back( pairs.front().b ); // first B
	mainChain.insert( mainChain.end(), sortedA.begin(), sortedA.end() );
}