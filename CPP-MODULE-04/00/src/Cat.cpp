#include "Cat.hpp"

Cat::Cat()
    : Animal("Cat 🐈") {

    std::cout << this->getType() << " (default constructor)." << std::endl;
}

Cat::Cat(std::string type)
    : Animal("Cat 🐈") {
    
    std::cout << this->getType() << " (default constructor)." << std::endl;
}

Cat&	Cat::operator=(const Cat& other) {

    if (this != &other) {
        Animal::operator=(other);
	}
    std::cout << "Cat (assignment operator)." <<std::endl;
	return *this;
}

Cat::Cat(const Cat& other)
    : Animal(other.getType()) {

    std::cout << this->getType() << " (copy constructor)." << std::endl;
}

Cat::~Cat() {

    std::cout << this->getType() << " (destructor)." << std::endl;
}

void Cat::makeSound() const {

    std::cout << "cat sound" << std::endl;
}

