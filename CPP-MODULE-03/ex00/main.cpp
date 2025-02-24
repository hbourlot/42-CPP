#include "ClapTrap.hpp"

int main() {

	ClapTrap clap("zezinho");
	ClapTrap newOne("Hugo");

	newOne = clap;
	newOne.attack("Jheniffer");
	// clap.attack("mario");

	return 0;
}