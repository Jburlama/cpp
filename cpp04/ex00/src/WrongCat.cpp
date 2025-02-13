#include "../headers/WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "Cat";
	std::cout << "WrongCat constructor\n";
}

WrongCat::WrongCat(const WrongCat &other)
{
	this->type = other.type;
	std::cout << "WrongCat copy constructor\n";
	return ;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	this->type = other.type;
	std::cout << "WrongCat copy assiagment\n";
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat copy destructor\n";
	return ;
}

void WrongCat::makeSound(void) const
{
	std::cout << "Meaaaawwwwwww!\n";
	return ;
}
