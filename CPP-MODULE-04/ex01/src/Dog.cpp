#include "Dog.hpp"

Dog::Dog()
	: Animal("Dog 🐕"), _brain(new Brain) {

    std::cout << this->_type << " (default constructor)." << std::endl;
	
}

Dog::Dog(std::string type)
	: Animal(type), _brain(new Brain) {
	
	std::cout << this->_type << " (default constructor)." << std::endl;
}

Dog::Dog(const Dog& other)
	: Animal(other), _brain(new Brain) {
	
	for (int idx = 0; idx < 100; idx++) {
		this->_brain->setIdea(idx, other._brain->getIdea(idx));
	}
	std::cout << this->_type << " (copy constructor)." << std::endl;

}

Dog&	Dog::operator=(const Dog& other) {

	if (this != &other) {
		// Animal::operator=(other);
		for (int idx = 0; idx < 100; idx++) {
			this->_brain->setIdea(idx, other._brain->getIdea(idx));
		}
	}
	std::cout << "Dog (assignment operator)." << std::endl;
	return *this;
}

Dog::~Dog() {

	delete this->_brain;
	std::cout << this->_type << " (destructor)." << std::endl;
}

void Dog::makeSound() const {

	std::cout << "bark bark " << std::endl;
}


void	Dog::setIdea(int idx, std::string idea) {

	this->_brain->setIdea(idx, idea);
}

std::string Dog::getIdea(int idx) {
	return this->_brain->getIdea(idx);
}
