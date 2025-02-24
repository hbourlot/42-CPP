#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	
	private:

	public:

	// Constructor
	ScavTrap(std::string name);

	// Destructor
	~ScavTrap( void );

	// Methods
	void	guardGate( void );
};

#endif
