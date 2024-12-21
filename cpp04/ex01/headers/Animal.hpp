#pragma once
#include <string>
#include <iostream>

class Animal {
	protected:
		std::string type;
	public:
		Animal();
		virtual ~Animal();
		virtual void makeSound(void) const;
		virtual std::string getType(void) const;
};

#include "Dog.hpp"
#include "Cat.hpp"
