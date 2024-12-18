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
		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);
		Fixed operator+( const Fixed &other );
		Fixed operator-( const Fixed &other );
		Fixed operator*( const Fixed &other );
		Fixed operator/( const Fixed &other );
		bool operator>( const Fixed &other ) const;
		bool operator>=( const Fixed &other ) const;
		bool operator<( const Fixed &other ) const;
		bool operator<=( const Fixed &other ) const;
		bool operator==( const Fixed &other ) const;
		bool operator!=( const Fixed &other ) const;
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
		static Fixed &min( Fixed &a, Fixed &b );
		static Fixed &max( Fixed &a, Fixed &b );
		static const Fixed &min( const Fixed &a, const Fixed &b);
		static const Fixed &max( const Fixed &a, const Fixed &b);
};

std::ostream &operator<<( std::ostream &str, const Fixed &fp );
