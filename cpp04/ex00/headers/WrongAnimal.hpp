#pragma once
#include <string>
#include <iostream>

class WrongAnimal {
	protected:
		std::string type;
	public:
		WrongAnimal();
		~WrongAnimal();
		void makeSound(void) const;
		std::string getType(void) const;
};

#include "WrongCat.hpp"
