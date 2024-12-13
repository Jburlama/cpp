#include "../HumanA.hpp"

void HumanA::attack( void ) const
{
	std::cout << this->_name;
	std::cout << " attacks with their ";
	std::cout << this->_weapon.getType();
	std::cout << std::endl;
}
