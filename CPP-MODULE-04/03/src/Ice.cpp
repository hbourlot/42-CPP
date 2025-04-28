#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {

	std::cout << "Ice ❄️ (default constructor)" << std::endl;
}

Ice::Ice(const Ice& other): AMateria("ice") {
	
	std::cout << "Ice ❄️ (copy constructor)" << std::endl;
}

Ice&	Ice::operator=(const Ice& other) {
	
	if (this != &other) {
		this->_type = other.getType();
	}

	std::cout << "Ice ❄️ (assignment constructor=)" << std::endl;
	return *this;
}

Ice::~Ice() {
	
	std::cout << "Ice ❄️ (destructor)" << std::endl;
}


AMateria*	Ice::clone() const {

	return new Ice;
}

void	Ice::use(ICharacter& target) {

	std::cout << "* shoots an ice bolt at " << target.getName();
	std::cout << " *" << std::endl;
}