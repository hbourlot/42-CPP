#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource()
	: IMateriaSource() {

	for (int i = 0; i < 4; i++) {
		this->_materia[i] = NULL;
	}
}

void	MateriaSource::learnMateria( AMateria * ptr) {
	if (ptr == NULL)
		return ;
	for (int i = 0; i < 4; i++) {
		if (!this->_materia[i]) {
			this->_materia[i] = ptr;
			return ;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const& type) {
	if (type == "ice")
		return new Ice();
	else if (type == "cure")
		return new Cure();
	return NULL;
}
