#pragma once

#include "AMateria.hpp"
#include <iostream>

class AMateria;

class ICharacter
{
	protected:

		ICharacter();
		ICharacter(const ICharacter& other);
		ICharacter&	operator=(const ICharacter& other);

	public:

		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};