#include "FragTrap.hpp"

FragTrap::FragTrap()
: ClapTrap(  )
{
	std::cout << "FragTrap default constructor called.\n";
}

FragTrap::FragTrap( const FragTrap &other )
: ClapTrap( other._name )
{
	std::cout << "FragTrap copy constructor called.\n";
	return ;
}

FragTrap &FragTrap::operator=( const FragTrap &other )
{
	std::cout << "FragTrap copy assignment operator called.\n";
	this->ClapTrap::operator=(other);
	return (*this);
}

FragTrap::~FragTrap(  )
{
	std::cout << "FragTrap destructor called.\n";
}

FragTrap::FragTrap( const std::string name )
: ClapTrap( name )
{
	std::cout << "FragTrap parametized constructor called.\n";
	this->_hit_point = 100;
	this->_energy_point = 100;
	this->_attack_damage = 30;
	return ;
}

void FragTrap::highFivesGuys( void )
{
	std::cout << "FragTrap highFives guys!\n";
}
