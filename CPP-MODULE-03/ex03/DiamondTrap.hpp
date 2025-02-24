#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {

	private:
		std::string _name; // Will receive the name from FragTrap


	public:

		// Constructor
		DiamondTrap( void );
		DiamondTrap( std::string name );
		DiamondTrap( const DiamondTrap& other );
		// Destructor
		~DiamondTrap( void );

		// Methods
		void 	whoAmI( void );
		void	attack( std::string name );

		// Getter
		std::string getName( void );
};

#endif