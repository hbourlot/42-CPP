#pragma once

#include <iostream>
#include "AMateria.hpp"

class Cure: public AMateria {

	private:
		//

	public:
		
		// Canonical
		Cure();
		Cure(const Cure& other);
		Cure& operator=(const Cure& other);
		~Cure();

		AMateria*	clone() const;
		void		use(ICharacter& target);
};
