#pragma once
#include "../Contact/Contact.hpp"

class PhoneBook {
	private:
		int	_count;
		Contact _contacts[8];
	public:
		PhoneBook();
		void add(void);
};
