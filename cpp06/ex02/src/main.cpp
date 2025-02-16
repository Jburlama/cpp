#include "../headers/dynamic.hpp"

int	main(void)
{
	Base *ptr;

	ptr = generate();
	identify(*ptr);
	identify(ptr);

	if (ptr)
		delete ptr;
}

