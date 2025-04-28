#pragma once

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:

		std::string _type;
		AMateria(std::string const & type);

	public:

		// Canonical
		AMateria();
		AMateria(const AMateria& other); //TODO: [] Maybe protected
		AMateria& operator=(const AMateria& other);
		virtual	~AMateria();

		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};