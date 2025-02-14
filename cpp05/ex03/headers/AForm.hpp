#pragma once
#include <string>
#include <iostream>
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
:public GradeTooHighException, public GradeTooLowException
{
	private:
		const std::string	_name;
		bool 				_is_signed;
		const int			_grade_required_to_sign;
		const int			_grade_required_to_execute;
		AForm();
	public:
		AForm(std::string name, const int required, const int execute);
		AForm(AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm() throw() {};
		std::string			getName() const;
		bool				getSigned() const;
		int					getGradeRequiredToSign() const;
		int					getGradeRequiredToExecute() const;
		void				beSigned(Bureaucrat &b);
		virtual void		execute(Bureaucrat const &executor) const = 0;
};

std::ostream &operator<<(std::ostream &os, const AForm &self);

