#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat: public Animal {
	
	private:

	public:
	
	//Constructor
		Cat( void );

	// Destructor
		~Cat( void );

	// Methods
		void makeSound( void ) const; // Polymorphism
};

#endif