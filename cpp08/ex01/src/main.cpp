#include "../includes/Span.hpp"

int mult(int i);

int main(void)
{
	std::cout << "Test 1:\n";
	std::cout << "----------------------------------------------\n";
	{
		Span s(20);
	
		try
		{
			s.addNumber(69);
			s.addNumber(-9);
			s.addNumber(-6);
		}
		catch (const std::logic_error &e)
		{
			std::cout << e.what() << "\n";
		}
	
		std::cout << "count: ";
		std::cout << s.getCount() << "\n";
	
		s.printContainer();
		try
		{
			std::cout << "shortestSpan: ";
			std::cout << s.shortestSpan() << "\n";
	
			std::cout << "longestSpan: ";
			std::cout << s.longestSpan() << "\n";
		}
		catch (const std::logic_error &e)
		{
			std::cout << e.what() << "\n";
		}
	}
	std::cout << "\n";
	std::cout << "Test 2:\n";
	std::cout << "----------------------------------------------\n";
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.printContainer();
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << "\n";
	std::cout << "Test 3:\n";
	std::cout << "----------------------------------------------\n";
	{
		Span sp = Span(100000);

		try
		{
			sp.addNumbers(std::pair<int,int>(10000, 20000), mult);
		}
		catch (const std::logic_error &e)
		{
			std::cout << e.what() << "\n";
		}
		std::cout << "shortest: ";
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << "longest: ";
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << "\n";
	std::cout << "Test 4:\n";
	std::cout << "----------------------------------------------\n";
	{
		Span sp(10);
		sp.addNumbers(std::pair<int,int>(10, 20), mult);
		sp.printContainer();

		Span sp2(sp);
		sp2.printContainer();

		Span sp3 = sp;
		sp3.printContainer();

		std::cout << "shortest: ";
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << "longest: ";
		std::cout << sp2.longestSpan() << std::endl;
	}
}

int mult(int i)
{
	return i * i;
}
