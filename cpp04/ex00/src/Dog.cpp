#include "../headers/Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << "Dog constructor\n";
	return ;
}

Dog::Dog(const Dog &other)
{
	this->type = other.type;
	std::cout << "Dog copy constructor\n";
	return ;
}

Dog &Dog::operator=(const Dog &other)
{
	this->type = other.type;
	std::cout << "Dog copy assiagment\n";
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor\n";
	return ;
}

void Dog::makeSound(void) const
{
	std::cout << "Au au au!\n";
	return ;
}
