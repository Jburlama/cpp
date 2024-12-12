#include "Zombie.hpp"

void	Zombie::announce( void )
{
	std::cout << this->_name << ": ";
	std::cout << "BraiiiiiiinnnzzzZ...";
	std::cout << std::endl;
}

void	Zombie::set_name( std::string name )
{
	this->_name = name;
}

Zombie::~Zombie( void )
{
	std::cout << this->_name << " deleted" << std::endl;
}
