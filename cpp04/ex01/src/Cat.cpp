#include "../headers/Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	this->brain = new Brain;
	for (int i = 0; i < 100; ++i)
		this->brain->ideas[i] = "Meauuu ";
	return ;
}

Cat::Cat(const Cat &other)
{
	this->type = other.type;
	this->brain = new Brain;
	for (int i = 0; i < 100; ++i)
		this->brain->ideas[i] = other.brain->ideas[i];
	return ;
}

Cat &Cat::operator=(const Cat &other)
{
	this->type = other.type;
	this->brain = new Brain;
	for (int i = 0; i < 100; ++i)
		this->brain->ideas[i] = other.brain->ideas[i];
	return (*this);
}

Cat::~Cat()
{
	delete this->brain;
	return ;
}

void Cat::makeSound(void) const
{
	std::cout << this->brain->ideas[0] << "\n";
	return ;
}
