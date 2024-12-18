#include "Fixed.hpp"

Fixed::Fixed( void )
{
	this->_fixed_point = 0;
	std::cout << "Default constructor called\n";
}

Fixed::Fixed( const Fixed &other)
{
	std::cout << "Copy constructor called\n";
	this->_fixed_point = other.getRawBits();
}

Fixed::Fixed( const int number )
{
	this->_fixed_point = number << this->_fractional_bit;
	std::cout << "Int constructor called\n";
}

Fixed::Fixed( const double number )
{
	this->_fixed_point = roundf(number * (1 << this->_fractional_bit));
	std::cout << "Float constructor called\n";
}

Fixed &Fixed::operator=( const Fixed &other )
{
	std::cout << "Copy assignment operator called\n";
	this->_fixed_point = other.getRawBits();
	return (*this);
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called\n";
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

std::ostream &operator<<( std::ostream &str, const Fixed &fp )
{
	std::cout << fp.toFloat();
	return (str);
}
