#pragma once

#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

#ifndef nullptr
# define nullptr NULL
#endif

class MateriaSource: public IMateriaSource {

	private:

		AMateria*		_slots[4];
		bool			isInSlots(AMateria* materia);

	public:

		MateriaSource();
		MateriaSource(const MateriaSource& other);
		MateriaSource&	 operator=(const MateriaSource& other);
		~MateriaSource();
		void			learnMateria(AMateria *materia);
		AMateria*		createMateria(std::string const& type);
};