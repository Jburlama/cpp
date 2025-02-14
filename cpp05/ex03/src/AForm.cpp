#include "../headers/AForm.hpp"

AForm::AForm()
:_name("Default"), _grade_required_to_sign(0), _grade_required_to_execute(0)
{
	this->_is_signed = false;
	return ;
}

AForm::AForm(AForm &other)
:_name(other.getName()), _grade_required_to_sign(other.getGradeRequiredToSign()), _grade_required_to_execute(other.getGradeRequiredToExecute())
{
	this->_is_signed = other.getSigned();
	return ;
}

AForm &AForm::operator=(const AForm &other)
{
	if (this == &other)
		return *this;
	this->_is_signed = other.getSigned();
	return *this;
}


AForm::AForm(std::string name, const int required, const int execute)
:_name(name), _grade_required_to_sign(required), _grade_required_to_execute(execute)
{
	if (this->getGradeRequiredToSign() < 1)
		throw AForm::GradeTooHighException();
	else if (this->getGradeRequiredToSign() > 150)
		throw AForm::GradeTooLowException();

	if (this->getGradeRequiredToExecute() < 1)
		throw AForm::GradeTooHighException();
	else if (this->getGradeRequiredToExecute() > 150)
		throw AForm::GradeTooLowException();

	this->_is_signed = false;
	return ;
}


std::string AForm::getName() const
{
	return this->_name;
}

bool AForm::getSigned() const
{
	return this->_is_signed;
}

int AForm::getGradeRequiredToSign() const
{
	return this->_grade_required_to_sign;
}

int AForm::getGradeRequiredToExecute() const
{
	return this->_grade_required_to_execute;
}


void AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() <= this->getGradeRequiredToSign())
	{
		this->_is_signed = true;
	}
	else
		throw AForm::GradeTooLowException();
	return ;
}

std::ostream &operator<<(std::ostream &os, const AForm &self)
{
	os << self.getName();
	os << ", form required grade to sign " << self.getGradeRequiredToSign();
	os << ", form required grade to execute " << self.getGradeRequiredToExecute();
	return (os);
}
