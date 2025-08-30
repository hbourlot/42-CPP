#include "PmergeMe.hpp"

// ---------- Ford-Johnson sequence ----------
// Book's formula => t_k = (2^(k+1) + (-1)^k) / 3
// int fordJohnsonTk(int k) {
// 	return (pow(2, (k + 1)) + ((k % 2 == 0) ? 1 : -1)) / 3;
// };

// Generate sequence up to n
// listIntType_t fordJohnsonSeq(int n) {

// 	int tk, k;
// 	listIntType_t seq;

// 	k = 1;

// 	while (true) {
// 		tk = fordJohnsonTk(k);
// 		if (tk > n)
// 			break;
// 		seq.push_back(tk);
// 		k++;
// 	}
// 	return seq;
// };

// // ---------- Pairing Step ----------

// // listPairType_t makePairs(listIntType_t &input, bool &hasLeftover, int &leftover) {
// template < typename CInt, typename CPair > CPair makePairs(CInt &input, bool &hasLeftover, int &leftover, CPair
// pairs) {

// 	// CPair pairs;
// 	// listPairType_t pairs;
// 	int first, second;
// 	hasLeftover = false;
// 	pairs.clear(); // !!!!!!!
// 	typename CInt::iterator it = input.begin();
// 	typename CInt::iterator end = input.end();
// 	// IntIterator_t it = input.begin();
// 	// IntIterator_t end = input.end();
// 	Pair uniquePair;

// 	while (it != input.end()) {

// 		first = *it++;
// 		if (it == end) {
// 			leftover = first;
// 			hasLeftover = true;
// 			break;
// 		}
// 		second = *it++;
// 		if (first > second) {
// 			uniquePair.a = first;
// 			uniquePair.b = second;
// 		} else {
// 			uniquePair.a = second;
// 			uniquePair.b = first;
// 		}
// 		pairs.push_back(uniquePair);
// 	}
// 	return pairs;
// };

// // ---------- Recursive sort of the a's ----------
// template < typename Container > Container mergeInsertionAlgorithm(Container input);
// // listIntType_t mergeInsertionAlgorithm(listIntType_t input);

// // ---------- Main merge-insertion algorithm ----------
// // listIntType_t recursiveSortA(const listPairType_t &pairs) {
// template < typename CInt, typename CPair > CInt recursiveSortA(const CPair &pairs, CInt input) {

// 	CInt listA;
// 	(void)input;
// 	typename CPair::const_iterator it = pairs.begin();
// 	// ConstPairIterator_t it = pairs.begin();
// 	typename CPair::const_iterator end = pairs.end();
// 	// ConstPairIterator_t end = pairs.end();
// 	for (; it != end; ++it) {
// 		const Pair &uniquePair = *it;
// 		listA.push_back(uniquePair.a);
// 	}
// 	listA = mergeInsertionAlgorithm(listA);
// 	return CInt(listA.begin(), listA.end());
// };

// // ---------- Insert b's ----------
// // listIntType_t insertBs(listIntType_t mainChain, const listPairType_t &pairs) {
// // template < typename CInt, typename CPair > CInt insertBs(CInt mainChain, const CPair &pairs) {

// // 	int n, start, end, bj;
// // 	// listIntType_t tks;
// // 	CInt tks;

// // 	n = pairs.size();
// // 	tks = fordJohnsonSeq(n);

// // 	for (size_t i = 1; i < tks.size(); i++) {
// // 		start = tks[i - 1] + 1;
// // 		end = tks[i];
// // 		for (int j = end; j >= start; j--) {
// // 			bj = pairs[j - 1].b;
// // 			typename CInt::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), bj);
// // 			// listIntType_t::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), bj);
// // 			mainChain.insert(pos, bj);
// // 		}
// // 	}

// // 	if (!tks.empty() && tks.back() < n) {
// // 		for (int j = n; j > tks.back(); j--) {
// // 			bj = pairs[j - 1].b;
// // 			typename CInt::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), bj);
// // 			// listIntType_t::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), bj);
// // 			mainChain.insert(pos, bj);
// // 		}
// // 	}

// // 	return mainChain;
// // };

// // ---------- Main merge-insertion algorithm ----------

// // listIntType_t mergeInsertionAlgorithm(listIntType_t input) {
// template < typename CInt, typename CPair > CInt mergeInsertionAlgorithm(CInt input) {

// 	bool hasLeftover;
// 	int leftover, a;
// 	CPair pairs;
// 	// listPairType_t pairs;

// 	if (input.size() <= 1)
// 		return input;

// 	hasLeftover = false;
// 	leftover = 0;
// 	pairs = makePairs(input, hasLeftover, leftover, pairs);

// 	// Step 2 : recursively sort A
// 	// listIntType_t sortedA = recursiveSortA(pairs);
// 	CInt sortedA = recursiveSortA(pairs, input);

// 	// Step 3: build main chain = {b1} U {sorted a’s}
// 	// listIntType_t mainChain;
// 	CInt mainChain;
// 	mainChain.push_back(pairs[0].b); // first b
// 	mainChain.insert(mainChain.end(), sortedA.begin(), sortedA.end());

// 	// Step 4: insert b's
// 	mainChain = insertBs(mainChain, pairs);

// 	// Step 5: insert leftover if odd
// 	if (hasLeftover) {
// 		// IntIterator_t pos = std::lower_bound(mainChain.begin(), mainChain.end(), leftover);
// 		typename CInt::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), leftover);

// 		mainChain.insert(pos, leftover);
// 	}

// 	return mainChain;
// };

// ---------------- Demo ----------------
int main() {

	std::list< int > l = {50, 20, 80, 10, 60, 40, 70, 30, 90, 5, 25};
	std::deque< int > d = {50, 20, 80, 10, 60, 40, 70, 30, 90, 5, 25};
	listIntType_t input(l.begin(), l.end());

	// ListWrapper< std::deque, int > inputDeque(d.begin(), d.end());
	// listIntType_t sorted = mergeInsertionAlgorithm< listIntType_t, listPairType_t >(input);
	std::deque< int > sorted = mergeInsertionAlgorithm< std::deque< int >, std::deque< Pair > >(d);

	// ListWrapper< std::deque, int > sortedDeque =
	// mergeInsertionAlgorithm< ListWrapper< std::deque, int >, std::deque< Pair > >(inputDeque);

	std::cout << "Sorted: ";
	for (int x : sorted)
		std::cout << x << " ";
	std::cout << "\n";

	std::cout << "\n";

	return 0;
}