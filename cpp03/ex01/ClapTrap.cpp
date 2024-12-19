#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap defaut constructor called.\n";
	this->_name = "Default";
	this->_hit_point = 10;
	this->_energy_point = 10;
	this->_attack_damage = 0;
}

ClapTrap::ClapTrap( const std::string name )
{
	std::cout << "ClapTrap constructor called.\n";
	this->_name = name;
	this->_hit_point = 10;
	this->_energy_point = 10;
	this->_attack_damage = 0;
}

ClapTrap::ClapTrap( const ClapTrap &other )
{
	std::cout << "ClapTrap copy constructor called.\n";
	this->_name = other._name;
	this->_hit_point = other._hit_point;
	this->_energy_point = other._energy_point;
	this->_attack_damage = other._attack_damage;
}

ClapTrap	&ClapTrap::operator=( const ClapTrap &other )
{
	std::cout << "ClapTrap copy assignment constructor called.\n";
	this->_name = other._name;
	this->_hit_point = other._hit_point;
	this->_energy_point = other._energy_point;
	this->_attack_damage = other._attack_damage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called.\n";
}

void ClapTrap::attack( const std::string &target )
{
	std::cout << "ClapTrap ";
	std::cout << this->_name << " ";
	std::cout << "attacks ";
	std::cout << target << ", ";
	std::cout << "causing ";
	std::cout << this->_attack_damage << " ";
	std::cout << "points of damage!\n";
}

void ClapTrap::takeDamage( unsigned int amount )
{
	std::cout << "ClapTrap ";
	std::cout << this->_name << " ";
	std::cout << "took ";
	std::cout << amount << " ";
	std::cout << "hit points of damage!\n";
}

void ClapTrap::beRepaired( unsigned int amount )
{
	std::cout << "ClapTrap ";
	std::cout << this->_name << " ";
	std::cout << "got ";
	std::cout << amount << " ";
	std::cout << "hit points!\n";
}
