#include "../headers/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; ++i)
		this->_src[i] = NULL;
	return ;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	for (int i = 0; i < 4; ++i)
	{
		if (other._src[i])
		{
			if (other._src[i]->getType() == "ice")
				this->_src[i] = new Ice();
			else if (other._src[i]->getType() == "cure")
				this->_src[i] = new Cure();
		}
		else
			this->_src[i] = NULL;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	for (int i = 0; i < 4; ++i)
	{
		if (other._src[i])
		{
			if (other._src[i]->getType() == "ice")
				this->_src[i] = new Ice();
			else if (other._src[i]->getType() == "cure")
				this->_src[i] = new Cure();
		}
		else
			this->_src[i] = NULL;
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; ++i)
	{
		if (this->_src[i])
			delete this->_src[i];
	}
}

void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; ++i)
	{
		if (!this->_src[i])
		{
			this->_src[i] = m;
			break ;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (_src[i] && _src[i]->getType() == type)
		{
			if (type == "ice")
				return (new Ice());
			else if (type == "cure")
				return (new Cure());
		}
	}
	return (NULL);
}
