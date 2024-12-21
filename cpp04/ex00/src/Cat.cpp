#include "../headers/Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
}

Cat::Cat(const Cat &other)
{
	this->type = other.type;
	return ;
}

Cat &Cat::operator=(const Cat &other)
{
	this->type = other.type;
	return (*this);
}

Cat::~Cat()
{
	return ;
}

void Cat::makeSound(void) const
{
	std::cout << "Meaaaawwwwwww!\n";
	return ;
}
