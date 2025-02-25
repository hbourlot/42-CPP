#include "WrongAnimal.hpp"

// Constructor
WrongAnimal::WrongAnimal( void )
	: type("'Default'") {
		std::cout << "WrongAnimal default constructor called!" << std::endl;
}

WrongAnimal::WrongAnimal( std::string type )
	: type(type) {
		std::cout << "WrongAnimal constructor called!" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& other ) {
	this->type = other.type;
	std::cout << "WrongAnimal copy constructor called!" << std::endl;
}

// Destructor
WrongAnimal::~WrongAnimal( void ) {
	std::cout << "WrongAnimal destructor called!" << std::endl;
}

// Methods
void	WrongAnimal::makeSound( void ) const {
	std::cout << WrongAnimal::getType() << " make a ⁉️ WRONG ⁉️ no sound 🚨" << std::endl;
}

// Getter
std::string WrongAnimal::getType( void ) const {
	return this->type;
}

// Operator

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	if (this != &other)
		this->type = other.type;
		
	std::cout << "WrongAnimal assignment operator called!" << std::endl;
	return *this;
}