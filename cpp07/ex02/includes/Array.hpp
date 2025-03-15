#pragma once
#include <iostream>
#include <cstring>
#include "IndexOutOfBoundException.hpp"

template <typename T>
class Array
:public IndexOutOfBoundException
{
	private:
		T 				*_array;
		unsigned int 	_size;
	public:
		unsigned int size(void);
		Array(unsigned int n);
		Array(const Array<T> &other);
		Array();
		~Array() throw();
		T &operator=(const Array<T> &other);
		T &operator[](const int n);
};


template <typename T>
unsigned int Array<T>::size(void)
{ return this->_size; }


template <typename T>
Array<T>::Array(unsigned int n)
:_size(n)
{
	this->_array = new T[n];
	std::memset(this->_array, 0, sizeof(this));
}


template <typename T>
Array<T>::Array(const Array<T> &other)
:_size(other._size)
{
	unsigned int n = this->size();
	this->_array = new T[n];

	for (unsigned int i = 0; i < n; i++)
		this->_array[i] = other._array[i];
}


template <typename T>
Array<T>::Array()
:_array(NULL), _size(0)
{}


template <typename T>
Array<T>::~Array() throw()
{
	delete[] (this->_array);
	return ;
}


template <typename T>
T &Array<T>::operator=(const Array &other)
{
	unsigned int n = other.size();

	this->_size = n;
	this->_array = new T[n];

	for (unsigned int i = 0; i < n; i++)
		this->_array[i] = other._array[i];
	
	return *this;
}


template <typename T>
T &Array<T>::operator[](const int n)
{
	if (n < 0 || n >= (int)this->size())
		throw(Array::IndexOutOfBoundException());
	return this->_array[n];
}
