#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap()
	: ClapTrap() {

	std::cout << "ScavTrap default constructor!" << std::endl;
	ClapTrap::_hitPoints = 100;
	ClapTrap::_energy = 50;
	ClapTrap::_attackDmg = 20;

}

ScavTrap::ScavTrap(const ScavTrap& other)
	: ClapTrap(other) {
	
	std::cout << "ScavTrap copy constructor!" << std::endl;
	ClapTrap::_hitPoints = 100;
	ClapTrap::_energy = 50;
	ClapTrap::_attackDmg = 20;
}

ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name) {

	std::cout << "ScavTrap constructor!" << std::endl;
	ClapTrap::_hitPoints = 100;
	ClapTrap::_energy = 50;
	ClapTrap::_attackDmg = 20;

}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor '" << this->_name << "'!\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {

	if (this != &other) {
		ClapTrap::operator=(other);
	}
	std::cout << "ScavTrap assignment operator!" << std::endl;
	return *this;
}

void	ScavTrap::guardGate() {

	std::cout << "ScavTrap now is Gate keeper mode. 🚪" << std::endl;
}