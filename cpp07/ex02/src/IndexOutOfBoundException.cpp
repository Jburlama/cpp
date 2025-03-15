#include "../includes/IndexOutOfBoundException.hpp"

const char *IndexOutOfBoundException::what() const throw()
{
	return "Index is out of bound";
}
