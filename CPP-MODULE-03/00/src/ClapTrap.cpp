#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: _name("Default"), _hitPoints(10),
	 _energy(10), _attackDmg(0)
{
	std::cout << "ClapTrap default constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hitPoints(10),
	 _energy(10), _attackDmg(0)
{
	std::cout << "ClapTrap default constructor!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
	: _name(other._name), _hitPoints(other._hitPoints),
	 _energy(other._energy), _attackDmg(other._attackDmg)
{
	std::cout << "ClapTrap copy constructor!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {

	if (this != &other) {
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energy = other._energy;
		this->_attackDmg = other._attackDmg;
	}
	std::cout << "ClapTrap Copy Assignment Operator=" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap Destructor'" << this->_name << "'!\n";
}


// Attacking and repairing cost 1 energy point each;
void	ClapTrap::attack(const std::string& target) {

	if (this->_energy <= 0) {
		std::cout << this->_name << " has no energy to attack" << std::endl;
		return ;
	}
	this->_energy -= 1;
	std::cout << "ClapTrap " << this->_name << " attacks ";
	std::cout << target << ", causing " << this->_attackDmg;
	std::cout << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	
	if ((this->_hitPoints - (int)amount) < 0) {
		std::cout << "ClapTrap " << this->_name << " died!" << std::endl;
	} else {
		this->_hitPoints -= 1;
		std::cout << "ClapTrap " << this->_name << " took" << amount;
		std::cout << " damage" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	
	if (this->_energy <= 0) {
		std::cout << "ClapTrap " << this->_name << "has no energy to heal" << std::endl;
		return ;
	} else {
		std::cout << "ClapTrap " << this->_name << "healed" << amount << " points" << std::endl;
		this->_hitPoints += amount;
		this->_energy -= 1;
	}
}


// GETTERS
std::string ClapTrap::getName() const {

	return this->_name;
}

int ClapTrap::getHitPoints() const {

	return this->_hitPoints;
}

int ClapTrap::getEnergy() const {

	return this->_energy;
}

int ClapTrap::getAttackDmg() const {

	return this->_attackDmg;
}