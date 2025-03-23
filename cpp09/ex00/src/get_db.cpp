#include "../includes/BitcoinExchange.hpp"

std::map<std::string, float> get_data(void)
{
	std::map<std::string, float>	map_data;
	std::string 					line;
	std::ifstream 					data("data.csv");

	if (!data.is_open())
		throw std::logic_error("Failed to open csv");

	std::string date;
	float 		exchange_rate;
	
	std::getline(data, line);
	while (std::getline(data, line))
	{
		date = line.substr(0, 10);
		exchange_rate = std::atof(line.substr(11).c_str());
		map_data[date] = exchange_rate;
	}

	data.close();
	return map_data;
}

void print_map(std::map<std::string, float> map_data)
{
	std::map<std::string, float>::iterator it;

	for (it = map_data.begin(); it != map_data.end(); it++)
		std::cout << it->first << " | " << it->second << "\n";
}
