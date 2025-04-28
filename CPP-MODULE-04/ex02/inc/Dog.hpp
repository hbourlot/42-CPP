#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal {

	private:
		Brain*	_brain;

	public:

		Dog();
		Dog(std::string type);
		Dog(const Dog& other);
		~Dog();
		Dog& operator=(const Dog& other);

		void 		makeSound() const;
		void	 	setIdea(int idx, std::string idea);
		std::string	getIdea(int idx);

};
