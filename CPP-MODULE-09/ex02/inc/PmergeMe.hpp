#pragma once

#include <exception>
#include <iostream>
#include <list>

#define RED "\033[31m"
#define RESET "\033[0m"

struct DijkstraBlock {
	int distance;
	std::string rep;
	int x, y;
	DijkstraBlock *previous;
};

struct MICompareBlock {
	int *v1;
	int *v2;
};

class PmergeMe {

  public:
	PmergeMe();
	PmergeMe(char **av);
	~PmergeMe();
	void readTerminal();
	void run();

  private:
	char **_av;
	std::list<int> _container;

	void parseInput(char **av);
	void convertInputIntoContainer(char **av);
};

//  --- Dijkstra Functions

/// @brief Checks if the given command represents a special block (Start "S" or End "E")
///        that already exists in the container.
/// @param container The list of existing DijkstraBlocks.
/// @param command The block type to check (e.g., "S", "E", ".", "#").
/// @return true if the block already exists (for "S" or "E"), false otherwise.
void addBlock(const std::string &command, std::list<DijkstraBlock> &container);

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
void displayBlocks(std::list<DijkstraBlock> &container);

/// @brief Displays the rules and key representations used in the Dijkstra grid.
///        Shows the meaning of each symbol (S, E, F, N, B) for user reference.
void displayRules();

/// @brief Executes Dijkstra's algorithm on the given container.
///        Updates the distance and previous pointers of each block to compute
///        the shortest path from Start ("S") to End ("E").
/// @param container The container of DijkstraBlocks representing the grid.
void performDijkstra(std::list<DijkstraBlock> &container);

/// @brief Prints the grid of Dijkstra blocks with the shortest path highlighted.
///        Blocks on the shortest path from Start ("S") to End ("E") are printed
///        in red, using the same layout style as displayBlocks.
/// @param container The container of DijkstraBlocks representing the grid.
void printShortestPath(const std::list<DijkstraBlock> &container);

/// @brief Runs the complete Dijkstra pathfinding process:
///        - Reads user input for blocks
///        - Displays rules
///        - Performs Dijkstra’s algorithm
///        - Prints the shortest path result
void runDijkstraAlgorithm();
