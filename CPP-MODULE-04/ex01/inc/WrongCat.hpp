#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "Animal.hpp"
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
	
	private:


	public:

	// Constructor
		WrongCat( void );

	// Destructor
		~WrongCat( void );
	
	// Methods
		void	makeSound( void ) const;
};

#endif