#include "Brain.hpp"

//* Constructor
Brain::Brain( void ) {
	std::cout << "Brain constructor called!" << std::endl;
}

Brain::Brain( const Brain& other ) {
	std::cout << "Copy Brain constructor called!" << std::endl;
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = other.ideas[i];
	}
}
//* Destructor
Brain::~Brain( void ) {
	std::cout << "Brain destructor called!" << std::endl;
}

//* Operator
Brain&	Brain::operator=(const Brain& other) {
	std::cout << "Brain assignment operator called!" << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; i++) {
			this->ideas[i] = other.ideas[i];
		}
	}
	return *this;
}

//*	Setter
void Brain::setIdea( size_t i, std::string name) {
	if (i <= 100) {
		// for (int j = 0; j < i; j++) {
			this->ideas[i] = name;
		// }
	} else {
		std::cout << "Wrong value! 🚨" << std::endl;
	}
}

//* Getter
std::string Brain::getIdea( size_t i) const {
	if (i <= 100) {
		return this->ideas[i];
	} else {
		return "Wrong idea idx! 🚨";
	}
}
