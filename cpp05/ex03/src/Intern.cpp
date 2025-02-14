#include "../headers/Intern.hpp"

AForm *Intern::createPresidentialPardonForm(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::createRobotomyRequestForm(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::createShrubberyCreationForm(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(std::string form, std::string target)
{
	std::string	forms[3] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};

	AForm *(Intern::*create_forms[3])(std::string) = {
		&Intern::createPresidentialPardonForm,
		&Intern::createRobotomyRequestForm,
		&Intern::createShrubberyCreationForm
	};


	for (int i = 0; i < 3; i++)
	{
		if (form == forms[i])
		{
			std::cout << "Intern creates " << form << "\n";
			return (this->*create_forms[i])(target);
		}
	}
	return NULL;
}
