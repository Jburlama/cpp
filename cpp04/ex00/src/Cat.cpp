#include "../headers/Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "Cat constructor\n";
}

Cat::Cat(const Cat &other)
{
	this->type = other.type;
	std::cout << "Cat copy constructor\n";
	return ;
}

Cat &Cat::operator=(const Cat &other)
{
	this->type = other.type;
	std::cout << "Cat copy assiagment\n";
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor\n";
	return ;
}

void Cat::makeSound(void) const
{
	std::cout << "Meaaaawwwwwww!\n";
	return ;
}
