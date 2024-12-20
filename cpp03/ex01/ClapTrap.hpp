#pragma once
#include <iostream>

class ClapTrap {
	protected:
		std::string _name;
		unsigned int _hit_point;
		unsigned int _energy_point;
		unsigned int _attack_damage;
	public:
		ClapTrap();
		ClapTrap( const std::string name );
		ClapTrap( const ClapTrap &other );
		ClapTrap &operator=( const ClapTrap &other );
		~ClapTrap();
		void attack( const std::string &target );
		void takeDamage( unsigned int amount );
		void beRepaired( unsigned int amount );
};
