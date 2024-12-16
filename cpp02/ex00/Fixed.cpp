#include "Fixed.hpp"

Fixed::Fixed( void )
{
	this->fixed_point = 0;
	std::cout << "Default constructor called\n";
}

Fixed::Fixed( const Fixed &other)
{
	std::cout << "Copy constructor called\n";
	this->fixed_point = other.getRawBits();
}

Fixed &Fixed::operator=( const Fixed &other )
{
	std::cout << "Copy assignment operator called\n";
	this->fixed_point = other.getRawBits();
	return (*this);
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called\n";
	return (this->fixed_point);
}

void Fixed::setRawBits( int const raw )
{
	this->fixed_point = raw;
}
