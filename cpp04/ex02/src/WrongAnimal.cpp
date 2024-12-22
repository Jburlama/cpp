#include "../headers/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->type = "Animal";
}

WrongAnimal::~WrongAnimal()
{
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
