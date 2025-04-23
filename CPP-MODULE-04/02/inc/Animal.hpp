#pragma once

#include <iostream>

class Animal {

    protected:
        
        std::string _type;
        Animal();
        Animal(std::string t);
        Animal(const Animal& other);

    public:

        virtual ~Animal();
        Animal & operator=(const Animal& other);

        
        virtual void    makeSound() const;
        std::string     getType() const;
        void            setType(std::string type);


};
