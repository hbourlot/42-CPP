#pragma once

#include <iostream>

class WrongAnimal {

	protected:
	
		std::string _type;


	public:

		WrongAnimal( void );
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal& other);
		virtual ~WrongAnimal( void );

		WrongAnimal& 	operator=(const WrongAnimal& other);

		
		void 			setType(const std::string& type);
		std::string 	getType( void ) const;
		virtual void	makeSound( void ) const;

};