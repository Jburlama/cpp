#include "../headers/Animal.hpp"

Animal::Animal()
{
	this->type = "Animal";
	std::cout << "Animal constructor\n";
}

Animal::~Animal()
{
	std::cout << "Animal destructor\n";
	return ;
}

void Animal::makeSound(void) const
{
	std::cout << "Im a animal!\n";
	return ;
}

std::string Animal::getType(void) const
{
	return (this->type);
}
