#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal {

	private:

	public:
	
	// Constructor
		Dog( void );
	
	// Destructor
		~Dog( void );

	// Methods
		void makeSound( void ) const; // Polymorphism
		
};

#endif