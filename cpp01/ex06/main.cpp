#include "Harl.hpp"

int	main( int argc, char *argv[] )
{
	if (argc != 2)
	{
		std::cout << "Usage: ./harpFilter <level>" << std::endl;
		return (0);
	}
	
	std::string levels[4] = { "DEBUG",
							  "INFO",
							  "WARNING",
							  "ERROR"};
	Harl obj;
	int lvl = -1;
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == argv[1])
		{
			lvl = i;
			break ;
		}
	}

	switch (lvl)
	{
		case -1:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break ;
		case 0:
			std::cout << "[ " << levels[0] << " ]" << std::endl;
			obj.complain(levels[0]);
			std::cout << std::endl;
			__attribute__((fallthrough));
		case 1:
			std::cout << "[ " << levels[1] << " ]" << std::endl;
			obj.complain(levels[1]);
			std::cout << std::endl;
			__attribute__((fallthrough));
		case 2:
			std::cout << "[ " << levels[2] << " ]" << std::endl;
			obj.complain(levels[2]);
			std::cout << std::endl;
			__attribute__((fallthrough));
		case 3:
			std::cout << "[ " << levels[3] << " ]" << std::endl;
			obj.complain(levels[3]);
	}
}
