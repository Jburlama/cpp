#include "../headers/ICharacter.hpp"

int main(void)
{
	AMateria *m = new Cure();
	ICharacter *c = new Character("ze");

	std::cout << c->getName() << "\n";

	c->equip(m);
	c->equip(m);
}
