#pragma once
#include <iostream>

class Fixed {
	private:
		static const int 	fractional_bit = 8;
		int					fixed_point;
	public:
		Fixed();
		Fixed( const Fixed &other );
		Fixed &operator=( const Fixed &other );
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};
