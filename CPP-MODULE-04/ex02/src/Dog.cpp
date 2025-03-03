#include "Dog.hpp"
#include "Brain.hpp"

// Constructor
Dog::Dog( void )
	: Animal("Dog") {
	std::cout << "Dog constructor called!" << std::endl;
	this->_brain = new Brain();
}

Dog::Dog(Dog& other)
	: Animal(other) {
	std::cout << "Copy Dog constructor called!" << std::endl;
	this->_brain = new Brain(*other._brain);
}

// Destructor
Dog::~Dog( void ) {
	std::cout << "Dog destructor called!" << std::endl;
	delete this->_brain;
}

// Operators
Dog&	Dog::operator=(const Dog& other) {
	std::cout << "Dog alignment operator called!" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	return *this;
}

// Methods
void	Dog::makeSound( void ) const {
	std::cout << "Bark Bark 🐕" << std::endl;
}


// Setter
void	Dog::setIdeas(size_t i, std::string idea) const {
	if (i <= 100) {
		for (size_t j = 0; j < i; j++) {
			this->_brain->setIdea(j, idea);
		}
	} else {
		std::cout << "You can set Max 100 ideas! 🚨" << std::endl; 
	}
}

// Getter
void	Dog::getIdeas( void ) const {
	for (int i = 0; i < 10; i++) {
		std::cout << "🧠 Idea: " << this->_brain->getIdea (i) << std::endl;
	}
}

void	Dog::getInfo( void ) const {
	std::cout << "Addr of _brain: " << this->_brain << std::endl;
	std::cout << "Value of _brain[0]: " << this->_brain->getIdea(0) << std::endl;
}
