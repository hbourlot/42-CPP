#include "WrongCat.hpp"

// Constructor
WrongCat::WrongCat( void )
:	WrongAnimal("WrongCat") {
	std::cout << "WrongCat constructor called!" << std::endl;
}

// Destructor
WrongCat::~WrongCat( void ) {
	std::cout << "WrongCat destructor called!" << std::endl;
}

// Methods
void	WrongCat::makeSound( void ) const {
	std::cout << "Wrong cat noiiisyyy ❕" << std::endl;
}