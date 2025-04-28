#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _slots() {

	std::cout << "MateriaSource (default constructor)" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other) : _slots() {
	
	for (int idx = 0; idx < 4; ++idx) {
		if (other._slots[idx])
		this->_slots[idx] = other._slots[idx]->clone();
		else
		this->_slots[idx] = nullptr;
	}
	std::cout << "MateriaSource (copy constructor)" << std::endl;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other) {
	
	if (this != &other) {
		for (int idx = 0; idx < 4; ++idx) {
			if (this->_slots[idx])
			delete this->_slots[idx];
			if (other._slots[idx])
			this->_slots[idx] = other._slots[idx]->clone();
			else
			this->_slots[idx] = nullptr;
		}
	}
	std::cout << "MateriaSource (assignment operator=)" << std::endl;
	return *this;
}

MateriaSource::~MateriaSource() {
	
	for (int idx = 0; idx < 4; ++idx) {
		if (this->_slots[idx])
		delete this->_slots[idx];
	}
	std::cout << "MateriaSource (destructor)" << std::endl;
}

void	MateriaSource::learnMateria(AMateria *materia) {

	std::string	err1 = "This materia is already on inventory.";
	std::string	err2 = "Invalid materia.";
	std::string	err3 = "There's no space to save new materia.";
	std::string valid = "Materia saved at index: ";

	for (int idx = 0; idx < 4; ++idx) {
		if (materia && this->_slots[idx] == nullptr) {
			if (this->isInSlots(materia) == false) {
				this->_slots[idx] = materia;
				std::cout << valid << idx << "." << std::endl;
				return;
			} else {
				std::cout << err1 << std::endl;
				return;
			}
		}
	}
	if (materia == nullptr)
		std::cout << err2 << std::endl;
	else
		std::cout << err3 << std::endl;
}


AMateria*	MateriaSource::createMateria(std::string const&	type) {

	for (int idx = 0; idx < 4; ++idx) {
		if (this->_slots[idx] && this->_slots[idx]->getType() == type)
			return this->_slots[idx]->clone();
	}
	return nullptr;
}

bool	MateriaSource::isInSlots(AMateria*	materia) {

	for (int idx = 0; idx < 4; ++idx) {
		if (this->_slots[idx])
			if (this->_slots[idx] == materia)
				return true;
	}
	return false;
}

