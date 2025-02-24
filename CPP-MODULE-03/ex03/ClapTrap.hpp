#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {

	protected:
		std::string _name;
		int 		_hitPoints; // Health representation
		int			_energy;
		int			_attackDmg;

	public:

	// Constructor
	ClapTrap( void );
	ClapTrap(std::string name);

	// Destructor
	~ClapTrap();

	// Methods
	void 	attack( const std::string& target );
	void	takeDamage( unsigned int amount );
	void	beRepaired( unsigned int amount );

	// Getter
	std::string getName( void );

	// Overload operators
	ClapTrap&	operator=(const ClapTrap& other);

};

#endif