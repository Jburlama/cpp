#include "../includes/Span.hpp"

Span::Span(unsigned int N)
{
	this->_max_capacity = N;
	this->_count = 0;
}


Span::Span(const Span &other)
:_max_capacity(other.getCapacity())
{
	std::set<int> container;

	container = other.getContainer();
	for (std::set<int>::iterator it = container.begin(); it != container.end(); it++)
	{
		this->_container.insert(*it);
		this->_count++;
	}
}


Span &Span::operator=(const Span &other)
{
	std::set<int> container;

	this->_max_capacity = other.getCapacity();
	container = other.getContainer();
	for (std::set<int>::iterator it = container.begin(); it != container.end(); it++)
	{
		this->_container.insert(*it);
		this->_count++;
	}
	return *this;
}

Span::~Span(){}


std::set<int> Span::getContainer() const
{
	return this->_container;
}

unsigned int Span::getCapacity() const
{
	return this->_max_capacity;
}

unsigned int Span::getCount() const
{
	return this->_count;
}

void Span::addNumber(int number)
{
	if (this->_count == this->_max_capacity)
		throw std::logic_error("Max capacity exceeded");


	if (this->_container.find(number) != this->_container.end())
	{
		std::ostringstream os;

		os << number;
		throw std::logic_error("Container already has element: " + os.str());
	}
		
	this->_container.insert(number);
	this->_count++;
}

void Span::addNumbers(std::pair<int, int> range, int (*func)(int))
{
	if (this->_count == this->_max_capacity)
		throw std::logic_error("Max capacity exceeded");

	for (int i = range.first; i < range.second; i++)
	{
		int number = func(i);
		if (this->_container.find(number) != this->_container.end())
		{
			std::ostringstream os;
	
			os << number;
			throw std::logic_error("Container already has element: " + os.str());
		}
			
		this->_container.insert(number);
		this->_count++;
	}
}

void Span::printContainer()
{
	for (std::set<int>::iterator it = this->_container.begin(); it != this->_container.end(); it++)
		std::cout << *it << ", ";
	std::cout << "\n";
}

unsigned int	Span::shortestSpan()
{
	std::set<int>::iterator it;
	int 			shortest_span;

	if (this->_container.size() <= 1)
		throw std::logic_error("No span found");

	shortest_span = 0;
	it = this->_container.begin();

	int first, second;
	first = *it;
	while (it != this->_container.end())
	{
		first = *it;
		second = *(++it);
		if (it == this->_container.end())
			break ;
		if (shortest_span == 0)
			shortest_span = second - first;
		else if (shortest_span > (second - first))
			shortest_span = second - first;
	}

	return shortest_span;
}

unsigned int	Span::longestSpan()
{
	std::set<int>::iterator first, last;

	if (this->_container.size() <= 1)
		throw std::logic_error("No span found");

	first = this->_container.begin();
	last = --this->_container.end();

	return *last - *first;
}
