#pragma once
#include <iostream>
#include <string>
#include "AMateria.hpp"

class AMateria;

class Character: public ICharacter {
	private:
		Character();
		std::string _name;
		bool		_slots[4];
		AMateria	*_materia[4];
	public:
		Character(std::string name);
		Character(const Character &other);
		Character &operator=(const Character &other);
		~Character() {};
		std::string const &getName() const;
		void equip(AMateria *m);
	//	void unequip(int idx);
	//	void use(int idx, ICharacter& target);
};
