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
		MutantStack(MutantStack &other);
		MutantStack &operator=(MutantStack &other);
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
MutantStack<T>::MutantStack(MutantStack &other)
:std::stack<T>()
{
	MutantStack<T>::iterator begin;
	MutantStack<T>::iterator end;

	begin = other.begin();
	end = other.end();

	while (begin != end)
	{
		this->push(*begin);
		begin++;
	}
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack &other)
{
	if (this != &other)
	{
		std::stack<T>();
		
		MutantStack<T>::iterator begin;
		MutantStack<T>::iterator end;
	
		begin = other.begin();
		end = other.end();
	
		while (begin != end)
		{
			this->push(*begin);
			begin++;
		}
	}
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack()
{}
