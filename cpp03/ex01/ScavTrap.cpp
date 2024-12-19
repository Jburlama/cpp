#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap defaut constructor called\n";
}

ScavTrap::ScavTrap( const std::string name ) : ClapTrap( name )
{
	std::cout << "ScavTrap constructor called\n";
}

ScavTrap::ScavTrap( const ScavTrap &other )
{
	(void) other;
	return ;
}
