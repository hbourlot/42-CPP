#pragma once

#include <exception>
#include <iostream>
#include <list>
#include <string>
#include <utility>

#define RED "\033[31m"
#define RESET "\033[0m"

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

template < template < typename, typename > class cT, typename T > class ListWrapper {
  private:
	cT< T, std::allocator< T > > _data;

  public:
	typedef typename std::list< T >::value_type value_type;
	typedef typename std::list< T >::allocator_type Allocator;
	typedef typename std::list< T >::size_type size_type;
	typedef typename std::list< T >::reference reference;
	typedef typename std::list< T >::const_reference const_reference;
	typedef typename std::list< T >::iterator iterator;
	typedef typename std::list< T >::const_iterator const_iterator;

	// default constructor
	ListWrapper() : _data() {};

	template < typename InputIt > ListWrapper(InputIt begin, InputIt end) : _data(begin, end){};

	// copy constructor
	ListWrapper(const ListWrapper &other) : _data(other._data) {};

	// assignment operator
	ListWrapper &operator=(const ListWrapper &other) {
		if (this != &other) {
			_data = other._data;
		}
		return *this;
	};

	// Destructor
	~ListWrapper() {};

	// element access (non-const)
	T &operator[](size_t index) {
		if (index >= _data.size())
			throw std::out_of_range("Index out of range");

		iterator it = _data.begin();
		std::advance(it, index);
		return *it;
	}

	// element access (const)
	const T &operator[](size_t index) const {
		if (index >= _data.size())
			throw std::out_of_range("Index out of range");

		const_iterator it = _data.begin();
		std::advance(it, index);
		return *it;
	}

	// forward methods
	void push_back(const T &value) {
		_data.push_back(value);
	};

	size_t size() const {
		return _data.size();
	};

	bool empty() const {
		return _data.empty();
	}

	void clear() {
		return _data.clear();
	};

	T back() const {
		return _data.back();
	}

	iterator begin() {
		return _data.begin();
	};

	const_iterator begin() const {
		return _data.begin();
	};

	iterator end() {
		return _data.end();
	};

	const_iterator end() const {
		return _data.end();
	};

	iterator insert(iterator pos, const T &value) {
		return _data.insert(pos, value);
	};

	void insert(iterator pos, size_type count, const T &value) {
		_data.insert(pos, count, value);
	};

	// insert range of elements
	template < typename iT > void insert(iterator pos, iT first, iT last) {
		_data.insert(pos, first, last);
	};
};

typedef ListWrapper< std::list, Pair >::iterator PairIterator_t;
typedef ListWrapper< std::list, Pair >::const_iterator ConstPairIterator_t;

typedef ListWrapper< std::list, int >::iterator IntIterator_t;
typedef ListWrapper< std::list, int >::const_iterator ConstIntIterator_t;

typedef ListWrapper< std::list, int > listIntType_t;
typedef ListWrapper< std::list, Pair > listPairType_t;

void readTerminal();
void parseInput(char **av);
void convertInputIntoContainer(char **av, std::list< int > &);
// listIntType_t mergeInsertionAlgorithm(listIntType_t input);

// ---------- Ford-Johnson sequence ----------
// Book's formula => t_k = (2^(k+1) + (-1)^k) / 3
int fordJohnsonTk(int k) {
	return (pow(2, (k + 1)) + ((k % 2 == 0) ? 1 : -1)) / 3;
};

// Generate sequence up to n
listIntType_t fordJohnsonSeq(int n) {

	int tk, k;
	listIntType_t seq;

	k = 1;

	while (true) {
		tk = fordJohnsonTk(k);
		if (tk > n)
			break;
		seq.push_back(tk);
		k++;
	}
	return seq;
};

// ---------- Pairing Step ----------

// listPairType_t makePairs(listIntType_t &input, bool &hasLeftover, int &leftover) {
template < typename CInt, typename CPair > CPair makePairs(CInt &input, bool &hasLeftover, int &leftover, CPair pairs) {

	// CPair pairs;
	// listPairType_t pairs;
	int first, second;
	hasLeftover = false;
	pairs.clear(); // !!!!!!!
	typename CInt::iterator it = input.begin();
	typename CInt::iterator end = input.end();
	// IntIterator_t it = input.begin();
	// IntIterator_t end = input.end();
	Pair uniquePair;

	while (it != input.end()) {

		first = *it++;
		if (it == end) {
			leftover = first;
			hasLeftover = true;
			break;
		}
		second = *it++;
		if (first > second) {
			uniquePair.a = first;
			uniquePair.b = second;
		} else {
			uniquePair.a = second;
			uniquePair.b = first;
		}
		pairs.push_back(uniquePair);
	}
	return pairs;
};

// ---------- Recursive sort of the a's ----------
template < typename CInt, typename CPair > CInt mergeInsertionAlgorithm(CInt input);
// listIntType_t mergeInsertionAlgorithm(listIntType_t input);

// ---------- Main merge-insertion algorithm ----------
// listIntType_t recursiveSortA(const listPairType_t &pairs) {
template < typename CInt, typename CPair > CInt recursiveSortA(const CPair &pairs, CInt input) {

	CInt listA;
	(void)input;
	typename CPair::const_iterator it = pairs.begin();
	// ConstPairIterator_t it = pairs.begin();
	typename CPair::const_iterator end = pairs.end();
	// ConstPairIterator_t end = pairs.end();
	for (; it != end; ++it) {
		const Pair &uniquePair = *it;
		listA.push_back(uniquePair.a);
	}
	listA = mergeInsertionAlgorithm< CInt, CPair >(listA);
	return CInt(listA.begin(), listA.end());
};

// ---------- Insert b's ----------
// listIntType_t insertBs(listIntType_t mainChain, const listPairType_t &pairs) {
// template < typename CInt, typename CPair > CInt insertBs(CInt mainChain, const CPair &pairs) {

// 	int n, start, end, bj;
// 	// listIntType_t tks;
// 	CInt tks;

// 	n = pairs.size();
// 	tks = fordJohnsonSeq(n);

// 	for (size_t i = 1; i < tks.size(); i++) {
// 		start = tks[i - 1] + 1;
// 		end = tks[i];
// 		for (int j = end; j >= start; j--) {
// 			bj = pairs[j - 1].b;
// 			typename CInt::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), bj);
// 			// listIntType_t::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), bj);
// 			mainChain.insert(pos, bj);
// 		}
// 	}

// 	if (!tks.empty() && tks.back() < n) {
// 		for (int j = n; j > tks.back(); j--) {
// 			bj = pairs[j - 1].b;
// 			typename CInt::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), bj);
// 			// listIntType_t::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), bj);
// 			mainChain.insert(pos, bj);
// 		}
// 	}

// 	return mainChain;
// };
template < typename CInt, typename CPair > CInt insertBs(CInt mainChain, const CPair &pairs) {

	int n, start, end, bj;
	CInt tks;

	n = pairs.size();
	tks = fordJohnsonSeq(n);

	if (tks.size() < 2)
		return mainChain;

	typename CInt::const_iterator prev = tks.begin();
	typename CInt::const_iterator curr = ++tks.begin();

	for (; curr != tks.end(); ++curr, ++prev) {
		start = *prev + 1;
		end = *curr;

		typename CPair::const_iterator it = pairs.begin();
		std::advance(it, end - 1);

		for (int j = end; j >= start; --j; --it) {
			bj = it->b;
			typename CInt::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), bj);
			mainChain.insert(pos, bj);
		}
	}

	if (!tks.empty() && *std::prev(tks.end()) < n) {
		typename CPair::const_iterator it = pairs.end();
		--it;
		for (int j = n; j > *std::prev(tks.end()); --j; --it) {
			bj = it->b;

			typename CInt::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), bj);
			mainChain.insert(pos, bj);
		}
	}

	return mainChain;
};

// ---------- Main merge-insertion algorithm ----------

// listIntType_t mergeInsertionAlgorithm(listIntType_t input) {
template < typename CInt, typename CPair > CInt mergeInsertionAlgorithm(CInt input) {

	bool hasLeftover;
	int leftover, a;
	CPair pairs;
	// listPairType_t pairs;

	if (input.size() <= 1)
		return input;

	hasLeftover = false;
	leftover = 0;
	pairs = makePairs(input, hasLeftover, leftover, pairs);

	// Step 2 : recursively sort A
	// listIntType_t sortedA = recursiveSortA(pairs);
	CInt sortedA = recursiveSortA(pairs, input);

	// Step 3: build main chain = {b1} U {sorted a’s}
	// listIntType_t mainChain;
	CInt mainChain;
	mainChain.push_back(pairs[0].b); // first b
	mainChain.insert(mainChain.end(), sortedA.begin(), sortedA.end());

	// Step 4: insert b's
	mainChain = insertBs(mainChain, pairs);

	// Step 5: insert leftover if odd
	if (hasLeftover) {
		// IntIterator_t pos = std::lower_bound(mainChain.begin(), mainChain.end(), leftover);
		typename CInt::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), leftover);

		mainChain.insert(pos, leftover);
	}

	return mainChain;
};

//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//

//
//

//  --- Dijkstra Functions

/// @brief Checks if the given command represents a special block (Start "S" or End "E")
///        that already exists in the container.
/// @param container The list of existing DijkstraBlocks.
/// @param command The block type to check (e.g., "S", "E", ".", "#").
/// @return true if the block already exists (for "S" or "E"), false otherwise.
void addBlock(const std::string &command, std::list< DijkstraBlock > &container);

/// @brief Creates and initializes a DijkstraBlock based on its representation.
///        - "S" (Start) is initialized with distance = 0.
///        - All other blocks are initialized with distance = INT_MAX.
/// @param representation The string identifier of the block (e.g., "S", "E", ".", "#", "N").
/// @return A new DijkstraBlock with default properties set.
DijkstraBlock createDijkstraBlock(std::string representation);

/// @brief Executes Dijkstra's algorithm on the given container.
///        Updates the distance and previous pointers of each block to compute
///        the shortest path from Start ("S") to End ("E").
/// @param container The container of DijkstraBlocks representing the grid.
void displayBlocks(std::list< DijkstraBlock > &container);

/// @brief Displays the rules and key representations used in the Dijkstra grid.
///        Shows the meaning of each symbol (S, E, F, N, B) for user reference.
void displayRules();

/// @brief Executes Dijkstra's algorithm on the given container.
///        Updates the distance and previous pointers of each block to compute
///        the shortest path from Start ("S") to End ("E").
/// @param container The container of DijkstraBlocks representing the grid.
void performDijkstra(std::list< DijkstraBlock > &container);

/// @brief Prints the grid of Dijkstra blocks with the shortest path highlighted.
///        Blocks on the shortest path from Start ("S") to End ("E") are printed
///        in red, using the same layout style as displayBlocks.
/// @param container The container of DijkstraBlocks representing the grid.
void printShortestPath(const std::list< DijkstraBlock > &container);

/// @brief Runs the complete Dijkstra pathfinding process:
///        - Reads user input for blocks
///        - Displays rules
///        - Performs Dijkstra’s algorithm
///        - Prints the shortest path result
void dijkstra();
