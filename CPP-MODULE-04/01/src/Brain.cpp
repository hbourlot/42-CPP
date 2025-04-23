#include "Brain.hpp"


Brain::Brain() {

	std::cout << "Brain default constructor" << std::endl;
	Brain::fillIdeas("No idea");
}

Brain::Brain(std::string idea) {
	
	std::cout << "Brain default constructor" << std::endl;
	Brain::fillIdeas(idea);
}

Brain::Brain(const Brain& other) {

	std::cout << "Brain copy constructor" << std::endl;
	// int i = 0;
	// while (i < 100) {
	// 	this->setIdea(i, other.getIdea(i));
	// 	i++;
	// }
	this->setIdeas(other.getIdeas());
}

Brain& Brain::operator=(const Brain& other) {
	if (this != &other) {
		this->setIdeas(other.getIdeas());
	}
	std::cout << "Brain assignment operator=" << std::endl;
	return *this;
}

Brain::~Brain() {
	
	std::cout << "Brain destructor" << std::endl;
}

void	Brain::fillIdeas(std::string idea) {
	int i = 0;

	while (i < 100) {
		this->setIdea(i, idea);
		i++;
	}
}

const std::string* Brain::getIdeas( void ) const {
	return this->_ideas;
}

void	Brain::setIdea(int idx, std::string idea) {
	
		this->_ideas[idx] = idea;
}

void	Brain::setIdeas(const std::string* ideas) {
	
	for (int i = 0; i < 100; i++) {
		this->setIdea(i, ideas[i]);
	}
}