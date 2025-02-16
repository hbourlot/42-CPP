#ifndef FIXED_CPP
# define FIXED_CPP


#include <iostream>

class Fixed {

	private:
		int _value;
		static const int _storeBits;

	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed ();
		int getRawBits ( void ) const;
		void setRawBits ( int const raw );
		Fixed& setValue( int value );
		void getValue();
};

#endif