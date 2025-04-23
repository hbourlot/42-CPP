#include "Cat.hpp"

Cat::Cat()
    : Animal("Cat 🐈") {

    std::cout << this->_type << " (default constructor)." << std::endl;
}

Cat::Cat(std::string type)
    : Animal("Cat 🐈") {
    
    std::cout << this->_type << " (default constructor)." << std::endl;
}

Cat::Cat(const Cat& other)
    : Animal(other._type) {

    std::cout << this->getType() << " (copy constructor)." << std::endl;
}

Cat::~Cat() {

    std::cout << this->getType() << " (destructor)." << std::endl;
}

void Cat::makeSound() const {

    std::cout << "cat sound" << std::endl;
}

