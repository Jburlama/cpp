#pragma once
#include <string>
#include <iostream>

class Contact {
		private:
		 	std::string	_first_name;
		 	std::string	_last_name;
			std::string _nickname;
		 	std::string	_number;
			std::string _darkest_secret;
		public:
			void set_first_name(std::string name);
			void set_last_name(std::string name);
			void set_nickname(std::string nickname);
			void set_number(std::string number);
			void set_secret(std::string secrete);
			std::string get_first_name();
			std::string get_last_name();
			std::string get_nickname();
			std::string get_number();
			std::string get_secret();
};
