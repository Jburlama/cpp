#include <iostream>
#include "../headers/Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat b("Josephina", 69);
		std::cout << b << "\n";
		b.incrementGrade(42);
		std::cout << b << "\n";
		b.incrementGrade(42);
	}
	catch (Bureaucrat::GradeTooHighException &e)
 	{
		std::cout << e.what() << "\n";
	}
	catch (Bureaucrat::GradeTooLowException &e)
 	{
		std::cout << e.what() << "\n";
	}
}
