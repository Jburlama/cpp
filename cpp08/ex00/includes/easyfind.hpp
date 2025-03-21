#include <algorithm>
#include <exception>
#include <iostream>
#include <list>
#include <sstream>
#include <vector>


template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator b, e, found;

	b = container.begin();
	e = container.end();
	found = std::find(b, e, value);
	if (found == e)
	{
		std::ostringstream os;

		os << value;
		throw std::logic_error(os.str() + " Not Found");
	}

	return found;
}
