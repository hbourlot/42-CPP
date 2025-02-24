#include "ScavTrap.hpp"

// Constructor

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