#include "../headers/Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	return ;
}

Dog::Dog(const Dog &other)
{
	this->type = other.type;
	return ;
}

Dog &Dog::operator=(const Dog &other)
{
	this->type = other.type;
	return (*this);
}

Dog::~Dog()
{
	return ;
}

void Dog::makeSound(void) const
{
	std::cout << "Au au au!\n";
	return ;
}
