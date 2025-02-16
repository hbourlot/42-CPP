#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>


class Fixed {

    private:
        int                 _fixedPointNumber;
        static const int    _storeBits;
    public:

        // Constructor
        Fixed();
        Fixed(const Fixed& other);
        Fixed(const int value );
        Fixed(const float value ); 
        
        // Destructor
        ~Fixed();

        // Getter
		int		getRawBits( void ) const;

        // Setter
        void    setRawBits( int const raw );

        // Assignment operator
        Fixed&  operator=(const Fixed& other);
        friend  std::ostream& operator<<(std::ostream& os, const Fixed& other);
        bool    operator>(const Fixed& other) const;
        bool    operator<(const Fixed& other) const;
        bool    operator<=(const Fixed& other) const;
        bool    operator>=(const Fixed& other) const;  
        bool    operator==(const Fixed& other) const;
        bool    operator!=(const Fixed& other) const;
        int     operator+(const Fixed& other);
        int     operator-(const Fixed& other);
        int     operator*(const Fixed& other);
        int     operator/(const Fixed& other);
        Fixed&  operator--( void );
        Fixed&  operator++( void );
        Fixed&  operator++( int );
        Fixed&  operator--( int );

        // overload member
        static        Fixed&    min(Fixed &first, Fixed& second);
        static const  Fixed&    min(const Fixed &first, const Fixed& second);
        static        Fixed&    max(Fixed &first, Fixed& second);
        static const  Fixed&    max(const Fixed &first, const Fixed& second);

        // Methods
        float   toFloat( void ) const;
        int     toInt( void ) const;
};

#endif