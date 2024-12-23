#include "../headers/Character.hpp"

Character::Character()
{
	this->_name = "Default";
	return ;
}

Character::Character(const Character &other)
{
	this->_name = other.getName();
	return ;
}

Character &Character::operator=(const Character &other)
{
	this->_name = other.getName();
	return (*this);
}

Character::Character(std::string name)
{
	this->_name = name;
	for (int i = 0; i < 4; ++i)
		this->_slots[i] = false;
	return ;
}

const std::string &Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria *m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; ++i)
	{
		if (this->_materia[i] == m)
			break ;
		if (!this->_slots[i])
		{
			this->_materia[i] = m;
			this->_slots[i] = true;
			break ;
		}
	}
}
