#include "../PhoneBook/PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->_count = 0;
}

void PhoneBook::add(void)
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string number;
	std::string secret;

	do
	{
		std::cout << "First name: ";
		std::getline(std::cin, first_name);
		if (std::cin.eof())
				return ;
	} while(first_name.empty());

	do
	{
		std::cout << "Last name: ";
		std::getline(std::cin, last_name);
		if (std::cin.eof())
				return ;
	} while(last_name.empty());

	do
	{
		std::cout << "Nickname: ";
		std::getline(std::cin, nickname);
		if (std::cin.eof())
				return ;
	} while(nickname.empty());

	bool	is_all_number;
	do
	{
		is_all_number = true;
		std::cout << "Phone number: ";
		std::getline(std::cin, number);
		if (std::cin.eof())
				return ;
		for (unsigned long i = 0; i < number.length(); i++)
		{
			if (i == 0 && number.at(0) == '+')
				continue ;
			if (number.at(i) < '0' || number.at(i) > '9')
			{
				is_all_number = false;
				break ;
			}
		}
	} while (number.empty() || is_all_number == false);
	
	do
	{
		std::cout << "Darkest secreat: ";
		std::getline(std::cin , secret);
		if (std::cin.eof())
				return ;
	} while (secret.empty());
	
	if (this->_count == 8)
		this->_count = 7;

	this->_contacts[this->_count].set_first_name(first_name);
	this->_contacts[this->_count].set_last_name(last_name);
	this->_contacts[this->_count].set_nickname(nickname);
	this->_contacts[this->_count].set_number(number);
	this->_contacts[this->_count].set_secret(secret);

	this->_count++;
}

void PhoneBook::search(void)
{
	if (this->_count == 0)
	{
		std::cout << "Empty phonebook." << std::endl;
		return ;
	}

	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|index     ";
	std::cout << "|first name";
	std::cout << "|last name ";
	std::cout << "|nickname  |";
	std::cout << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;

	this->print_contacts();
	int	table_index = this->get_table_index();
	if (table_index == -1)
		return ;
	std::cout << std::endl;
	this->print_contact_info(table_index - 1);
	std::cout << std::endl;
}

void PhoneBook::print_contact_info(int index)
{
	std::cout << "First Name: " << this->_contacts[index].get_first_name() << std::endl;
	std::cout << "Last Name: " << this->_contacts[index].get_last_name() << std::endl;
	std::cout << "Nickname: " << this->_contacts[index].get_nickname() << std::endl;
	std::cout << "Phone Number: " << this->_contacts[index].get_number() << std::endl;
	std::cout << "Darkest Secret: " << this->_contacts[index].get_secret() << std::endl;
}

int PhoneBook::get_table_index(void)
{
	std::string user_input;
	bool		is_all_digit;
	while (42)
	{
		is_all_digit = true;
		std::cout << "SELECT INDEX: ";
		std::getline(std::cin, user_input);
		if (std::cin.eof())
				return (-1);
		for (unsigned long i = 0; i < user_input.length(); i++)
		{
			if (user_input.at(i) < '0' || user_input.at(i) > '9')
			{
				is_all_digit = false;
				break;
			}
		}
		if (is_all_digit && (std::atoi(user_input.c_str()) > 0 && std::atoi(user_input.c_str()) < this->_count + 1))
			break ;
	}
	return (std::atoi(user_input.c_str()));
}

void	PhoneBook::print_contacts(void)
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	for (int i = 0; i < this->_count; i++)
	{
		first_name = this->_contacts[i].get_first_name();
		last_name = this->_contacts[i].get_last_name();
		nickname = this->_contacts[i].get_nickname();
		std::cout << "|";
		std::cout << i + 1;
		std::cout << std::setw(10);
		std::cout << "|";

		if (first_name.length() <= 10)
		{
				std::cout << first_name;
				std::cout << std::setw(10 - first_name.length() + 1);
				std::cout << "|";
		}
		else
		{
				std::cout << first_name.substr(0,9) + '.';
				std::cout << "|";
		}
		if (last_name.length() <= 10)
		{
				std::cout << last_name;
				std::cout << std::setw(10 - last_name.length() + 1);
				std::cout << "|";
		}
		else
		{
				std::cout << last_name.substr(0,9) + '.';
				std::cout << "|";
		}
		if (nickname.length() <= 10)
		{
				std::cout << nickname;
				std::cout << std::setw(10 - nickname.length() + 1);
				std::cout << "|";
		}
		else
		{
				std::cout << nickname.substr(0,9) + '.';
				std::cout << "|";
		}
		std::cout << std::endl;
		std::cout << "|-------------------------------------------|" << std::endl;
	}
}
