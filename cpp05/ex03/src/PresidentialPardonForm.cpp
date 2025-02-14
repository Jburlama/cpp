#include "../headers/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: AForm("PresidentialPardonForm", 25, 5)
{
	this->_target = target;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &other)
: AForm("PresidentialPardonForm", 25, 5)
{
	this->_target = other.getTarget();
	return ;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this == &other)
		return *this;
	this->_target = other.getTarget();
	return *this;
}

std::string PresidentialPardonForm::getTarget() const
{
	return this->_target;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
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
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox\n";
}
