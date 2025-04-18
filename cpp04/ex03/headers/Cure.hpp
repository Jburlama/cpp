#pragma once
#include "AMateria.hpp"

class Cure: public AMateria {
	public:
		Cure(): AMateria("cure") {};
		Cure(const Cure &other);
		Cure &operator=(const Cure &other);
	 	~Cure() {};
		AMateria *clone() const;
		void use(ICharacter &target);
};
