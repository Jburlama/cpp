#include <iostream>
#include "../headers/Serializer.hpp"
#include "../headers/Data.hpp"

int main(void)
{
	Data 		data;
	uintptr_t 	ptr;

	data.foo = 42;
	std::cout << &data << "\n";

	ptr = Serializer::serialize(&data);
	std::cout << ptr << "\n";

	Data *d_ptr;

	d_ptr = Serializer::deserialize(ptr);
	std::cout << d_ptr << "\n";

	std::cout << data.foo << "\n";
	std::cout << d_ptr->foo << "\n";
}
