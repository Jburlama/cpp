#include <iostream>
#include "../headers/Bureaucrat.hpp"
#include "../headers/AForm.hpp"
#include "../headers/ShrubberyCreationForm.hpp"
#include "../headers/RobotomyRequestForm.hpp"
#include "../headers/PresidentialPardonForm.hpp"

int main(void)
{
	{
		try
		{
			Bureaucrat b("Joana", 15);
			ShrubberyCreationForm s("home");
	
			b.signForm(&s);
			b.executeForm(s);
		}
		catch (AForm::GradeTooHighException &e)
	 	{
			std::cout << e.what() << "\n";
		}
		catch (AForm::GradeTooLowException &e)
	 	{
			std::cout << e.what() << "\n";
		}
	}
	{
		try
		{
			Bureaucrat b("Quim", 7);
			RobotomyRequestForm f("home");

			b.signForm(&f);
			b.executeForm(f);
		}
		catch (AForm::GradeTooHighException &e)
	 	{
			std::cout << e.what() << "\n";
		}
		catch (AForm::GradeTooLowException &e)
	 	{
			std::cout << e.what() << "\n";
		}
	}
	{
		try
		{
			Bureaucrat b("Ford", 2);
			PresidentialPardonForm f("Arthur");

			b.signForm(&f);
			b.executeForm(f);
		}
		catch (AForm::GradeTooHighException &e)
	 	{
			std::cout << e.what() << "\n";
		}
		catch (AForm::GradeTooLowException &e)
	 	{
			std::cout << e.what() << "\n";
		}
	}
}

