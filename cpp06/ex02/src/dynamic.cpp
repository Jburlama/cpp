#include "../headers/dynamic.hpp"

Base *generate(void)
{
	srand(time(0));  
	int rng;

	rng = rand() % 3;

	if (rng == 0)
	{
		std::cout << "Generated A\n";
		return new A;
	}
	else if (rng == 1)
	{
		std::cout << "Generated B\n";
		return new B;
	}
	else if (rng == 2)
	{
		std::cout << "Generated C\n";
		return new C;
	}

	return NULL;
}

void identify(Base &p)
{
	try
	{
		Base &ref = dynamic_cast<A&>(p);
		std::cout << "Identyfied has A\n";
		(void)ref;
	}
	catch (const std::exception&e)
	{
	}
	try
	{
		Base &ref = dynamic_cast<B&>(p);
		std::cout << "Identyfied has B\n";
		(void)ref;
	}
	catch (const std::exception&e)
	{
	}
	try
	{
		Base &ref = dynamic_cast<C&>(p);
		std::cout << "Identyfied has C\n";
		(void)ref;
	}
	catch (const std::exception&e)
	{
	}
	return ;
}

void identify(Base *p)
{
	Base *ptr;

	ptr = dynamic_cast<A*>(p);
	if (ptr != NULL)
	{
		std::cout << "Identyfied has A\n";
		return ;
	}
	ptr = dynamic_cast<B*>(p);
	if (ptr != NULL)
	{
		std::cout << "Identyfied has B\n";
		return ;
	}
	ptr = dynamic_cast<C*>(p);
	if (ptr != NULL)
	{
		std::cout << "Identyfied has C\n";
		return ;
	}
	return ;
}

