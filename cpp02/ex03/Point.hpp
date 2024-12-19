#pragma once
#include "Fixed.hpp"

class Point{
	private:
			const Fixed _x;
			const Fixed _y;
	public:
		Point(): _x(0), _y(0) {}
		Point( const float a, const float b ): _x(a), _y(b) {}
		Point( const Point &other ): _x(other.getX()), _y(other.getY()) {}
		const Fixed getX() const;
		const Fixed getY() const;
		Point &operator=( const Point &other);
		~Point() {};
};
