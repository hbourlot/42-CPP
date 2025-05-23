
#include "Animal.hpp"


Animal::Animal()
	: _type("Default") {
	
	std::cout  << "Animal '" << this->getType() << "' (default constructor)" << std::endl;
}

Animal::Animal(std::string type)
	: _type(type) {
	
	std::cout  << "Animal '" << this->getType() << "' (default constructor)" << std::endl;
}

Animal::Animal(const Animal& other)
	: _type(other.getType()) {
	
	std::cout  << "Animal '" << this->getType() << "' (copy constructor)" << std::endl;
}

Animal::~Animal() {
	
	std::cout  << "Animal '" << this->getType() << "' (destructor)" << std::endl;
}

Animal& 	Animal::operator=(const Animal& other) {
	
	if (this != &other) {
		this->setType(other.getType());
	}
	std::cout  << "Animal '" << this->getType() << "' (assignment operator)" << std::endl;
	return *this;
}

void 		Animal::makeSound() const {
	std::cout << this->getType() << " has no sound" << std::endl;
}


std::string Animal::getType() const {
	return this->_type;
}

void		Animal::setType(std::string type) {
	this->_type = type;
}