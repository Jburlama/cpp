#include "../includes/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Please input one text file\n";
		return 1;
	}

	std::map<std::string, float> map_data;

	try
	{
		map_data = get_data();
		exchange(map_data, argv[1]);
	}
	catch (const std::logic_error &e)
	{
		std::cerr << e.what() << "\n";
		return 1;
	}
	return 0;
}
