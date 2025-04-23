#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"

class cure: AMateria {

    private:
    
    public:

    AMateria*   clone();
    void        use(ICharacter& target);
}