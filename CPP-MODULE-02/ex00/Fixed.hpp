#ifndef FIXED_CPP
# define FIXED_CPP


#include <iostream>

class Fixed {

	private:
		int _value;

	public:
		Fixed() {
			std::cout << "Default constructor called" << std::endl;
		}

		Fixed(const Fixed& other) {
			std::cout << "Copy constructor called" << std::endl;
			this->_value = other._value;
		}
		Fixed& operator=(const Fixed& other) {
			std::cout << "Copy assignment operator called" << std::endl;
			if (this != &other) {
				this->_value = other._value;
			}
			return *this;
		}

		~Fixed () {
			std::cout << "Destructor called" << std::endl;
		}

		int getRawBits ( void ) const {
			return this->_value;
		}
		void setRawBits ( int const raw ) {
			this->_value = raw;
		}

		Fixed& setValue( int value ) {
			this->_value = value;
			return *this;
		}
		
		void getValue() {
			std::cout << "Value: " << this->_value << std::endl;
		}
};

#endif