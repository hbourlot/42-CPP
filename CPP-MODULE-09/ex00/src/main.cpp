#include "../inc/BitcoinExchange.hpp"
#include <exception>

void execute(int av, char *ac[]) {

	if (av == 2) {
		try {
			BitcoinExchange algorithm(ac[1]);
			algorithm.run();
		} catch (std::exception &e) {
			std::cout << e.what();
		};
	} else {
		std::cerr << "Program must be executed with dataPath.\n";
	};
}

int main(int av, char *ac[]) {

	execute(av, ac);
	return 0;
};