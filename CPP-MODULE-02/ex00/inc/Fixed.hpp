#pragma once

#include <iostream>

class Fixed {

	private:
		int _value;
		static const int _storeBits;

	public:
		Fixed();
		Fixed(const Fixed& other);
		~Fixed ();
		Fixed& operator=(const Fixed& other);
		int getRawBits ( void ) const;
		void setRawBits ( int const raw );
		Fixed& setValue( int value );
		void getValue();
};
