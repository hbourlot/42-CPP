#include "Cat.hpp"


// Constructor
Cat::Cat( void )
	: Animal("Cat") {
		std::cout << "Cat constructor called!" << std::endl;
}

// Destructor
Cat::~Cat( void ) {
	std::cout << "Cat destructor called!" << std::endl;
}

// Methods
void	Cat::makeSound( void ) const {
	std::cout << "Miau Miau 🐈" << std::endl;
}