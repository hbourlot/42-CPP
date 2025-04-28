#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"

#include <iostream>

class Ice: public AMateria {

	private:
		//		

	public:

		// Canonical
		Ice();
		Ice(const Ice&other);
		Ice& operator=(const Ice& other);
		~Ice();


		AMateria*	clone() const;
		void		use(ICharacter& target);
};
