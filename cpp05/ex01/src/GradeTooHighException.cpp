#include "../headers/GradeTooHighException.hpp"

const char *GradeTooHighException::what() const throw()
{
	return "GradeTooHighException";
}
