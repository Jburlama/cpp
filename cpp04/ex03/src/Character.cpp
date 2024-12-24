#include "../headers/Character.hpp"

Character::Character()
{
	this->_name = "Default";
	return ;
}

Character::Character(const Character &other)
{
	this->_name = other.getName();
	for (int i = 0; i < 4; ++i)
	{
		if (other._materia[i])
		{
			if (other._materia[i]->getType() == "ice")
				this->_materia[i] = new Ice();
			else if (other._materia[i]->getType() == "Cure")
				this->_materia[i] = new Cure();
		}
		else
			this->_materia[i] = NULL;
	}
	return ;
}

Character &Character::operator=(const Character &other)
{
	this->_name = other.getName();
	for (int i = 0; i < 4; ++i)
	{
		if (other._materia[i])
		{
			if (other._materia[i]->getType() == "ice")
				this->_materia[i] = new Ice();
			else if (other._materia[i]->getType() == "Cure")
				this->_materia[i] = new Cure();
		}
		else
			this->_materia[i] = NULL;
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; ++i)
	{
		if (this->_materia[i])
			delete this->_materia[i];
	}
}

Character::Character(std::string name)
{
	this->_name = name;
	for (int i = 0; i < 4; ++i)
		this->_materia[i] = NULL;
	return ;
}

std::string const &Character::getName() const
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
		if (!this->_materia[i])
		{
			this->_materia[i] = m;
			break ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
		return ;
	this->_materia[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= 4)
		return ;
	if (this->_materia[idx])
	{
		std::cout << this->_name << " ";
		_materia[idx]->use(target);
	}
}
