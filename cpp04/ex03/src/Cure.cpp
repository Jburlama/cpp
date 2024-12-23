#include "../headers/Cure.hpp"

AMateria *Cure::clone() const
{
	AMateria *m = new Cure();
	return (m);
}

Cure::Cure(const Cure &other)
: AMateria("cure")
{
	(void) other;
	return ;
}

Cure &Cure::operator=(const Cure &other)
{
	(void) other;
	return (*this);
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}
