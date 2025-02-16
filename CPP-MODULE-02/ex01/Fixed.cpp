#include "Fixed.hpp"

// Static
const int Fixed::_storeBits = 8; // 8 bits scale :)

// Constructor
Fixed::Fixed() : _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	operator=(other);
}

Fixed::Fixed(const int number ) : _fixedPointValue(number << _storeBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float number) : _fixedPointValue(roundf(number *  (1 << _storeBits))) {
	std::cout << "Float constructor called" << std::endl;
}


//Destructor 
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
	this->_fixedPointValue = 0;
}


// Assignment operator

// =
Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (&other != this) {
		this->_fixedPointValue = other._fixedPointValue;
	}
	return *this;
}

// <<
std::ostream& operator<<(std::ostream& os, const Fixed& other)  {
	os << other.toFloat();
	return os;
}


// Public methods

// getter
int	Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointValue;
}

// setter
void Fixed::setRawBits( int const raw ) {
	this->_fixedPointValue = raw;
}

float	Fixed::toFloat( void ) const {
	return (float)this->_fixedPointValue / (1 << _storeBits);
}

int	Fixed::toInt( void ) const {
	return this->_fixedPointValue / (1 << _storeBits);
}


// Int to fixed-point -> value << _storeBits
// float to fixed-point -> value * (1 << _storeBits) 


// fixed-point to float -> (float)value / (1 << _storeBits)
// fixed-point fo int -> value / ( << _storeBits) || value / 256( for 8 bits)
