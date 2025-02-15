#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
	
	private:
		std::string _name;
		Weapon* 	_weapon;
	
	public:
		HumanB(std::string name)
		:	_name(name), _weapon(NULL) {}
		~HumanB() {}
		void attack(void);
		void setWeapon(Weapon& weapon);
		void setType(std::string type);
};


#endif