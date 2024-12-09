#include "../PhoneBook/PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->_count = 0;
}

void PhoneBook::add(void)
{
	std::string first_name;
	std::string last_name;
	std::string number;
	std::string secret;

	std::cout << "First name: ";
	std::cin >> first_name;
	std::cout << "Last name: ";
	std::cin >> last_name;
	std::cout << "Phone number: ";
	std::cin >> number;
	std::cout << "Darkest secreat: ";
	std::cin >> secret;

	if (this->_count < 8)
		(this->_count)++;
	int i = 0;
	while (i < this->_count - 1)
		i++;

	this->_contacts[i].set_first_name(first_name);
	this->_contacts[i].set_last_name(last_name);
	this->_contacts[i].set_number(number);
	this->_contacts[i].set_secret(secret);
}
