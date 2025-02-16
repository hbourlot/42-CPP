#include "Fixed.hpp"

const int Fixed::_storeBits = 8;

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	this->_value = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_value = other._value;
	}
	return *this;
}


Fixed::~Fixed () {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits ( void ) const {
	return this->_value;
}

void Fixed::setRawBits ( int const raw ) {
	this->_value = raw;
}

Fixed& Fixed::setValue( int value ) {
	this->_value = value;
	return *this;
}

void Fixed::getValue() {
	std::cout << "Value: " << this->_value << std::endl;
}