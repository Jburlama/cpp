#pragma once
#include <exception>
#include <string>

class IndexOutOfBoundException
:public std::exception
{
	public:
		const char *what() const throw();
};
