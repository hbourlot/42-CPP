#include "AMateria.hpp"

AMateria::AMateria() : _type("Default") {

	std::cout << "AMateria: ";
	std::cout << AMateria::getType() << " (default constructor)" << std::endl;
}

AMateria::AMateria(const AMateria& other) {

	this->_type = other.getType();
	std::cout << "AMateria: ";
	std::cout << AMateria::getType() << " (copy constructor)" << std::endl;
}

AMateria&	AMateria::operator=(const AMateria& other) {

	if (this != &other) {
		this->_type = other.getType();
	}
	std::cout << "AMateria: ";
	std::cout << AMateria::getType() << " (assignment operator=)" << std::endl;
	return *this;
}

AMateria::~AMateria() {

	std::cout << "AMateria: ";
	std::cout << AMateria::getType() << " (destructor)" << std::endl;
}



AMateria::AMateria(std::string const& type) {

}

std::string const& AMateria::getType() const {

	return this->_type;
}

AMateria*	AMateria::clone() const {

	return NULL;
}


void	AMateria::use(ICharacter& target) {
	
	std::cout << AMateria::getType();
	std::cout << " has no materia type" << std::endl;
}