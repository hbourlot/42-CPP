#pragma once

#include <iostream>

class AAnimal {
	
	protected:
		std::string type;

	public:

		AAnimal( void );
		AAnimal( std::string type );
		AAnimal( const AAnimal& other);
		virtual 		~AAnimal( void );
		std::string		getType( void ) const ;
		virtual void	makeSound( void ) const = 0;
		AAnimal& 		operator=(const AAnimal& other);
};
