#include "../PhoneBook/PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->_count = 0;
	memset(_have, false, sizeof(_have));
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

	do
	{
		std::cout << "Phone number: ";
		std::getline(std::cin, number);
		if (std::cin.eof())
				return ;
	} while (number.empty());
	
	do
	{
		std::cout << "Darkest secreat: ";
		std::getline(std::cin , secret);
		if (std::cin.eof())
				return ;
	} while (secret.empty());

	int i = 0;
	while (i < 8)
	{
		if (this->_have[i] == false)
		{
			this->_have[i] = true;
			break ;
		}
		i++;
	}
	if (i == 8)
		i = 7;
	this->_contacts[i].set_first_name(first_name);
	this->_contacts[i].set_last_name(last_name);
	this->_contacts[i].set_nickname(nickname);
	this->_contacts[i].set_number(number);
	this->_contacts[i].set_secret(secret);
}

void PhoneBook::search(void)
{
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|index     ";
	std::cout << "|first name";
	std::cout << "|last name ";
	std::cout << "|nickname  |";
	std::cout << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;

	std::string first_name;
	std::string last_name;
	std::string nickname;
	int index = 1;
	for (int i = 0; i < 8; i++)
	{
		if (this->_have[i] == true)
		{
			first_name = this->_contacts[i].get_first_name();
			last_name = this->_contacts[i].get_last_name();
			nickname = this->_contacts[i].get_nickname();
			std::cout << "|";
			std::cout << index;
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
			index++;
		}
	}

	bool		is_all_digit;
	std::string user_input;
	while (42)
	{
		is_all_digit = true;
		std::cout << "SELECT INDEX: ";
		std::getline(std::cin, user_input);
		if (std::cin.eof())
				return ;
		for (unsigned long i = 0; i < user_input.length(); i++)
		{
			if (user_input.at(i) < '0' || user_input.at(i) > '9')
			{
				is_all_digit = false;
				break;
			}
		}
		if (is_all_digit && (std::atoi(user_input.c_str()) > 0 && std::atoi(user_input.c_str()) < index))
			break;
	}
}
