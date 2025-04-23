#pragma once
#include "Animal.hpp"

class Cat: public Animal {

    private:
        //

    public:

        Cat();
        Cat(std::string type);
        Cat(const Cat& other);
        ~Cat();
        Cat& operator=(const Cat& other);

        void    makeSound() const;

};