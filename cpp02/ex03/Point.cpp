#include "Point.hpp"

const Fixed Point::getX() const
{
	return (this->_x);
}

const Fixed Point::getY() const
{
	return (this->_y);
}

Point &Point::operator=( const Point &other )
{
	*(Fixed *)&this->_x = other.getX();
	*(Fixed *)&this->_y = other.getY();
	return (*this);
}

