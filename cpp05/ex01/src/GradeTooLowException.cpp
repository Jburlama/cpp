#include "../headers/GradeTooLowException.hpp"

const char *GradeTooLowException::what() const throw()
{
	return "GradeTooLowException";
}
