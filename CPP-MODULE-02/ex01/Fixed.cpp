#include "Fixed.hpp"

// Static
const int Fixed::_storeBits = 8; // !8 bits :)

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

Fixed::Fixed(const float number) : _fixedPointValue(roundf(number)) {
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
		this->_fixedPointValue = other.getRawBits();
	}
	return *this;
}

// <<
std::ostream& operator<<(std::ostream& os, const Fixed& other)  {
	os << other._fixedPointValue;
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
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointValue = raw;
}