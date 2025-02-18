#include "ClapTrap.hpp"

void ClapTrap::attack(const std::string& target) {
	if (this->_energy <= 0 || this->_hitPoints <= 0)
		return;
		// pass the target and hits it
		this->_energy -= 1;
		std::cout << "ClapTrap attacks ⚔️" << target;
		std::cout << ", causing " << this->_attackDmg;
		std::cout << " points of damage!" << std::endl;
}
	
void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_energy <= 0)
		return;
	
}
	
void ClapTrap::beRepaired(unsigned int amount) {
	
	if (this->_energy <= 0)
		return;
	this->_hitPoints += amount;
	this->_energy -= 1;
}

