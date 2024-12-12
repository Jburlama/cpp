#include "Contact.hpp"
#include <iostream>
#include <string>

void Contact::set_first_name(std::string name)
{
	this->_first_name = name;
}

void Contact::set_last_name(std::string name)
{
	this->_last_name = name;
}

void Contact::set_nickname(std::string nickname)
{
	this->_nickname = nickname;
}

void Contact::set_number(std::string number)
{
	this->_number = number;
}

void Contact::set_secret(std::string secrete)
{
	this->_darkest_secret = secrete;
}

std::string Contact::get_first_name()
{
	return (_first_name);
}

std::string Contact::get_last_name()
{
	return (_last_name);
}

std::string Contact::get_nickname()
{
	return (_nickname);
}

std::string Contact::get_number()
{
	return (_number);
}


std::string Contact::get_secret()
{
	return (_darkest_secret);
}
