#include "Cat.hpp"

Cat::Cat()
    : Animal("Cat 🐈"), _brain(new Brain) {

    std::cout << this->getType() << " (default constructor)." << std::endl;
}

Cat::Cat(std::string type)
    : Animal("Cat 🐈"), _brain(new Brain) {
    
    std::cout << this->getType() << " (default constructor)." << std::endl;
}

Cat&	Cat::operator=(const Cat& other) {

    if (this != &other) {
        for (int idx = 0; idx < 100; idx++) {
            this->_brain->setIdea(idx, other._brain->getIdea(idx));
        }
	}
    std::cout << "Cat (assignment operator)." <<std::endl;
	return *this;
}

Cat::Cat(const Cat& other)
    : Animal(other.getType()), _brain(new Brain) {

    for (int idx = 0; idx < 100; idx++) {
        this->_brain->setIdea(idx, other._brain->getIdea(idx));
    }
    std::cout << this->getType() << " (copy constructor)." << std::endl;
}

Cat::~Cat() {

    delete _brain;
    std::cout << this->getType() << " (destructor)." << std::endl;
}

void Cat::makeSound() const {

    std::cout << "cat sound" << std::endl;
}

void    Cat::setIdea(int idx, std::string idea) {

    this->_brain->setIdea(idx, idea);
}

std::string Cat::getIdea(int idx) {
    
    return this->_brain->getIdea(idx);
}