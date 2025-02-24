#include "ScavTrap.hpp"

// Constructor
ScavTrap::ScavTrap( void )
	: ClapTrap() {
	std::cout << "ScavTrap default constructor called!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) 
	: ClapTrap(name) {
	std::cout << "ScavTrap constructor called!" << std::endl;
	ClapTrap::_hitPoints = 100;
	ClapTrap::_energy = 50;
	ClapTrap::_attackDmg = 20;
}

// Destructor
ScavTrap::~ScavTrap( void ) {
	std::cout << "ScavTrap destructor called!" << std::endl;
}

// Methods
void	ScavTrap::guardGate( void ) {
	std::cout << "ScavTrap now is Gate keeper mode. 🚪" << std::endl;
}

void	ScavTrap::attack( std::string name ) {
	if (this->_energy == 0) {
		std::cout << this->_name << " has no energy to attack" << std::endl;
		return ;
	} 
	this->_energy -= 1;
	std::cout << "ScavTrap " << this->_name << " attacks " << name;
	std::cout << ", causing " << this->_attackDmg;
	std::cout << " points of damage!" << std::endl;
}