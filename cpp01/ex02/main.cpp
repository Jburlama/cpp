#include <iostream>
#include <string>

int	main( void )
{
	std::string brain = "HI THIS IS BRAIN";

	std::string	*stringPTR = &brain;
	std::string	&stringREF = brain;

	std::cout << "string memory address: " << &brain << std::endl;
	std::cout << "stringPTR memory address: " << &stringPTR << std::endl;
	std::cout << "stringREF memory address: " << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << "string value: " << brain << std::endl;
	std::cout << "stringPTR value: " << stringPTR << std::endl;
	std::cout << "stringREF value: " << stringREF << std::endl;
}
