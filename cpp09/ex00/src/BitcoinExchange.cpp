#include "../includes/BitcoinExchange.hpp"

void exchange(std::map<Date, float> map_data, char *argv)
{
	std::string 					line;
	std::ifstream					input(argv);

	if (!input.is_open())
		throw std::logic_error("Error: could not open file.");

	Date 		date;
	Date 		lowest_date(2009, 01, 02);
	int			poss;
	float		value;

	std::getline(input, line);
	while (std::getline(input, line))
	{
		try
		{
			poss = line.find("|");
			if (poss == -1)
				throw std::logic_error("Error: bad input => " + line);
			date = get_date(line.substr(0, poss).c_str());
			if (date < lowest_date)
				throw std::logic_error("Error: Only have record since 2009-01-02");
			value = get_value(line.substr(++poss).c_str());
			display_results(map_data, date, value);
		}
		catch (std::logic_error &e)
		{
			std::cout << e.what() << "\n";
		}
	}

	input.close();
}

void display_results(std::map<Date, float> db, Date date, float value)
{
	Date zero_day(0,0,0);

	std::cout << date << " => ";
	std::cout << value << " = ";

	
	while (42)
	{
		try
		{
			std::cout << db.at(date) * value << "\n";
			break ;
		}
		catch (std::out_of_range &e)
		{
			--(date);
			if (date == zero_day)
				break ;
			continue;
		}
		std::cout << "\n";
	}
}

float get_value(std::string input_value)
{
	std::string 	units;
	std::string		decimal;
	int				poss;

	strtrim(input_value);

	poss = input_value.find_first_of('.');
	units = input_value.substr(0, poss);
	if (poss != -1)
		decimal = input_value.substr(++poss);
	else
		decimal = "0";

	int		start;
	int		sign;

	start = 0;
	sign = 1;

	while (units[start] == '-' || units[start] == '+')
	{
		if (units[start] == '-')
			sign = -sign;
		start++;
	}

	std::string::iterator it;

	for (it = units.begin() + start; it != units.end(); it++)
	{
		if (!std::isdigit(*it))
			throw std::logic_error("Error: not a float or integer");
	}
	for (it = decimal.begin(); it != decimal.end(); it++)
	{
		if (!std::isdigit(*it))
			throw std::logic_error("Error: not a float or integer");
	}

	float float_unit;
	float float_decimal;
	float total;

	float_unit = std::atof(units.c_str() + start);
	float_decimal = std::atof(decimal.c_str()) / pow(10, decimal.length());

	total = (float_unit + float_decimal) * sign;

	if (total < 0)
		throw std::logic_error("Error: not a possitive number");
	if (total > 1000)
		throw std::logic_error("Error: too large number");

	return total;
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

	float float_month, float_day;

	float_month = std::atoi(month.c_str());
	float_day = std::atoi(day.c_str());

	if (float_month < 0 || float_month > 12)
		throw std::logic_error("Error: bad input => " + input_date);
	if (float_day < 0 || float_day > 31)
		throw std::logic_error("Error: bad input => " + input_date);

	return Date(std::atoi(year.c_str()), float_month, float_day);
}

std::map<Date, float> get_data(void)
{
	std::map<Date, float>			map_data;
	std::string 					line;
	std::ifstream 					data("data.csv");

	if (!data.is_open())
		throw std::logic_error("Failed to open csv");

	std::string str_date;
	float 		exchange_rate;
	std::string	str_year;
	std::string	str_month;
	std::string	str_day;
	
	std::getline(data, line);
	while (std::getline(data, line))
	{
		str_date = line.substr(0, 10);
		exchange_rate = std::atof(line.substr(11).c_str());

		str_year = str_date.substr(0, 4);
		str_month = str_date.substr(5, 2);
		str_day = str_date.substr(8, 2);

		Date date(std::atoi(str_year.c_str()), std::atoi(str_month.c_str()), std::atoi(str_day.c_str()));
		map_data[date] = exchange_rate;

	}
	data.close();
	return map_data;
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
	os << date.year << "-";
	if (date.month < 10)
		os << "0" << date.month << "-";
	else
		os << date.month << "-";
	if (date.day < 10)
		os << "0" << date.day;
	else
		os << date.day;
	return os;
}

bool Date::operator<(const Date &other) const
{
	if (this->year < other.year)
		return true;
	if (this->year == other.year && this->month < other.month)
		return true;
	if (this->year == other.year && this->month == other.month && this->day < other.day)
		return true;
	return false;
}

bool Date::operator==(const Date &other) const
{
	if (this->year == other.year &&
		this->month == other.month &&
		this->day == other.day)
	{
		return true;
	}
	return false;
}

Date Date::operator--()
{

	if (this->day > 1)
	{
		--(this->day);
	}
	else if (this->day == 1 && this->month > 1)
	{
		this->day = 31;
		--(this->month);
	}
	else if (this->day == 1 && this->month == 1 && this->year > 1)
	{
		this->day = 31;
		this->month = 12;
		--(this->year);
	}

	return *this;
}

Date Date::operator--(int)
{
	Date copy(*this);

	if (this->day > 1)
	{
		--(this->day);
	}
	else if (this->day == 1 && this->month > 1)
	{
		this->day = 31;
		--(this->month);
	}
	else if (this->day == 1 && this->month == 1 && this->year > 1)
	{
		this->day = 31;
		this->month = 12;
		--(this->year);
	}

	return copy;
}
