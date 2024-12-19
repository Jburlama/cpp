#include "Fixed.hpp"

Fixed::Fixed( void )
{
	this->_fixed_point = 0;
}

Fixed::Fixed( const Fixed &other)
{
	this->_fixed_point = other.getRawBits();
}

Fixed::Fixed( const int number )
{
	this->_fixed_point = number << this->_fractional_bit;
}

Fixed::Fixed( const double number )
{
	this->_fixed_point = roundf(number * (1 << this->_fractional_bit));
}

Fixed &Fixed::operator=( const Fixed &other )
{
	this->_fixed_point = other.getRawBits();
	return (*this);
}

Fixed &Fixed::operator++()
{
	this->_fixed_point++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp;

	tmp = *this;
	this->_fixed_point++;
	return (tmp);
}

Fixed &Fixed::operator--()
{
	this->_fixed_point--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp;

	tmp = *this;
	this->_fixed_point--;
	return (tmp);
}

Fixed Fixed::operator+( const Fixed &other )
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator*( const Fixed &other )
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/( const Fixed &other )
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed Fixed::operator-( const Fixed &other )
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

bool Fixed::operator>( const Fixed &other ) const
{
	return (this->getRawBits() > other.getRawBits());
}

bool Fixed::operator>=( const Fixed &other ) const
{
	return (this->getRawBits() >= other.getRawBits());
}

bool Fixed::operator<( const Fixed &other ) const
{
	return (this->getRawBits() < other.getRawBits());
}

bool Fixed::operator<=( const Fixed &other ) const
{
	return (this->getRawBits() <= other.getRawBits());
}

bool Fixed::operator==( const Fixed &other ) const
{
	return (this->getRawBits() == other.getRawBits());
}

bool Fixed::operator!=( const Fixed &other ) const
{
	return (this->getRawBits() != other.getRawBits());
}

Fixed::~Fixed( void )
{
}

int Fixed::getRawBits( void ) const
{
	return (this->_fixed_point);
}

void Fixed::setRawBits( int const raw )
{
	this->_fixed_point = raw;
}

float Fixed::toFloat( void ) const
{
	return ((float)this->_fixed_point / (1 << this->_fractional_bit));
}

int Fixed::toInt( void ) const
{
	return (this->_fixed_point >> this->_fractional_bit);
}

Fixed &Fixed::min( Fixed &a, Fixed &b )
{
	return (a < b ? a : b);
}

Fixed &Fixed::max( Fixed &a, Fixed &b )
{
	return (a > b ? a : b);
}

const Fixed &Fixed::min( const Fixed &a, const Fixed &b )
{
	return (a > b ? a : b);
}

const Fixed &Fixed::max( const Fixed &a, const Fixed &b )
{
	return (a > b ? a : b);
}

std::ostream &operator<<( std::ostream &str, const Fixed &fp )
{
	std::cout << fp.toFloat();
	return (str);
}
