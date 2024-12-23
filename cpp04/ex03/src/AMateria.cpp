#include "../headers/AMateria.hpp"

const std::string &AMateria::getType() const
{
	return (this->_type);
}


void AMateria::use(ICharacter &target)
{
	(void)target;
	return ;
}
