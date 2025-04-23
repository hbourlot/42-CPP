
#include "Animal.hpp"


Animal::Animal() {
	
	this->_type = "Default";
	std::cout  << "Animal '" << this->_type << "' (default constructor)" << std::endl;
}

Animal::Animal(std::string type) : _type(type) {
	
	std::cout  << "Animal '" << this->_type << "' (default constructor)" << std::endl;
}

Animal::Animal(const Animal& other) {
	
	this->_type = other._type;
	std::cout  << "Animal '" << this->_type << "' (copy constructor)" << std::endl;
}

Animal::~Animal() {
	
	std::cout  << "Animal '" << this->_type << "' (destructor)" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
	
	if (this != &other) {
		this->_type = other._type;
	}
	std::cout  << "Animal '" << this->_type << "' (assignment operator)" << std::endl;
	return *this;
}

void Animal::makeSound() const {
	std::cout << this->_type << " has no sound" << std::endl;
}


std::string Animal::getType() const {
	return this->_type;
}