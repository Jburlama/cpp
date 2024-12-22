#include "../headers/Animal.hpp"
#include "../headers/WrongAnimal.hpp"
#include "../headers/Brain.hpp"

int main()
{
	Animal *d = new Dog();
	Animal *c = new Cat();

	d->makeSound();
	c->makeSound();

	delete d;
	delete c;
}
