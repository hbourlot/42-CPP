#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>
#include <string>

class  Ice: public AMateria {

	public:
		Ice() : AMateria("ice") {};
		void	use(ICharacter& target);
		AMateria*	clone() const;
		virtual ~Ice() {};
};