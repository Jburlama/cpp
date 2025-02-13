#include "../headers/Form.hpp"

Form::Form()
:_name("Default"), _grade_required_to_sign(0), _grade_required_to_execute(0)
{
	this->_is_signed = false;
	return ;
}

Form::Form(std::string name, const int required, const int execute)
:_name(name), _grade_required_to_sign(required), _grade_required_to_execute(execute)
{
	if (getGradeRequiredToSign() < 1)
		throw Form::GradeTooHighException();
	else if (getGradeRequiredToSign() > 150)
		throw Form::GradeTooLowException();

	if (getGradeRequiredToExecute() < 1)
		throw Form::GradeTooHighException();
	else if (getGradeRequiredToExecute() > 150)
		throw Form::GradeTooLowException();

	this->_is_signed = false;
	return ;
}

Form::~Form() throw()
{
	return ;
}

std::string Form::getName() const
{
	return this->_name;
}

bool Form::getSigned() const
{
	return this->_is_signed;
}

int Form::getGradeRequiredToSign() const
{
	return this->_grade_required_to_sign;
}

int Form::getGradeRequiredToExecute() const
{
	return this->_grade_required_to_execute;
}

void Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() <= this->getGradeRequiredToSign())
		this->_is_signed = true;
	else
		throw Form::GradeTooLowException();
	return ;
}

std::ostream &operator<<(std::ostream &os, const Form &self)
{
	os << self.getName();
	os << ", form required grade to sign " << self.getGradeRequiredToSign();
	os << ", form required grade to execute " << self.getGradeRequiredToExecute();
	return (os);
}
