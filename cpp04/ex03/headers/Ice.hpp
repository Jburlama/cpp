#pragma once
#include "AMateria.hpp"

class Ice: public AMateria {
	public:
		Ice(): AMateria("ice") {};
		Ice(const Ice &other);
		Ice &operator=(const Ice &other);
	 	~Ice() {};
		AMateria *clone() const;
		void use(ICharacter &target);
};
