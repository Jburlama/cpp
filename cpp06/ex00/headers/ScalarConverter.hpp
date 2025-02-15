#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <limits>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter& other);
		ScalarConverter &operator=(ScalarConverter &other);
		~ScalarConverter();
	public:
		static void convert(const std::string &str);
};
