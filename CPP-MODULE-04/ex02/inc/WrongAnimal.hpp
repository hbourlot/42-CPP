#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {

	protected:
		//

	private:
		std::string type;

	public:
	
	// Constructor
		WrongAnimal( void );
		WrongAnimal( std::string type );
		WrongAnimal( const WrongAnimal& other );

	// Destructor
		virtual ~WrongAnimal( void );
	
	// Methods
		virtual void	makeSound( void ) const;

	// 	Getter
		std::string getType( void ) const;

	// Operators
		WrongAnimal& operator=(const WrongAnimal& other);

};

#endif