#include "DiamondTrap.hpp"

// Constructor
DiamondTrap::DiamondTrap( void ) {
	ClapTrap::_name = "Default";
	std::cout << "DiamondTrap default constructor called!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
	: ScavTrap(name), FragTrap(name), _name(name) {
	std::cout << "DiamondTrap constructor called!" << std::endl;
	
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energy = ScavTrap::_energy;
	this->_attackDmg = FragTrap::_attackDmg;
	ClapTrap::_name = name = "_clap_name";
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other), ScavTrap(other), FragTrap(other) {
	*this = other;
	std::cout << "DiamondTrap copy constructor called!" << std::endl;
}

// Destructor
DiamondTrap::~DiamondTrap( void ) {
	std::cout << "DiamondTrap destructor called!" << std::endl;
}


// Methods
void	DiamondTrap::whoAmI( void ) {
	std::cout << "DiamondTrap name: " << this->_name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
}

// Getter
std::string DiamondTrap::getName( void ) {
	return this->_name;
}

void	DiamondTrap::attack( std::string name ) {
	ScavTrap::attack(name);
}