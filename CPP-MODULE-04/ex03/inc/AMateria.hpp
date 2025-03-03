#pragma once

#include "ICharacter.hpp"
#include <iostream>
#include <string>

class ICharacter;

class AMateria {
	
	protected:
		std::string _type;
		
	public:
		AMateria(std::string const & type);
		//...

		std::string const & getType() const; // Returns the materia type

		virtual AMateria*	clone() const = 0;
		virtual void 		use(ICharacter& target);
};