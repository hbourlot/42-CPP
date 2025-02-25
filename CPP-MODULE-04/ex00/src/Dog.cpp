#include "Dog.hpp"


// Constructor
Dog::Dog( void )
	: Animal("Dog") {
		std::cout << "Dog constructor called!" << std::endl;
}

// Destructor
Dog::~Dog( void ) {
	std::cout << "Dog destructor called!" << std::endl;
}

// Methods
void Dog::makeSound( void ) const {
	std::cout << "Bark Bark 🐕" << std::endl;
}