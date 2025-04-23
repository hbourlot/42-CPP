#pragma once

#include <iostream>

class Animal {

    protected:
        
        std::string _type;

    public:

        Animal();
        Animal(std::string type);
        Animal(const Animal& other);
        virtual ~Animal();
        Animal & operator=(const Animal& other);

        virtual void        makeSound() const;
        std::string         getType() const;
        void                setType(const std::string& type);

};
