#include "FragTrap.hpp"

// Constructor
FragTrap::FragTrap(std::string name)
	: ClapTrap(name) {
	std::cout << "FragTrap constructor called!" << std::endl;
	this->_name = name;
	this->_energy = 100;
	this->_attackDmg = 30;
	this->_hitPoints = 100;
}

FragTrap::FragTrap( void )
	: ClapTrap() {
	std::cout << "FragTrap default constructor called!" << std::endl;
}
// FragTrap::FragTrap(const FragTrap& other)
// 	: ClapTrap(other) {
// 	if (this != &other)
// 		*this = other;
// }
// Destructor

FragTrap::~FragTrap( void ) {
	std::cout << "FragTrap destructor called!" << std::endl;
}

// Methods

void	FragTrap::highFivesGuys( void ) {
	std::cout << "Here is your 🖐️ requested!" << std::endl;
}