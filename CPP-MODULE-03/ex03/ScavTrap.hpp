#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
	
	private:

	public:

	// Constructor
	ScavTrap( void );
	ScavTrap(std::string name);

	// Destructor
	~ScavTrap( void );

	// Methods
	void	guardGate( void );
	void	attack( std::string name );
};

#endif
