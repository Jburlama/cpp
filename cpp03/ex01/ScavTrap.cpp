#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
: ClapTrap()
{
	std::cout << "ScavTrap defaut constructor called.\n";
	this->_hit_point = 100;
	this->_energy_point = 50;
	this->_attack_damage = 20;
}

ScavTrap::ScavTrap( const std::string name )
: ClapTrap( name )
{
	std::cout << "ScavTrap parametized constructor called.\n";
	this->_hit_point = 100;
	this->_energy_point = 50;
	this->_attack_damage = 20;
}

ScavTrap::ScavTrap( const ScavTrap &other )
: ClapTrap( other._name )
{
	std::cout << "ScavTrap copy constructor called.\n";
	return ;
}

ScavTrap &ScavTrap::operator=( const ScavTrap &other )
{
		std::cout << "ScavTrap copy assignment operator called.\n";
	this->ClapTrap::operator=(other);
	return (*this);
}

ScavTrap::~ScavTrap(  )
{
	std::cout << "ScavTrap destructor called.\n";
}

void ScavTrap::attack( const std::string &target )
{
	std::cout << "ScavTrap ";
	std::cout << this->_name << " ";
	std::cout << "attacks ";
	std::cout << target << ", ";
	std::cout << "causing ";
	std::cout << this->_attack_damage << " ";
	std::cout << "points of damage!\n";
}

void ScavTrap::guardGate(  )
{
	std::cout << "ScavTrap is now in Gatekeeper mode!\n";
}
