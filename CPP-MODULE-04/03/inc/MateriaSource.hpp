#pragma once

#include "AMateria.hpp"

class MateriaSource {

    private:
        AMateria*   _slots[4];
        int         idx;


    public:

        void        learnMateria(AMateria* materia);
        AMateria*   createMateria(std::string const& type);

};