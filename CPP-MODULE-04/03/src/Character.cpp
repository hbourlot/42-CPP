#include "Character.hpp"

Character::Character() : _name("Default"), _slots() {
	
	std::cout << "Character " << this->getName() << " (default constructor)" << std::endl;
}

Character::Character(const Character& other) : _name(other.getName()), _slots() {

	for (int idx = 0; idx < 4; ++idx) {
		if (other._slots[idx]) {
			this->_slots[idx] = other._slots[idx]->clone();
		} else {
			this->_slots[idx] = nullptr;
		}
	}
	std::cout << "Character " << this->getName() << " (copy constructor)" << std::endl;
}

Character&	Character::operator=(const Character& other) {
	
	if (this != &other) {
		for (int idx = 0; idx < 4; ++idx) {
			if (this->_slots[idx])
				delete this->_slots[idx];
			if (other._slots[idx])
				this->_slots[idx] = other._slots[idx]->clone();
			else
				this->_slots[idx] = nullptr;
		}
		this->_name = other.getName();
	}
	std::cout << "Character " << this->getName() << " (assignment operator=)" << std::endl;
	return *this;
}

Character::~Character() {
	
	for (int idx = 0; idx < 4; ++idx) {
		if (this->_slots[idx])
		delete this->_slots[idx];
	}
	std::cout << "Character " << this->getName() << " (destructor)" << std::endl;
}

Character::Character(std::string name) : _name(name), _slots() {

	std::cout << "Character " << this->getName() << " (default constructor)" << std::endl;
}

std::string const&	Character::getName() const {
	
	return this->_name;
}

void	Character::equip(AMateria*	m) {

	for (int idx = 0; idx < 4; ++idx) {
		if (this->_slots[idx] == nullptr) {
			this->_slots[idx] = m;
			return;
		}
	}
	std::cout << "Character " << this->getName() << " has a full inventory." << std::endl;
}

void	Character::unequip(int idx) {

	if (idx < 0 || idx > 3) {
		std::cout << "Wrong idx!";
		return;
	}
	if (this->_slots[idx]) {
		std::cout << "Unequipped " << this->_slots[idx]->getType() << "at index " << idx << std::endl;
	} else  {
		std::cout << "Can't unequip materia at index " << idx << std::endl;
	}
}

void	Character::use(int idx, ICharacter& target) {

	if (this->_slots[idx]) {
		this->_slots[idx]->use(target);
	} else {
		std::cout << "There's no materia at slot number: " << idx << std::endl;
	}
}