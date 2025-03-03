#include "Cure.hpp"


void	Cure::use(ICharacter& target) {
	std::cout << "* heals " <<  target.getName() << "'s wounds *\n";
}

AMateria*	Cure::clone() const {
	return new Cure();
}