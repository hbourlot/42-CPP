#pragma once

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

	private:
		//

	public:
	
		ScavTrap();
		ScavTrap(const ScavTrap& other);
		ScavTrap(std::string name);
		~ScavTrap();
		
		ScavTrap& operator=(const ScavTrap& other);
		
		void	guardGate();
	

};