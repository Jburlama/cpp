#include "../includes/PmergeMe.hpp"

// ./PmergeMe `shuf -i 1-100 -n 10 | tr "\n" " "`
// ./PmergeMe 2 3 80 1 0 100 1 3
// ./PmergeMe 6 97 31 70 27 8 19 20 62 83 86 12 38 73 58 71 1 74 36 23 11 88 56 42 26 29 77 9 72 49 34 99 91 69 14 40 41 80 46 33 63 84 25 5 94 55 95 15 21 35
// ./PmergeMe 87 7 99 42 39 38 44 47 57 18 40 85 17 25 70 43 81 6 52 41 66 21 68 11 23 83 75 69 31 49 28 65 95 56 5 78

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Insert Possitive numbers\n";
		return 1;
	}

	PmergeMe obj;

	try
	{
		obj.argtolist(argv);

		std::cout << "List        : ";
		obj.print_list();

		std::cout << "\n";
		obj.sort_list(1);

		std::cout << "\n";
		std::cout << "List ordered: ";
		obj.print_list();

		std::cout << "\n";

/*
		std::cout << "Vector        : ";
		obj.argtovector(argv);
		obj.print_vector();

		obj.sort_vector(1);
		std::cout << "Vector ordered: ";
		obj.print_vector();
*/

	}
	catch (std::logic_error &e)
	{
		std::cerr << e.what() << "\n";
	}
}
