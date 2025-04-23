#include "WrongCat.hpp"


WrongCat::WrongCat()
	: WrongAnimal() {

    std::cout << this->getType() << " (default constructor)." << std::endl;
}

WrongCat::WrongCat(std::string type)
	: WrongAnimal(type) {

	std::cout << this->getType() << " (default constructor)." << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
	: WrongAnimal(other.getType()) {
	
	std::cout << this->getType() << " (copy constructor)." << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& other) {

	if (this != &other) {
		this->setType(other.getType());
	}
	std::cout << this->getType() << " (assignment operator=)." << std::endl;
	return *this;
}

WrongCat::~WrongCat() {
	
	std::cout << this->getType() << " (destructor)." << std::endl;
}

void WrongCat::makeSound( void ) const {

	std::cout << "WrongCat sound!" << std::endl;
}
