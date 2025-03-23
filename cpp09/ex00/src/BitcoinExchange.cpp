#include "../includes/BitcoinExchange.hpp"

void exchange(std::map<std::string, float> map_data, char *argv)
{
	(void) map_data;
	std::map<std::string, float>	map_input;
	std::string 					line;
	std::ifstream					input(argv);

	if (!input.is_open())
		throw std::logic_error("Failed to open input");

	Date 		date;
	int			poss;

	std::getline(input, line);
	while (std::getline(input, line))
	{
		poss = line.find("|");
		try
		{
			date = get_date(line.substr(0, poss).c_str());
			std::cout << date << "\n";
		}
		catch (std::logic_error &e)
		{
			std::cout << e.what() << "\n";
		}
		break ;
	}

	input.close();
}

Date get_date(std::string input_date)
{
	std::string year, month, day;
	int poss, len;

	strtrim(input_date);

	poss = input_date.find_first_of('-');
	if (poss == -1)
		throw std::logic_error("Error: bad input => " + input_date);
	year = input_date.substr(0, poss);

	poss = input_date.find_first_of('-', ++poss);
	if (poss == -1)
		throw std::logic_error("Error: bad input => " + input_date);

	len = year.length();

	month = input_date.substr(len + 1, poss - len - 1);
	day = input_date.substr(++poss);
	
	if (0 == year.length())
		throw std::logic_error("Error: bad input => " + input_date);
	if (0 == month.length() || month.length() > 2)
		throw std::logic_error("Error: bad input => " + input_date);
	if (0 == day.length() || day.length() > 2)
		throw std::logic_error("Error: bad input => " + input_date);
		
	std::string::iterator it;

	for (it = year.begin(); it != year.end(); it++)
	{
		if (!std::isdigit(*it))
			throw std::logic_error("Error: bad input => " + input_date);
	}
	for (it = month.begin(); it != month.end(); it++)
	{
		if (!std::isdigit(*it))
			throw std::logic_error("Error: bad input => " + input_date);
	}
	for (it = day.begin(); it != day.end(); it++)
	{
		if (!std::isdigit(*it))
			throw std::logic_error("Error: bad input => " + input_date);
	}

	return Date(std::atoi(year.c_str()), std::atoi(month.c_str()), std::atoi(day.c_str()));
}

void strtrim(std::string &input_date)
{
	int poss;
	int len;

	poss = 0;
	while (std::isspace(input_date[poss]))
		poss++;
	input_date = input_date.erase(0, poss);
	len = input_date.length();
	poss = len - 1;
	while (std::isspace(input_date[poss]))
		poss--;
	input_date = input_date.erase(poss + 1, len);
}

std::ostream &operator<<(std::ostream &os, const Date &date)
{
	os << date.year << "-" << date.month << "-" << date.day;
	return os;
}

