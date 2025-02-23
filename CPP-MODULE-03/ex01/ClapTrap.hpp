#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {

	private:
		std::string _name;
		int 		_hitPoints; // Health representation
		int			_energy;
		int			_attackDmg;

	public:

	// Constructor
	ClapTrap(std::string name) : _name(name), _hitPoints(10), _energy(10), _attackDmg(0) {
		std::cout << "Constructor called!" << std::endl;
	}

	// Destructor
	~ClapTrap() {
		std::cout << "Destructor called!" << std::endl;
	}
	void 	attack( const std::string& target );
	void	takeDamage( unsigned int amount );
	void	beRepaired( unsigned int amount );


};

#endif