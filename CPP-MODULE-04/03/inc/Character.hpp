#pragma once

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character {

    private:
        AMateria    _slots[4];
        int         _idx; // If tries to add more than 4 nothing happens
    public:

        Character();
        Character(AMateria materia);
        Character(const AMateria& other);
        Character& operator=(const AMateria& other);
        ~Character();

        std::string const& getName() const;
        void        equip(AMateria* m);
        void        unequip(int idx); // Must Not delete the Materia!
        void        use(int idx, ICharacter& target); // Use the Materia of the 'idx' slot and call AMateria::use()
};


// Handle the Materias your character leaves on the floor as you like.
// Save the addresses before calling unequip(), or anything else, but
// don’t forget that you have to avoid memory leaks.