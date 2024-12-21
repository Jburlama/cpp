#include "../headers/WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "Cat";
}

WrongCat::WrongCat(const WrongCat &other)
{
	this->type = other.type;
	return ;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	this->type = other.type;
	return (*this);
}

WrongCat::~WrongCat()
{
	return ;
}

void WrongCat::makeSound(void) const
{
	std::cout << "Meaaaawwwwwww!\n";
	return ;
}
