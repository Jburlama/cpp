#include "../headers/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: AForm("RobotomyRequestForm", 72, 45)
{
	this->_target = target;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &other)
: AForm("RobotomyRequestForm", 72, 45)
{
	this->_target = other.getTarget();
	return ;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this == &other)
		return *this;
	this->_target = other.getTarget();
	return *this;
}

std::string RobotomyRequestForm::getTarget() const
{
	return this->_target;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	srand(time(0));


	if (!this->getSigned())
	{
		std::cout << "Form " << this->getName() << " is not signed\n";
		return ;
	}
	if (executor.getGrade() > this->getGradeRequiredToExecute())
	{
		std::cout << "Grade from " << executor.getName() << " to low to execute " << this->getName() << "\n";
		throw AForm::GradeTooLowException();
	}
	if (rand() % 2)
	{
		std::cout << this->getTarget() << " has been robotomized successfully\n";
		return ;
	}
	std::cout << "robotomy failed\n";
}
