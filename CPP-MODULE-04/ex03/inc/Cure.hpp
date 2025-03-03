#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>
#include <string>

class Cure: public AMateria {

	public:
		Cure() : AMateria("cube") {};
		void	use(ICharacter& target);
		AMateria*	clone() const;
		virtual ~Cure() {};
};