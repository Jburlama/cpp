#include "../headers/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->type = "Animal";
	std::cout << "WrongAnimal constructor\n";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor\n";
	return ;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "Im a animal!\n";
	return ;
}

std::string WrongAnimal::getType(void) const
{
	return (this->type);
}
