#pragma once
#include <exception>
#include <string>

class GradeTooHighException: public std::exception
{
	public:
		const char *what() const throw();
};
