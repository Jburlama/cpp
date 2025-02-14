#pragma once
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include "AForm.hpp"

class RobotomyRequestForm
: public AForm
{
	private:
		std::string _target;
		RobotomyRequestForm();
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm &other);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
		~RobotomyRequestForm() throw() {};
		std::string getTarget() const;
		void	execute(Bureaucrat const &executor) const;
};
