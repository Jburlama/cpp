#include "../includes/RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return 0;

	float result;

	try 
	{
		result = rpn(argv[1]);
		std::cout << result << "\n";
	}
	catch (std::logic_error &e)
	{
		std::cout << e.what() << "\n";
	}
}
