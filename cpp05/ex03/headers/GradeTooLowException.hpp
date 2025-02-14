#pragma once
#include <exception>
#include <string>

class GradeTooLowException: public std::exception
{
	public:
		const char *what() const throw();
};
