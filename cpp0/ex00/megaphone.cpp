#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}

	std::string message;

	for (int i = 1; i < argc; i++)
		message.append(argv[i]);

	for (long unsigned int i = 0; i < message.length(); i++)
	{
		if (message[i] <= 'z' && message[i] >= 'a')
			message[i] -= ('a' - 'A');
	}

	std::cout << message << std::endl;
}
