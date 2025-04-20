#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {

	FragTrap one("Hugo");

	FragTrap two;

	two = one;
	one.highFivesGuys();

	return 0;
}