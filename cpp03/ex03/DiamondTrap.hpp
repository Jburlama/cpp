#pragma once
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap {
	private:
		std::string _name;
		unsigned int _hit_point;
		unsigned int _energy_point;
		unsigned int _attack_damage;
	public:
		DiamondTrap();
		DiamondTrap( const DiamondTrap &other );
		DiamondTrap &operator=( const DiamondTrap &other );
		DiamondTrap( const std::string name );
		~DiamondTrap();
		void attack( const std::string &target );
		void whoAmI( void );
};
