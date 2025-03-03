#include "AAnimal.hpp"

// Constructor
AAnimal::AAnimal( void )
	: type("Default") {
	std::cout << "Default AAnimal constructor called!" << std::endl;
}

AAnimal::AAnimal( std::string type )
	: type(type) {
		std::cout << "AAnimal constructor called!" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) {
	this->type = other.type;
	std::cout << "AAnimal copy constructor called!" << std::endl;
}

// Destructor
AAnimal::~AAnimal( void ) {
	std::cout << "AAnimal destructor called!" << std::endl;
}

// Getter
std::string AAnimal::getType( void ) const {
	return this->type;
}

// Methods
// void	AAnimal::makeSound( void ) const {
// 	std::cout << AAnimal::getType() <<  " make no sound 🚨" << std::endl;
// }

// Operators
AAnimal& AAnimal::operator=(const AAnimal& other) {
	std::cout << "AAnimal Assignment operator called!" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}