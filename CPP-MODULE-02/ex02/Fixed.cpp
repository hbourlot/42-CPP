#include "Fixed.hpp"

// static

const int Fixed::_storeBits = 8;


// Constructor
Fixed::Fixed() : _fixedPointNumber(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int number ) : _fixedPointNumber(number << _storeBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float number) : _fixedPointNumber(roundf(number *  (1 << _storeBits))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	operator=(other);
}

// Destructor

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
    this->_fixedPointNumber = 0;
}


// Getter
int	Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointNumber;
}

// Setter
void Fixed::setRawBits( int const raw ) {
	this->_fixedPointNumber = raw;
}

// Assignment operator

// = 
Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (&other != this)
        setRawBits(other.getRawBits());
    return *this;
}
// <<
std::ostream& operator<<(std::ostream& os, const Fixed& other) {
    os << other.toFloat();
    return os;
}
// >
bool Fixed::operator>(const Fixed& other) const {
	return this->toFloat() > other.toFloat();
}
// <
bool Fixed::operator<(const Fixed& other) const {
	return toFloat() < other.toFloat();
}
// <=
bool Fixed::operator<=(const Fixed& other) const {
	return toFloat() <= other.toFloat();
}
// >=
bool Fixed::operator>=(const Fixed& other) const {
	return toFloat() >= other.toFloat();
}
// ==
bool Fixed::operator==(const Fixed& other) const {
	return toFloat() == other.toFloat();
}
// !=
bool Fixed::operator!=(const Fixed& other) const {
	return toFloat() != other.toFloat();
}
// +
int	Fixed::operator+(const Fixed& other) {
	return toInt() + other.toInt();
}
// -
int Fixed::operator-(const Fixed& other) {
	return toInt() - other.toInt();
}
// *
int	Fixed::operator*(const Fixed& other) {
	return toInt() * other.toInt();
}
// /
int Fixed::operator/(const Fixed& other) {
	return toInt() / other.toInt();
}
// --
Fixed& Fixed::operator--() {
	this->_fixedPointNumber--;
	return *this;
}
// ++
Fixed& Fixed::operator++() {
	this->_fixedPointNumber++;
	return *this;
}
// ++ after
Fixed& Fixed::operator++(int) {
	this->_fixedPointNumber++;
	return *this;
}
// -- after
Fixed& Fixed::operator--( int ) {
	this->_fixedPointNumber--;
	return *this;
}

// Overload member

//min
Fixed& Fixed::min(Fixed &first, Fixed& second) {
	if (first.toFloat() < second.toFloat())
		return first;
	return second;
}
// min const
const Fixed& Fixed::min(const Fixed &first, const Fixed& second) {
	if (first.toFloat() < second.toFloat())
		return first;
	return second;
}
// max
Fixed& Fixed::max(Fixed& first, Fixed& second) {
	if (first.toFloat() > second.toFloat())
		return first;
	return second;
}
// max const
const Fixed& Fixed::max(const Fixed& first, const Fixed& second) {
	if (first.toFloat() > second.toFloat())
		return first;
	return second;
}







// Methods

float	Fixed::toFloat( void ) const {
	return (float)this->_fixedPointNumber / (1 << _storeBits);
}

int	Fixed::toInt( void ) const {
	return _fixedPointNumber / (1 << _storeBits);
}
