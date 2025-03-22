#pragma once
#include <iostream>
#include <stack>

template <typename T>
class MutantStack
:public std::stack<T>
{
	private:
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;

		MutantStack();
		MutantStack(const MutantStack &other);
		MutantStack &operator=(const MutantStack &other);
		~MutantStack();

		iterator begin();
		iterator end();
};

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::end()
{
	return this->c.end();
}


template <typename T>
MutantStack<T>::MutantStack()
{}


template <typename T>
MutantStack<T>::MutantStack(const MutantStack &other)
{
	*this = other;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &other)
{
	if (this != &other)
		*this = other;
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack()
{}
