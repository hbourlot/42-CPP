#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : virtual public ClapTrap {
	private:
		//
	public:

		// Constructor
		FragTrap( void );
		FragTrap(std::string name);
		// FragTrap(const FragTrap& other);
		// Destructor
		~FragTrap( void );

		// Methods
		void	highFivesGuys( void );
};

#endif