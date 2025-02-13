#include "../headers/Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	this->brain = new Brain;
	for (int i = 0; i < 100; ++i)
		this->brain->ideas[i] = "au ";
	return ;
}

Dog::Dog(const Dog &other)
{
	this->type = other.type;
	this->brain = new Brain;
	for (int i = 0; i < 100; ++i)
		this->brain->ideas[i] = other.brain->ideas[i];
	return ;
}

Dog &Dog::operator=(const Dog &other)
{
	this->type = other.type;
	this->brain = new Brain;
	for (int i = 0; i < 100; ++i)
		this->brain->ideas[i] = other.brain->ideas[i];
	return (*this);
}

Dog::~Dog()
{
	delete this->brain;
	return ;
}

void Dog::makeSound(void) const
{
	std::cout << this->brain->ideas[0] << "\n";
	return ;
}
