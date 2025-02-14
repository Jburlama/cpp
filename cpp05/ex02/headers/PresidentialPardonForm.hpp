#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include "AForm.hpp"

class PresidentialPardonForm
: public AForm
{
	private:
		std::string _target;
		PresidentialPardonForm();
	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm &other);
		PresidentialPardonForm&operator=(const PresidentialPardonForm &other);
		~PresidentialPardonForm() throw() {};
		std::string getTarget() const;
		void	execute(Bureaucrat const &executor) const;
};
