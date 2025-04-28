#include "Cure.hpp"

Cure::Cure(): AMateria("cure") {

	std::cout << "Cure 🌳 (default constructor)" << std::endl;
}

Cure::Cure(const Cure& other): AMateria("cure") {
	
	std::cout << "Cure 🌳 (copy constructor)" << std::endl;
}

Cure&	Cure::operator=(const Cure& other) {
	
	if (this != &other) {
		this->_type = other.getType();
	}

	std::cout << "Cure 🌳 (assignment operator=)" << std::endl;
	return *this;
}

Cure::~Cure() {
	
	std::cout << "Cure 🌳 (destructor)" << std::endl;
}

AMateria*	Cure::clone() const {

	return new Cure;
}

void		Cure::use(ICharacter& target) {

	std::cout << "* heals " << target.getName();
	std::cout << "'s wounds *" << std::endl;
}
