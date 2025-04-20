#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {

	DiamondTrap monster("Hugo");
	
	// DiamondTrap newMonster(monster);
	// DiamondTrap copy(monster);
	monster.whoAmI();
	monster.attack("Julia");
	// std::cout << "Monster name is: " << monster.getName() << std::endl;
	return 0;
};