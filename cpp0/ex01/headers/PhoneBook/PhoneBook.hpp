#pragma once
#include <cstring>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "../Contact/Contact.hpp"

class PhoneBook {
	private:
		int	_count;
		Contact _contacts[8];
		bool	_have[8];
	public:
		PhoneBook();
		void add(void);
		void search(void);
};
