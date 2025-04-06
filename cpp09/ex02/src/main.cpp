#include "../includes/PmergeMe.hpp"

// ./PmergeMe `shuf -i 1-100 -n 10 | tr "\n" " "`
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
		obj.argtovector(argv);
		std::clock_t list_start;
		std::clock_t vector_start;
		std::clock_t list_end;
		std::clock_t vector_end;
	
		std::cout << "Before: ";
		obj.print_list();
		
		list_start = std::clock();
		if (list_start == -1)
			throw std::logic_error("processor time used is not available");
		obj.sort_list(1);
		list_end = std::clock();
	
		vector_start = std::clock();
		if (vector_start == -1)
			throw std::logic_error("processor time used is not available");
		obj.sort_vector(1);
		vector_end = std::clock();
	
		std::cout << "After: ";
		obj.print_list();
	
		std::cout << "Time to process a range of " << obj.get_list_size() <<" elements with std::list : " << 1000.0 * (list_end - list_start) / CLOCKS_PER_SEC << " ms\n";
		std::cout << "Time to process a range of " << obj.get_vector_size() << " elements with std::vector : " << 1000.0 * (vector_end - vector_start) / CLOCKS_PER_SEC << " ms\n";
	
	}
	catch (std::logic_error &e)
	{
		std::cerr << e.what() << "\n";
	}
	
}
