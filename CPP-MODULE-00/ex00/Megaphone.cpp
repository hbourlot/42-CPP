#include <iostream>

int main(int argc, char *argv[]) {

	int j, i;

	i  = 0;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDACK NOISE *";
	if (argc > 1) {
		while (argv[++i]) {

			j = -1;
			while (argv[i][++j])
				std::cout << (char)std::toupper(argv[i][j]);
		}
	}
	std::cout << "\n";
	return 0;
}