#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
	
	private:
		Weapon& 		_weapon;
		std::string 	_name;
	
	public:
		HumanA(std::string name, Weapon& weapon)
			: _weapon(weapon), _name(name) {}
		~HumanA() {}
		void attack(void);

};

#endif