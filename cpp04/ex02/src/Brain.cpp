#include "../headers/Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default contructor!\n";
	for (int i = 0; i < 100; ++i)
		this->ideas[i] = "null";
	return ;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain copy contructor!\n";
	for (int i = 0; i < 100; ++i)
		this->ideas[i] = other.ideas[i];
	return ;
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Brain copy assignment operator!\n";
	for (int i = 0; i < 100; ++i)
		this->ideas[i] = other.ideas[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor!\n";
	return ;
}
