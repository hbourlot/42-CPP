#include "Character.hpp"

Character::Character(std::string name) {
	this->_name = name;
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
}


std::string const& Character::getName() const {
	return this->_name;
}

void	Character::equip(AMateria *m) {
	if (!m)
		return;
	for (int i = 0; i < 4; i++) {
		if (!this->_inventory[i]) {
			this->_inventory[i] = m;
			return ;
		}
	}
}

void	Character::unequip(int idx) {
	if (idx >= 0 && idx <= 3) {
		this->_inventory[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx <= 3) {
		if (this->_inventory[idx]) {
			this->_inventory[idx]->use(target);
		}
	}
}

