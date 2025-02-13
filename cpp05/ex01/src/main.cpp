#include <iostream>
#include "../headers/Bureaucrat.hpp"
#include "../headers/Form.hpp"

int main(void)
{
	try
	{
		Bureaucrat b("Quim", 70);
		Form f("Tua Mãe", 69, 42);

		b.signForm(f);
	}
	catch (Form::GradeTooHighException &e)
 	{
		std::cout << e.what() << "\n";
	}
	catch (Form::GradeTooLowException &e)
 	{
		std::cout << e.what() << "\n";
	}
}

