#include "../headers/Bureaucrat.hpp"

std::string Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

void Bureaucrat::decrementGrade(int n)
{
	if ((this->getGrade() + n) > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade += n;
}

void Bureaucrat::incrementGrade(int n)
{
	if ((this->getGrade() - n) < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade -= n;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
: _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
: _name(other.getName())
{
	this->_grade = other.getGrade();
}


Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this == &other)
		return *this;
	this->_grade = other.getGrade();
	return *this;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &self)
{
	os << self.getName() << ", bureaucrat grade " << self.getGrade();
	return (os);
}

Bureaucrat::~Bureaucrat() throw()
{
	return ;
}

void Bureaucrat::signForm(AForm *form)
{
	try
	{
		form->beSigned(*this);
	}
	catch (AForm::GradeTooLowException &e)
 	{
		std::cout << this->getName() << " couldn’t sign " << form->getName() << " because grade is too low\n";
	}
}

void Bureaucrat::executeForm(AForm const &form)
{
	if (!form.getSigned())
	{
		std::cerr << "Form " << form.getName() << " is not signed\n";
		return ;
	}
	form.execute(*this);
	std::cout << this->getName() << " executed " << form.getName() << "\n";
}
