#include "../includes/MutantStack.hpp"
#include <list>

int main(void)
{
	std::cout << "Test 1 ------------------------------------\n";
	{
		MutantStack<int> my_stack;
	
		my_stack.push(69);
		my_stack.push(6);
		my_stack.push(9);
		
		
		MutantStack<int>::iterator begin = my_stack.begin();
		MutantStack<int>::iterator end = my_stack.end();
	
		std::cout << "begin of the Stack: ";
		std::cout << *begin << "\n";
		std::cout << "end of the Stack: ";
		std::cout << *(--end) << "\n";
		std::cout << "\n";
		++end;
	
		std::cout << "Iterating over the Stack: ";
		for (MutantStack<int>::iterator it = begin; it != end; it++)
			std::cout << *it << ", ";
		std::cout << "\n";
	
		begin++;
		*begin = 42;
		begin--;
		std::cout << "Iterating over changed the Stack: ";
		for (MutantStack<int>::iterator it = begin; it != end; it++)
			std::cout << *it << ", ";
		std::cout << "\n";

	}
	std::cout << "\n";
	std::cout << "Test 2 ------------------------------------\n";
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	std::cout << "\n";
	std::cout << "Test 3 ------------------------------------\n";
	{
		std::list<int> mstack;

		mstack.push_back(5);
		mstack.push_back(17);

		std::cout << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;

		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);

		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(mstack);
	}
	std::cout << "\n";
	std::cout << "Test 4 ------------------------------------\n";
	{
		MutantStack<int> my_stack;
	
		my_stack.push(69);
		my_stack.push(6);
		my_stack.push(9);
		MutantStack<int> my_stack2(my_stack);

		std::cout << "Iterating over changed the Stack 2: ";
		for (MutantStack<int>::iterator it = my_stack2.begin(); it != my_stack2.end(); it++)
			std::cout << *it << ", ";
		std::cout << "\n";

		MutantStack<int> my_stack3;

		my_stack3 = my_stack;
	
		std::cout << "Iterating over changed the Stack 3: ";
		for (MutantStack<int>::iterator it = my_stack3.begin(); it != my_stack3.end(); it++)
			std::cout << *it << ", ";
		std::cout << "\n";
	}
}
