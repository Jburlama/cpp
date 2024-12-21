#include "../headers/Animal.hpp"
#include "../headers/WrongAnimal.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* w_cat = new WrongCat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	w_cat->makeSound();

	delete meta;
	delete j;
	delete i;
	delete w_cat;
	return 0;
}
