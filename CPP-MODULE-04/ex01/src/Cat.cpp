#include "Cat.hpp"
#include "Brain.hpp"

// Constructor
Cat::Cat( void )
	: Animal("Cat 🐈") {
	std::cout << "Cat constructor called!" << std::endl;
	this->_brain = new Brain();
}

Cat::Cat(const Cat& other)
	: Animal(other) {
	std::cout << "Cat copy constructor called!" << std::endl;
	this->_brain = new Brain(*other._brain);
}

// Destructor
Cat::~Cat( void ) {
	std::cout << "Cat destructor called!" << std::endl;
	delete this->_brain;
}

// Methods
void	Cat::makeSound( void ) const {
	std::cout << "Miau Miau 🐈" << std::endl;
}

// Operators
Cat&	Cat::operator=(const Cat& other) {
	std::cout << "Cat assignment operator called!" <<std::endl;
	if (this != &other) {
		Animal::operator=(other);
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	return *this;
}
// Setter
void	Cat::setIdeas( size_t i, std::string idea) const {
	if (i <= 100) {
		for (size_t j = 0; j < i; j++) {
			this->_brain->setIdea(j, idea);
		}
	} else {
		std::cout << "You can set Max 100 ideas! 🚨" << std::endl; 
	}
}

// Getter
void	Cat::getIdeas( void ) const {
	for (int i = 0; i < 10; i++) {
		std::cout << "🧠 Idea: " << this->_brain->getIdea (i) << std::endl;
	}
}

void	Cat::getInfo( void ) const {
	std::cout << "Addr of _brain: " << this->_brain << std::endl;
	std::cout << "Value of _brain[0]: " << this->_brain->getIdea(0) << std::endl;
}