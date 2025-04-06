#include "../includes/PmergeMe.hpp"

// Each pair has order elements in it
void	PmergeMe::sort_list(int order)
{
	std::list<int>::iterator	first;
	std::list<int>::iterator	second;
	std::list<int>::iterator	temp;

	// Break case when it can't form anymore pairs
	if (order > this->_list_size / 2)
		return ;

	// Points first and second to the last element of each pair
	first = this->_list.begin();
	std::advance(first, order - 1);
	second = first;
	std::advance(second, order);
	
	
	// Iterates over the list and swap the pairs if necessary
	while (first != this->_list.end() && second != this->_list.end())
	{
		temp = second;
		if (*second < *first)
		{
			std::swap(*first, *second);
			for (int i = 1; i < order; ++i)
			{
				--first;
				--second;
				std::swap(*first, *second);
			}
		}
		first = temp;
		second = first;
		for (int i = 0; i < order && second != this->_list.end(); ++i)
			++second;
		for (int i = 0; i < order && second != this->_list.end(); ++i)
		{
			++first;
			++second;
		}
	}

	sort_list(order * 2); // Recursivily order pairs
	
	std::vector<int>								main;
	std::vector<int>::iterator 						main_it;
	std::vector<int>::iterator 						bound;
	std::list<int>::iterator	 					list_it;
	std::list<int>::iterator						non_participant;
	std::vector<std::list<int>::iterator>			pend;
	std::vector<std::list<int>::iterator>::iterator	pend_it;
	size_t											possible_pairs;
	size_t											inserted_pairs;

	main.reserve(this->_list_size);
	possible_pairs = this->_list_size / (order * 2);

	// Inicialize the main chain
	list_it = this->_list.begin();
	for (int i = 0; i < order; ++i)
		main.push_back(*list_it++);
	for (int i = 0; i < order; ++i)
		main.push_back(*list_it++);
	inserted_pairs = 1;

	// Insert the rest of the pend and main
	while (inserted_pairs < possible_pairs && list_it != this->_list.end())
	{
		std::advance(list_it, order - 1);
		pend.insert(pend.end(), list_it);
		++list_it;
		for (int i = 0; i < order; ++i)
			main.push_back(*list_it++);
		++inserted_pairs;
	}

	// If there is elements left add to pend
	int	elements_inserted;
	int	elements_left;

	elements_inserted = order * 2 * inserted_pairs;
	elements_left = this->_list_size - elements_inserted;
	if (elements_left >= order)
	{
		std::advance(list_it, order - 1);
		pend.insert(pend.end(), list_it);
		list_it++;
	}

	// Elements not participanting, will point to list.end() if all are
	non_participant = list_it;

	int	previous_jacobsthal;
	int current_jacobsthal;
	int	jacobsthal_index;
	int	jacobsthal_diff;
	int	bond_indx;
	int	pend_size;

	previous_jacobsthal = get_jacobsthal(1);
	current_jacobsthal = get_jacobsthal(2);
	jacobsthal_index = 2;
	elements_inserted = order * 2;
	jacobsthal_diff = current_jacobsthal - previous_jacobsthal;
	pend_size = static_cast<int>(pend.size());

	while (pend_size >= jacobsthal_diff)
	{
		while (jacobsthal_diff)
		{

			pend_it = pend.begin() + jacobsthal_diff - 1;
			bond_indx = current_jacobsthal + elements_inserted + 1;
			if (bond_indx % order)
				bond_indx += bond_indx % order;
			if (bond_indx < static_cast<int>(main.size()))
				bound = main.begin() + bond_indx - 1;
			else
				bound = main.end() - 1;
			main_it = bound;
			if (*main_it < *(*pend_it))
				main_it = main.end() - 1;
			while (main_it != main.begin() && *main_it > *(*pend_it))
			{
				for (int i = 0; i < order && main_it != main.begin(); ++i)
					--main_it;
			}
			if (main_it != main.begin() && main_it != main.end() && *(*pend_it) >= *main_it)
				++main_it;
			if (main_it == main.begin() && order == 1 && *(*pend_it) >= *main_it)
				++main_it;
			for (int i = 0; i < order; ++i)
	 		{
				main_it = main.insert(main_it, *(*pend_it));
				if (order != 1)
					std::advance(*pend_it, -1);
			}
			pend_it = pend.erase(pend_it);
			--pend_size;
			--jacobsthal_diff;
			elements_inserted += order;
		}
		previous_jacobsthal = current_jacobsthal;
		current_jacobsthal = get_jacobsthal(++jacobsthal_index);
		jacobsthal_diff = current_jacobsthal - previous_jacobsthal;
	}

	// Add the rest of The pend to main
	while (pend_size != 0)
	{
		main_it = main.end() - 1;
		pend_it = pend.begin();

		
		while (main_it != main.begin() && *main_it > *(*pend_it))
		{
			for (int i = 0; i < order && main_it != main.begin(); ++i)
				--main_it;
		}
		if (main_it != main.begin() && *(*pend_it) >= *main_it)
			++main_it;
		if (main_it == main.begin() && *(*pend_it) >= *main_it && order == 1)
			++main_it;
		for (int i = 0; i < order; ++i)
 		{
			main_it = main.insert(main_it, *(*pend_it));
			if (order != 1)
				std::advance(*pend_it, -1);
		}
		pend_it = pend.erase(pend_it);
		--pend_size;
	}

	// Adding the non participant elements to main
	while (non_participant != this->_list.end())
	{
		main.insert(main.end(), *non_participant);
		++non_participant;
	}


	// Copy from main to list
	list_it = this->_list.begin();
	main_it = main.begin();
	while (list_it != this->_list.end() && main_it != main.end())
	{
		*list_it = *main_it;
		++list_it;
		++main_it;
	}
}

// Each pair has order elements in it
void	PmergeMe::sort_vector(int order)
{
	std::vector<int>::iterator	first;
	std::vector<int>::iterator	second;
	std::vector<int>::iterator	temp;

	// Break case when it can't form anymore pairs
	if (order > this->_vector_size / 2)
		return ;

	// Points first and second to the last element of each pair
	first = this->_vector.begin();
	std::advance(first, order - 1);
	second = first;
	std::advance(second, order);
	
	
	// Iterates over the list and swap the pairs if necessary
	while (first != this->_vector.end() && second != this->_vector.end())
	{
		temp = second;
		if (*second < *first)
		{
			std::swap(*first, *second);
			for (int i = 1; i < order; ++i)
			{
				--first;
				--second;
				std::swap(*first, *second);
			}
		}
		first = temp;
		second = first;
		for (int i = 0; i < order && second != this->_vector.end(); ++i)
			++second;
		for (int i = 0; i < order && second != this->_vector.end(); ++i)
		{
			++first;
			++second;
		}
	}

	sort_vector(order * 2); // Recursivily order pairs
	
	std::vector<int>									main;
	std::vector<int>::iterator 							main_it;
	std::vector<int>::iterator 							bound;
	std::vector<int>::iterator	 						list_it;
	std::vector<int>::iterator							non_participant;
	std::vector<std::vector<int>::iterator>	 			pend;
	std::vector<std::vector<int>::iterator>::iterator	pend_it;
	size_t												possible_pairs;
	size_t												inserted_pairs;

	main.reserve(this->_vector_size);
	possible_pairs = this->_vector_size / (order * 2);

	// Inicialize the main chain
	list_it = this->_vector.begin();
	for (int i = 0; i < order; ++i)
		main.push_back(*list_it++);
	for (int i = 0; i < order; ++i)
		main.push_back(*list_it++);
	inserted_pairs = 1;

	// Insert the rest of the pend and main
	while (inserted_pairs < possible_pairs && list_it != this->_vector.end())
	{
		std::advance(list_it, order - 1);
		pend.insert(pend.end(), list_it);
		++list_it;
		for (int i = 0; i < order; ++i)
			main.push_back(*list_it++);
		++inserted_pairs;
	}

	// If there is elements left add to pend
	int	elements_inserted;
	int	elements_left;

	elements_inserted = order * 2 * inserted_pairs;
	elements_left = this->_vector_size - elements_inserted;
	if (elements_left >= order)
	{
		std::advance(list_it, order - 1);
		pend.insert(pend.end(), list_it);
		list_it++;
	}

	// Elements not participanting, will point to list.end() if all are
	non_participant = list_it;

	int	previous_jacobsthal;
	int current_jacobsthal;
	int	jacobsthal_index;
	int	jacobsthal_diff;
	int	bond_indx;
	int	pend_size;

	previous_jacobsthal = get_jacobsthal(1);
	current_jacobsthal = get_jacobsthal(2);
	jacobsthal_index = 2;
	elements_inserted = order * 2;
	jacobsthal_diff = current_jacobsthal - previous_jacobsthal;
	pend_size = static_cast<int>(pend.size());

	while (pend_size >= jacobsthal_diff)
	{
		while (jacobsthal_diff)
		{

			pend_it = pend.begin() + jacobsthal_diff - 1;
			bond_indx = current_jacobsthal + elements_inserted + 1;
			if (bond_indx % order)
				bond_indx += bond_indx % order;
			if (bond_indx < static_cast<int>(main.size()))
				bound = main.begin() + bond_indx - 1;
			else
				bound = main.end() - 1;
			main_it = bound;
			if (*main_it < *(*pend_it))
				main_it = main.end() - 1;
			while (main_it != main.begin() && *main_it > *(*pend_it))
			{
				for (int i = 0; i < order && main_it != main.begin(); ++i)
					--main_it;
			}
			if (main_it != main.begin() && main_it != main.end() && *(*pend_it) >= *main_it)
				++main_it;
			if (main_it == main.begin() && order == 1 && *(*pend_it) >= *main_it)
				++main_it;
			for (int i = 0; i < order; ++i)
	 		{
				main_it = main.insert(main_it, *(*pend_it));
				if (order != 1)
					std::advance(*pend_it, -1);
			}
			pend_it = pend.erase(pend_it);
			--pend_size;
			--jacobsthal_diff;
			elements_inserted += order;
		}
		previous_jacobsthal = current_jacobsthal;
		current_jacobsthal = get_jacobsthal(++jacobsthal_index);
		jacobsthal_diff = current_jacobsthal - previous_jacobsthal;
	}

	// Add the rest of The pend to main
	while (pend_size != 0)
	{
		main_it = main.end() - 1;
		pend_it = pend.begin();

		
		while (main_it != main.begin() && *main_it > *(*pend_it))
		{
			for (int i = 0; i < order && main_it != main.begin(); ++i)
				--main_it;
		}
		if (main_it != main.begin() && *(*pend_it) >= *main_it)
			++main_it;
		if (main_it == main.begin() && *(*pend_it) >= *main_it && order == 1)
			++main_it;
		for (int i = 0; i < order; ++i)
 		{
			main_it = main.insert(main_it, *(*pend_it));
			if (order != 1)
				std::advance(*pend_it, -1);
		}
		pend_it = pend.erase(pend_it);
		--pend_size;
	}

	// Adding the non participant elements to main
	while (non_participant != this->_vector.end())
	{
		main.insert(main.end(), *non_participant);
		++non_participant;
	}


	// Copy from main to list
	list_it = this->_vector.begin();
	main_it = main.begin();
	while (list_it != this->_vector.end() && main_it != main.end())
	{
		*list_it = *main_it;
		++list_it;
		++main_it;
	}
}

size_t	PmergeMe::get_jacobsthal(size_t index)
{
	return (std::pow(2, index + 1) + std::pow(-1, index)) / 3;
}

void PmergeMe::argtolist(char **argv)
{
	size_t nbr;

	nbr = 0;
	for (int i = 1; argv[i]; ++i)
	{
		for (int j = 0; argv[i][j]; ++j)
		{
			while (argv[i][j] && argv[i][j] == ' ')
				++j;
			if (!argv[i][j])
				break ;
			while (isdigit(argv[i][j]))
				nbr = nbr * 10 + argv[i][j++] - '0';
			if (argv[i][j] && argv[i][j] != ' ' && !isdigit(argv[i][j]))
				throw std::logic_error(std::string("Not a digit: ").append(1, argv[i][j]));
			this->_list.push_back(nbr);
			nbr = 0;
			if (!argv[i][j])
				break ;
		}
	}
	this->_list_size = static_cast<int>(this->_list.size());
}

void PmergeMe::argtovector(char **argv)
{
	size_t nbr;

	nbr = 0;
	for (int i = 1; argv[i]; ++i)
	{
		for (int j = 0; argv[i][j]; ++j)
		{
			while (argv[i][j] && argv[i][j] == ' ')
				++j;
			if (!argv[i][j])
				break ;
			while (isdigit(argv[i][j]))
				nbr = nbr * 10 + argv[i][j++] - '0';
			if (argv[i][j] && argv[i][j] != ' ')
				throw std::logic_error(std::string("Not a digit: ").append(1, argv[i][j]));
			this->_vector.push_back(nbr);
			nbr = 0;
			if (!argv[i][j])
				break ;
		}
	}
	this->_vector_size = static_cast<int>(this->_vector.size());
}

void PmergeMe::print_list(void)
{
	for (std::list<int>::iterator it = this->_list.begin(); it != this->_list.end(); ++it)
		std::cout << *it << " ";
	std::cout << "\n";
}

void PmergeMe::print_vector(void)
{
	for (std::vector<int>::iterator it = this->_vector.begin(); it != this->_vector.end(); ++it)
		std::cout << *it << " ";
	std::cout << "\n";
}

int	PmergeMe::get_list_size(void)
{
	return this->_list_size;
}

int	PmergeMe::get_vector_size(void)
{
	return this->_vector_size;
}
