#pragma once
#include <string>
#include <iostream>

class Animal {
	protected:
		std::string type;
	public:
		Animal();
		virtual ~Animal() = 0;
		virtual void makeSound(void) const = 0;
		virtual std::string getType(void) const;
};

#include "Dog.hpp"
#include "Cat.hpp"
