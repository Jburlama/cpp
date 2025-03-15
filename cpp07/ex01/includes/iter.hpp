#include <iostream>

template <typename T>
void iter(T *ptr, int length, void (*func)(T const&))
{
	for (int i = 0; i < length; i++)
		func(ptr[i]);
}
