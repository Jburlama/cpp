#include <iostream>
#include "../headers/Bureaucrat.hpp"
#include "../headers/AForm.hpp"
#include "../headers/ShrubberyCreationForm.hpp"
#include "../headers/RobotomyRequestForm.hpp"
#include "../headers/PresidentialPardonForm.hpp"
#include "../headers/Intern.hpp"

int main(void)
{
	Intern someRandomIntern;
	AForm* rrf;
	try
	{
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		delete rrf;
	}
	catch (std::bad_alloc &e)
	{
		std::cout << e.what() << "\n";
	}
}
