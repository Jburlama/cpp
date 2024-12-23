#include "../headers/Ice.hpp"

AMateria *Ice::clone() const
{
	AMateria *m = new Ice();
	return (m);
}

Ice::Ice( const Ice &other)
: AMateria("ice")
{
	(void) other;
	return ;
}

Ice &Ice::operator=(const Ice &other)
{
	(void) other;
	return (*this);
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
