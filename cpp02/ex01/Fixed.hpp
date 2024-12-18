#pragma once
#include <iostream>
#include <math.h>

class Fixed {
	private:
		static const int 	_fractional_bit = 8;
		int					_fixed_point;
	public:
		Fixed();
		Fixed( const Fixed &other );
		Fixed( const int number );
		Fixed( const double number );
		Fixed &operator=( const Fixed &other );
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream &operator<<( std::ostream &str, const Fixed &fp );
