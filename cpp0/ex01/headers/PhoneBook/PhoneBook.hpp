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
	public:
		PhoneBook();
		void add(void);
		void search(void);
	private:
		void print_contacts(void);
		int	get_table_index();
		void print_contact_info(int	table_index);
};
