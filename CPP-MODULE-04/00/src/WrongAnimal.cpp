#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	
	this->setType("Default");
	std::cout  << "WrongAnimal '" << this->getType() << "' (default constructor)." << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) {
	
	this->setType(type);
	std::cout  << "WrongAnimal '" << this->getType() << "' (default constructor)." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	
	this->setType(other.getType());
	std::cout  << "WrongAnimal '" << this->getType() << "' (copy constructor)." << std::endl;
}

WrongAnimal::~WrongAnimal( void ) {

	std::cout  << "WrongAnimal '" << this->getType() << "' (destructor)." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	
	if (this != &other) {
		this->setType(other.getType());
	}
	std::cout  << "WrongAnimal '" << this->getType() << "' (assignment operator=)." << std::endl;
	return *this;
}

void	WrongAnimal::setType(const std::string& type) {
	this->_type = type;
}

std::string WrongAnimal::getType( void ) const {
	return this->_type;
}

void	WrongAnimal::makeSound( void ) const {
	std::cout << "WrongAnimal sound" << std::endl;
}