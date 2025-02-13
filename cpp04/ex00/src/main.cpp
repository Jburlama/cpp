#include "../headers/Animal.hpp"
#include "../headers/WrongAnimal.hpp"

int main()
{
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	const WrongAnimal* w_cat = new WrongCat();
	std::cout << "\n";

	std::cout << animal->getType() << "\n";
	std::cout << dog->getType() << "\n";
	std::cout << cat->getType() << "\n";
	std::cout << w_cat->getType() << "\n";

	dog->makeSound();
	cat->makeSound();
	animal->makeSound();
	w_cat->makeSound();

	std::cout << "\n";

	delete animal;
	delete dog;
	delete cat;
	delete w_cat;
	return 0;
}
