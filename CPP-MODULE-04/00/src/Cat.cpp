#include "Cat.hpp"

Cat::Cat()
    : Animal() {
    
    this->type = "Default";
    std::cout << "Cat " << this->type << " default constructor." << std::endl;
    
}

// Cat::Cat(std::string t)
//     : Animal() {
    
//     std::cout << "Cat " << this->type << " default constructor." << std::endl;

// }

