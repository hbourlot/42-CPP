#include "Harl.hpp"

int main(int argc, char *argv[]) {

	if (argc != 2)
		return -1;
	
	Harl filter;
	filter.complain(argv[1]);
	return 0;
}