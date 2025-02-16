#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {

	private:
		int 				_fixedPointValue;
		static const int	 _storeBits;

	public:

		//  Constructor
		Fixed();
		Fixed(const Fixed& other);
		Fixed(const int number);
		Fixed(const float number);

		// Destructor
		~Fixed();
		Fixed&	operator=(const Fixed& other);
		friend 	std::ostream& operator<<(std::ostream& os, const Fixed& other);
		int		getRawBits ( void ) const;
		void 	setRawBits ( int const raw );


};


// Constructor that  takes a const integer as parameter
#endif