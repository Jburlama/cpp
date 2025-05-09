#pragma once
#include <cmath>
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <ctime>

class PmergeMe
{
	private:
		std::list<int>		_list;
		int					_list_size;
		std::vector<int>	_vector;
		int					_vector_size;

	public:
		void 	argtolist(char **argv);
		void 	argtovector(char **argv);
		void 	print_list(void);
		void 	print_vector(void);
		void 	sort_list(int order);
		void 	sort_vector(int order);
		size_t	get_jacobsthal(size_t index);

		int							get_vector_size(void);
		int							get_list_size(void);
		std::vector<int>::iterator	get_vector_begin(void);
		std::list<int>::iterator	get_list_begin(void);
		std::vector<int>::iterator	get_vector_end(void);
		std::list<int>::iterator	get_list_end(void);

		PmergeMe();
		PmergeMe(PmergeMe &other);
		PmergeMe &operator=(PmergeMe &other);
		~PmergeMe(){};
};
