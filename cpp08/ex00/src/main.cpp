#include "../includes/easyfind.hpp"

int main(void)
{
	{
	    std::vector<int> v;
	
		v.push_back(6);
		v.push_back(9);
		v.push_back(4);
		v.push_back(2);
	
		try {
			std::cout << *easyfind(v, 69) << "\n";
		}
		catch (const std::logic_error &e) {
			std::cerr << e.what() << "\n";
		}
	}
	{
	    std::list<int> l;
	
		l.push_back(6);
		l.push_back(9);
		l.push_back(4);
		l.push_back(2);
	
		try {
			std::cout << *easyfind(l, 6) << "\n";
		}
		catch (const std::logic_error &e) {
				std::cerr << e.what() << "\n";
		}
	}
}
