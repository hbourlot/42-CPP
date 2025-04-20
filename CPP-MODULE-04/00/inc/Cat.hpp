#pragma once

#include "Animal.hpp"

class Cat: public Animal {

    private:
        std::string type;

    public:

        Cat();
        Cat(std::string type);
        Cat(const Cat& other);
        ~Cat();
        Cat& operator=(const Cat& other);

};