#include "../headers/PhoneBook/PhoneBook.hpp"

int	main(void)
{
	PhoneBook phonebook;
	std::string input;

	while (42)
	{
		std::cout << "select: ADD, SEARCH or EXIT\n>> ";
		std::cin >> input;
		if (input == "EXIT")
			return (0);
		else if (input == "ADD")
		{
			phonebook.add();
		}
	}
}
