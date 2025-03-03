#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
	
	private:
		//

	protected:
		std::string type;

	public:

		Animal( void );
		Animal( std::string type );
		Animal( const Animal& other);
		virtual 		~Animal( void );
		std::string		getType( void ) const ;
		virtual void	makeSound( void ) const;
		Animal& 		operator=(const Animal& other);
};

#endif