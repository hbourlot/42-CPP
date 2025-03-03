#include "Ice.hpp"
#include "Character.hpp"

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName();
	std:: cout << " *\n";
}

AMateria*	Ice::clone() const {
	return new Ice();
}