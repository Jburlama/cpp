#include "../HumanB.hpp"

void HumanB::attack( void ) const
{
	std::cout << this->_name;
	std::cout << " attacks with their ";
	std::cout << this->_weapon->getType();
	std::cout << std::endl;
}

void HumanB::setWeapon( Weapon &weapon )
{
	this->_weapon = &weapon;
}
