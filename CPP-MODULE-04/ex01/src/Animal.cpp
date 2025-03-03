#include "Animal.hpp"


// Constructor
Animal::Animal( void )
	: type("Default") {
	std::cout << "Default animal constructor called!" << std::endl;
}

Animal::Animal( std::string type )
	: type(type) {
		std::cout << "Animal constructor called!" << std::endl;
}

Animal::Animal(const Animal& other) {
	this->type = other.type;
	std::cout << "Animal copy constructor called!" << std::endl;
}

// Destructor
Animal::~Animal( void ) {
	std::cout << "Animal destructor called!" << std::endl;
}

// Getter
std::string Animal::getType( void ) const {
	return this->type;
}

// Methods

void	Animal::makeSound( void ) const {
	std::cout << Animal::getType() <<  " make no sound 🚨" << std::endl;
}

// Operators

Animal& Animal::operator=(const Animal& other) {
	std::cout << "Animal Assignment operator called!" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}