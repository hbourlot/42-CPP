#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
	
	ClapTrap::_name = "Default_clap_name";
	std::cout << "DiamondTrap constructor!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energy = ScavTrap::_energy;
	this->_attackDmg = FragTrap::_attackDmg;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energy = ScavTrap::_energy;
	this->_attackDmg = FragTrap::_attackDmg;
}

DiamondTrap::~DiamondTrap() {
	
	std::cout << "Diamond destructor!" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	
	if (this != &other) {
		ClapTrap::operator=(other);
		ScavTrap::operator=(other);
		FragTrap::operator=(other);
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energy = other._energy;
		_attackDmg = other._attackDmg;
	}

	std::cout << "Copy assignment destructor!" << std::endl;

	return *this;
}

void	DiamondTrap::whoAmI() {

	std::cout << "DiamondTrap name: " << this->_name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
}

void	DiamondTrap::attack( std::string name ) {
	ScavTrap::attack(name);
}