#pragma once
#include "Weapon.hpp"

class HumanB {
	public:
		HumanB(std::string name):_name(name) {}
		void attack() const;
		void setWeapon(Weapon &weapon);
	private:
		std::string _name;
		Weapon		*_weapon;
};
