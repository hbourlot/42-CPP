#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
	
	private:
		//

	protected:
		std::string type;

	public:

	// Constructor
		Animal( void );
		Animal( std::string type );
		Animal( const Animal& other);

	// Destructor
		virtual ~Animal( void );

	// getter
		std::string getType( void ) const ;

	// Methods
		virtual void	makeSound( void ) const;

	// Operators
		Animal& operator=(const Animal& other);
};

#endif