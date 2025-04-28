#include "Brain.hpp"

Brain::Brain() {

    std::cout << "Brain (constructor)" << std::endl;
}

Brain::Brain(std::string idea) {
    Brain::setIdeas(idea);
    std::cout << "Brain (constructor)" << std::endl;
}

Brain::Brain(const Brain& other) {
    
    for (int idx = 0; idx < 100; idx++) {
        Brain::setIdea(idx, other._ideas[idx]);
    }
    std::cout << "Brain (copy constructor)" << std::endl;
}

Brain&  Brain::operator=(const Brain& other) {
    
    if (this != &other) {
        for (int idx = 0; idx < 100; idx++) {
            Brain::setIdea(idx, other._ideas[idx]);
        }
    }
    std::cout << "Brain (assignment constructor)" << std::endl;
    
    return *this;
}

Brain::~Brain() {
    
    std::cout << "Brain (destructor)" << std::endl;
}

std::string* Brain::getIdeas() {
    return this->_ideas;
}

void    Brain::setIdea(int idx, std::string idea) {
    
    if (idx < 0 || idx > 99) {
        std::cout << "Wrong idx" << std::endl;
        return ;
    }
    this->_ideas[idx] = idea;
}

void    Brain::setIdeas(std::string idea) {

    for (int i = 0; i < 100; i++) {
        Brain::setIdea(i, idea);
    }
}

std::string Brain::getIdea(int idx) const {

    if (idx < 0 || idx > 99) {
        return "Wrong idx";
    }
    return this->_ideas[idx];
}
