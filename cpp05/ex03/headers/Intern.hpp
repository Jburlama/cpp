#include <iostream>
#include <string>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	private:
		AForm *createPresidentialPardonForm(std::string target);
		AForm *createRobotomyRequestForm(std::string target);
		AForm *createShrubberyCreationForm(std::string target);
	public:
		AForm *makeForm(std::string form, std::string target);
};
