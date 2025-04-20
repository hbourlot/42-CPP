#pragma once

# include <iostream>

class ClapTrap {

	protected:

		std::string _name;
		int	_hitPoints;
		int	_energy;
		int	_attackDmg;


	public:

		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		// GETTER
		std::string getName() const;
		int			getHitPoints() const;
		int			getEnergy() const;
		int 		getAttackDmg() const;
		~ClapTrap();

};