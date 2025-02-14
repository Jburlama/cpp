#include "../headers/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: AForm("shrubberycreationform", 145, 137)
{
	this->_target = target;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &other)
: AForm("shrubberycreationform", 145, 137)
{
	this->_target = other.getTarget();
	return ;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this == &other)
		return *this;
	this->_target = other.getTarget();
	return *this;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return this->_target;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	int tree_size;
	int line;
	int trunk_size;
	int trunk_len;
	int current_trunk_len;
	std::string file_name;

	if (!this->getSigned())
	{
		std::cout << "Form cannot be executed because is not signed\n";
		return ;
	}
	if (executor.getGrade() > this->getGradeRequiredToExecute())
	{
		std::cout << "Grade from " << executor.getName() << " to low to execute " << this->getName() << "\n";
		throw AForm::GradeTooLowException();
	}
	file_name = this->getTarget() + "_shrubbery";
	std::ofstream File(file_name.c_str());
	tree_size = 50;
	trunk_size = 5;
	trunk_len = 5;
	current_trunk_len = 0;
	for (int i = 0; i < tree_size; i++)
	{
		line = 0;
		while (line++ < tree_size / 2)
			File << " ";
		line = 0;
		if (i >= tree_size / 2)
		{
			while (line++ < (tree_size / 2) - trunk_len)
				File << " ";
			while (line++ < (tree_size / 2) + trunk_len)
				File << "|";
			File << "\n";
			if (trunk_size == current_trunk_len)
				break ;
			current_trunk_len++;
			continue ;
		}
		while (line++ < tree_size / 2 - i)
			File << " ";
		while (line++ < tree_size / 2 + i)
			File << "@";
		File << "\n";
	}
	File.close();
	return ;
}
