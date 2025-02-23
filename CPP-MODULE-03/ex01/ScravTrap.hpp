#ifndef SCRAVTRAP_HPP
# define SCRAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	
	private:

	public:
	ScavTrap(std::string name): ClapTrap(name) {
		std::cout << "Constructor of ClapTrap inside the ScavTrap" << std::endl;
	}
};

#endif
