#include "HumanA.hpp"

void HumanA::attack() {
	
	std::cout << this->_name << " attacks with their ";
	std::cout << this->_weapon.getType() << std::endl;
}