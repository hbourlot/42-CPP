#include "Dog.hpp"

Dog::Dog() : Animal("Dog 🐕") {

    std::cout << this->_type << " (default constructor)." << std::endl;
	
}

Dog::Dog(std::string type) : Animal(type) {
	
	std::cout << this->_type << " (default constructor)." << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	
	std::cout << this->_type << " (copy constructor)." << std::endl;

}

Dog::~Dog() {

	std::cout << this->_type << " (destructor)." << std::endl;
}

void Dog::makeSound() const {

	std::cout << "bark bark " << std::endl;
}
