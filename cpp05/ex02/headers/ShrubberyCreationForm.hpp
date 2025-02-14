#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm
:public AForm
{
	private:
		std::string _target;
		ShrubberyCreationForm();
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm &other);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm() throw() {};
		std::string getTarget() const;
		void	execute(Bureaucrat const &executor) const;
};
