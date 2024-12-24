#pragma once
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource {
	public:
		AMateria *_src[4];
		MateriaSource();
		MateriaSource(const MateriaSource &other);
		MateriaSource &operator=(const MateriaSource &other);
		~MateriaSource();
		void learnMateria(AMateria *m);
		AMateria* createMateria(std::string const & type);
};
