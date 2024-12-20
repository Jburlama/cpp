#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( )
{
	std::cout << "DiamondTrap default constructor called.\n";
	this->_name = ClapTrap::_name + "_clap_name";
	return ;
}

DiamondTrap::~DiamondTrap( )
{
	std::cout << "DiamondTrap destructor called.\n";
	return ;
}

DiamondTrap::DiamondTrap( const DiamondTrap &other )
: FragTrap( other.ClapTrap::_name ), ScavTrap( other.ScavTrap::_name )
{
	std::cout << "DiamondTrap copy constructor called.\n";
	return ;
}

DiamondTrap::DiamondTrap( const std::string name )
: FragTrap( name ), ScavTrap( name )
{
	std::cout << "DiamondTrap parametized constructor called.\n";
	this->ClapTrap::_name = name;
	this->_name = name + "_clap_name";
	this->_hit_point = this->FragTrap::_hit_point;
	this->_energy_point = this->ScavTrap::_energy_point;
	this->_attack_damage = this->FragTrap::_attack_damage;
	return ;
}

DiamondTrap &DiamondTrap::operator=( const DiamondTrap &other )
{
	std::cout << "DiamondTrap copy assignment operator called.\n";
	this->FragTrap::operator=(other);
	return (*this);
}

void DiamondTrap::attack( const std::string &target )
{
	ScavTrap::attack(target);
	return ;
}

void DiamondTrap::whoAmI( void )
{
	std::cout << "DiamondTrap_name: " << this->_name;
	std::cout << " | ClapTrap_name: " << this->ClapTrap::_name << "\n";
}
