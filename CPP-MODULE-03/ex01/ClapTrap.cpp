#include "ClapTrap.hpp"

void ClapTrap::attack(const std::string& target) {
	if (this->_energy == 0) {
		std::cout << this->_name << " has no energy to attack" << std::endl;
		return ;
	} 
	this->_energy -= 1;
	std::cout << "ClapTrap" << this->_name << " attacks " << target;
	std::cout << ", causing " << this->_attackDmg;
	std::cout << " points of damage!" << std::endl;
}
	
void ClapTrap::takeDamage(unsigned int amount) {
	if ((this->_hitPoints - (int)amount) < 0) {
		std::cout << "ClapTrap " << this->_name << " died!" << std::endl;
	} else {
		this->_hitPoints -= amount;
		printf("%d\n\n",  this->_hitPoints);
		std::cout << "ClapTrap " << this->_name << " took " << amount;
		std::cout << " damage" << std::endl;
	}
}
	
void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energy <= 0) {
		std::cout << "ClapTrap " << this->_name << "has no energy to heal" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->_name << "healed " << amount << " points" << std::endl;
	this->_hitPoints += amount;
	this->_energy -= 1;
}

