#include <iostream>
#include <set>
#include <sstream>

class Span
{
	private:
		unsigned int	_max_capacity;
		unsigned int	_count;
		std::set<int> 	_container;
		Span();
	public:
		Span(unsigned int N);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		std::set<int>	getContainer() const;
		unsigned int 	getCapacity() const;
		unsigned int 	getCount() const;
		void			addNumber(int number);
		void			addNumbers(std::pair<int, int> range, int (*func)(int));
		void			printContainer();
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
};
