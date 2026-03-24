#include "PmergeMe.hpp"

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

// ---------- Ford-Johnson List ----------

static std::list< Pair > makePairsList( std::list< int > &containerList, bool &hasLeftOver, int &leftover ) {

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

static std::list< int > recursiveSortAList( std::list< Pair > &pairs ) {
	std::list< int > listA;
	std::list< Pair >::iterator it = pairs.begin();
	std::list< Pair >::iterator end = pairs.end();

	for ( ; it != end; ++it ) {
		const Pair &uniquePair = *it;
		listA.push_back( uniquePair.a );
	}
	listA = fordJohnsonList( listA );
	return std::list< int >( listA.begin(), listA.end() );
}

static std::list< int > insertBsList( std::list<int> mainChain, const std::list< Pair > &pairs ) {

	int n, start, end, bj;
	std::list<int> tks;

	n = pairs.size();
	tks = fordJohnsonSeq< std::list<int> >( n );

	if ( tks.size() < 2 )
		return mainChain;

	std::list<int>::const_iterator prev = tks.begin();
	std::list<int>::const_iterator curr = ++tks.begin();

	for ( ; curr != tks.end(); ++curr, ++prev ) {
		start = *prev + 1;
		end = *curr;

		std::list< Pair >::const_iterator it = pairs.begin();
		std::advance( it, end - 1 );

		for ( int j = end; j >= start; --j, --it ) {
			bj = it->b;
			std::list<int>::iterator pos = std::lower_bound( mainChain.begin(), mainChain.end(), bj );
			mainChain.insert( pos, bj );
		}
	}

	if ( !tks.empty() ) {
		std::list<int>::iterator last_tks = tks.end();
		--last_tks;
		if ( *last_tks < n ) {
			std::list< Pair >::const_iterator it = pairs.end();
			--it;
			for ( int j = n; j > *last_tks; --j ) {
				--it;
				bj = it->b;

				std::list<int>::iterator pos = std::lower_bound( mainChain.begin(), mainChain.end(), bj );
				mainChain.insert( pos, bj );
			}
		}
	}

	return mainChain;
};

std::list< int > fordJohnsonList( std::list< int > containerList ) {

	bool hasLeftOver;
	int leftover;
	std::list< Pair > pairs;

	if ( containerList.size() <= 1 )
		return containerList;

	hasLeftOver = false;
	leftover = 0;
	pairs = makePairsList( containerList, hasLeftOver, leftover );

	// Step 2 : recursively sort A
	std::list< int > sortedA = recursiveSortAList( pairs );

	// Step 3 : build main chain = {b1} U {sorted a's}
	std::list< int > mainChain;
	mainChain.push_back( pairs.front().b ); // first B
	mainChain.insert( mainChain.end(), sortedA.begin(), sortedA.end() );


	// Step 4: insert b's
	mainChain = insertBsList(mainChain, pairs);

	// Step 5: insert leftover if odd
	if ( hasLeftOver ) {
		std::list<int>::iterator pos = std::lower_bound( mainChain.begin(), mainChain.end(), leftover );

		mainChain.insert( pos, leftover );
	}

	return mainChain;
}

// ---------- Ford-Johnson Deque ----------

static std::deque< Pair > makePairsDeque( std::deque< int > &containerList, bool &hasLeftOver, int &leftover ) {

	int first, second;
	std::deque< Pair > pairs;
	Pair uniquePair;

	std::deque< int >::iterator it = containerList.begin();
	std::deque< int >::iterator end = containerList.end();

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

static std::deque< int > recursiveSortADeque( std::deque< Pair > &pairs ) {
	std::deque< int > listA;
	std::deque< Pair >::iterator it = pairs.begin();
	std::deque< Pair >::iterator end = pairs.end();

	for ( ; it != end; ++it ) {
		const Pair &uniquePair = *it;
		listA.push_back( uniquePair.a );
	}
	listA = fordJohnsonDeque( listA );
	return std::deque< int >( listA.begin(), listA.end() );
}

static std::deque< int > insertBsDeque( std::deque<int> mainChain, const std::deque< Pair > &pairs ) {

	int n, start, end, bj;
	std::deque<int> tks;

	n = pairs.size();
	tks = fordJohnsonSeq< std::deque<int> >( n );

	if ( tks.size() < 2 )
		return mainChain;

	std::deque<int>::const_iterator prev = tks.begin();
	std::deque<int>::const_iterator curr = ++tks.begin();

	for ( ; curr != tks.end(); ++curr, ++prev ) {
		start = *prev + 1;
		end = *curr;

		std::deque< Pair >::const_iterator it = pairs.begin();
		std::advance( it, end - 1 );

		for ( int j = end; j >= start; --j, --it ) {
			bj = it->b;
			std::deque<int>::iterator pos = std::lower_bound( mainChain.begin(), mainChain.end(), bj );
			mainChain.insert( pos, bj );
		}
	}

	if ( !tks.empty() ) {
		std::deque<int>::iterator last_tks = tks.end();
		--last_tks;
		if ( *last_tks < n ) {
			std::deque< Pair >::const_iterator it = pairs.end();
			--it;
			for ( int j = n; j > *last_tks; --j ) {
				--it;
				bj = it->b;

				std::deque<int>::iterator pos = std::lower_bound( mainChain.begin(), mainChain.end(), bj );
				mainChain.insert( pos, bj );
			}
		}
	}

	return mainChain;
};

std::deque< int > fordJohnsonDeque( std::deque< int > containerList ) {

	bool hasLeftOver;
	int leftover;
	std::deque< Pair > pairs;

	if ( containerList.size() <= 1 )
		return containerList;

	hasLeftOver = false;
	leftover = 0;
	pairs = makePairsDeque( containerList, hasLeftOver, leftover );

	// Step 2 : recursively sort A
	std::deque< int > sortedA = recursiveSortADeque( pairs );

	// Step 3 : build main chain = {b1} U {sorted a's}
	std::deque< int > mainChain;
	mainChain.push_back( pairs.front().b ); // first B
	mainChain.insert( mainChain.end(), sortedA.begin(), sortedA.end() );


	// Step 4: insert b's
	mainChain = insertBsDeque(mainChain, pairs);

	// Step 5: insert leftover if odd
	if ( hasLeftOver ) {
		std::deque<int>::iterator pos = std::lower_bound( mainChain.begin(), mainChain.end(), leftover );

		mainChain.insert( pos, leftover );
	}

	return mainChain;
}