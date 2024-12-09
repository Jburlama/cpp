#include "../headers/PhoneBook/PhoneBook.hpp"

int	main(void)
{
	PhoneBook phonebook;
	std::string input;

	while (42)
	{
		std::cout << "select: ADD, SEARCH or EXIT" << std::endl;
		do
		{
			std::cout << ">> ";
	 		std::getline(std::cin, input);
			if (std::cin.eof())
				return (0);
		}  while (input.empty());
		if (input == "EXIT\0") 
			return (0);
		else if (input == "ADD\0")
			phonebook.add();
		else if (input == "SEARCH\0")
			phonebook.search();
		if (std::cin.eof())
			return (0);
	}
}
