#include "../includes/BitcoinExchange.hpp"

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
