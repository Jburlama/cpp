#pragma once
#include <iostream>
#include <exception>
#include <string>
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"
#include "AForm.hpp"

class AForm;

class Bureaucrat
:public GradeTooHighException, public GradeTooLowException
{
	private:
		const std::string	_name;
		int					_grade;
		Bureaucrat();
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat() throw();
		std::string getName() const;
		int getGrade() const;
		void decrementGrade(int n);
		void incrementGrade(int n);
		void signForm(AForm *form);
		void executeForm(AForm const &form);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &self);
