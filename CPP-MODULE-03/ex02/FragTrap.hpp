#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap {
	private:

	public:

		// Constructor

		FragTrap(std::string name);
		
		// Destructor

		~FragTrap( void );

		// Methods

		void	highFivesGuys( void );
};

#endif