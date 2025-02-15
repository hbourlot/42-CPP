#include "HumanB.hpp"

void HumanB::attack(void) {
	std::cout << this->_name << " attacks with their ";
	std::cout << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& weapon) {
	this->_weapon = &weapon;
}

void HumanB::setType(std::string type) {
	this->_weapon->setType(type);
}