#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {
	
	private:
		std::string _type;

	public:

		Weapon( std::string weapon )
			: _type(weapon) {}
		~Weapon() {}

		// Getter
		std::string getType(void);

		// Setter
		void setType(std::string type);


};

#endif