#pragma once
#include <string>
#include <iostream>
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form: public GradeTooHighException, public GradeTooLowException
{
	private:
		const std::string	_name;
		bool 				_is_signed;
		const int			_grade_required_to_sign;
		const int			_grade_required_to_execute;
		Form();
	public:
		Form(std::string name, const int required, const int execute);
		~Form() throw();
		std::string	getName() const;
		bool		getSigned() const;
		int			getGradeRequiredToSign() const;
		int			getGradeRequiredToExecute() const;
		void		beSigned(Bureaucrat &b);
};

std::ostream &operator<<(std::ostream &os, const Form &self);

