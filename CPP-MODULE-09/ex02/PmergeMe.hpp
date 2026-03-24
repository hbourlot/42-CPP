#pragma once

#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <exception>
#include <iomanip> // for std::fixed and std::setprecision
#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

#define RED "\033[31m"
#define RESET "\033[0m"

#ifndef BONUS
#define BONUS false
#endif

struct Pair {
		int a; // larger
		int b; // smaller
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
				container.push_back( atoi( valueStr.c_str() ) );
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
/// @param func Function to apply to the container
template < typename Container, typename Function >
void processContainerDisplay( Container container, std::string classType, Function func ) {

	long elapsed_us;
	double display_us;

	std::clock_t start = std::clock();
	Container sorted = func( container );
	std::clock_t end = std::clock();

	elapsed_us = ( end - start ) * 1000000 / CLOCKS_PER_SEC;
	display_us = double( elapsed_us ) / 1000.0;

	std::cout << "Time to process a range of " << container.size() << " elements with " << classType << " : "
			  << std::fixed << std::setprecision( 5 ) << display_us << " us\n";
};

std::list< int > fordJohnsonList( std::list< int > containerList );
std::deque< int > fordJohnsonDeque( std::deque< int > containerList );
