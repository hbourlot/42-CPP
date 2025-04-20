#pragma once

#include <iostream>

class Animal {

    protected:
        
        std::string type;


    public:

        Animal();
        Animal(std::string t);
        Animal(const Animal& other);
        ~Animal();

};