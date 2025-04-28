#include "ICharacter.hpp"

ICharacter::ICharacter() {

	std::cout << "ICharacter (default constructor)" << std::endl;
}

ICharacter::ICharacter(const ICharacter& other) {
	
	*this = other;
	std::cout << "ICharacter (copy constructor)" << std::endl;
}

ICharacter&	ICharacter::operator=(const ICharacter&	other) {
	
	(void)other;
	std::cout << "ICharacter (assignment operator=)" << std::endl;
	return *this;
}
