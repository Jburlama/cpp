#include "../includes/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	(void)argc;
	std::map<Date, float> map_data;

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
