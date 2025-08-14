#include "../inc/easyfind.hpp"

int main() {

    std::vector<int> container1;

    // Fill container
    for (int i = 1; i <= 5; ++i)
        container1.push_back(i);

    // Value to find
    int value = 2;

    std::cout << "Searching for value: " << value << " in container.\n";

    try {
        std::vector<int>::iterator it = easyfind(container1, value);
        std::cout << "Value found: " << *it << " at position " << std::distance(container1.begin(), it) << '\n';
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    // Trying with a value not in the container
    value = 10;
    std::cout << "\nSearching for value: " << value << " in container.\n";

    try {
        std::vector<int>::iterator it = easyfind(container1, value);
        std::cout << "Value found: " << *it << " at position " << std::distance(container1.begin(), it) << '\n';
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    return 0;
}
