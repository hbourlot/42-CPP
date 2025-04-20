#include "FragTrap.hpp"

FragTrap::FragTrap()
	: ClapTrap() {

	ClapTrap::_hitPoints = 100;
	ClapTrap::_energy = 100;
	ClapTrap::_attackDmg = 30;

	std::cout << "FragTrap constructor!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
	: ClapTrap(other) {

	ClapTrap::_hitPoints = 100;
	ClapTrap::_energy = 100;
	ClapTrap::_attackDmg = 30;

	std::cout << "FragTrap copy constructor!" << std::endl;
}

FragTrap::FragTrap(std::string name)
	: ClapTrap(name) {

	ClapTrap::_hitPoints = 100;
	ClapTrap::_energy = 100;
	ClapTrap::_attackDmg = 30;

	std::cout << "FragTrap constructor!" << std::endl;
}

FragTrap::~FragTrap() {

	std::cout << "FragTrap destructor!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	
	if (this != &other) {
		ClapTrap::operator=(other);
	}

	std::cout << "FragTrap assignment operator!" << std::endl;
	return *this;
}

void	FragTrap::highFivesGuys( void ) {

	std::cout << "ScavTrap now is Gate keeper mode. 🚪" << std::endl;
}