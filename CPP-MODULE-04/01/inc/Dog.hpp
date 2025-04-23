#pragma once

#include "Animal.hpp"

class Dog: public Animal {

	private:
		//	

	public:

		Dog();
		Dog(std::string type);
		Dog(const Dog& other);
		~Dog();
		Dog& operator=(const Dog& other);

		void makeSound() const;

};
