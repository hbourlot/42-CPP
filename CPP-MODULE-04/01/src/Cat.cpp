#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat()
    : Animal("Cat 🐈"), _brain(new Brain) {

    std::cout << this->getType() << " (default constructor)." << std::endl;
}

Cat::Cat(std::string type)
    : Animal("Cat 🐈"), _brain(new Brain) {
    
    std::cout << this->getType() << " (default constructor)." << std::endl;
}

Cat::Cat(const Cat& other)
    : Animal(other.getType()), _brain(new Brain) {

    *_brain = *(other.getBrain());

    std::cout << this->getType() << " (copy constructor)." << std::endl;
}

Cat::~Cat() {
    delete this->getBrain();
    std::cout << this->getType() << " (destructor)." << std::endl;
}

void Cat::makeSound() const {

    std::cout << "cat sound" << std::endl;
}

Brain*   Cat::getBrain() const {
    return this->_brain;
}

