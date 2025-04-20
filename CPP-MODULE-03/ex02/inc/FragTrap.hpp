#pragma once

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap {

	private:
		//

	public:

		FragTrap();
		FragTrap(const FragTrap& other);
		FragTrap(std::string name);
		~FragTrap();
		
		FragTrap& operator=(const FragTrap& other);

		void	highFivesGuys( void );
};