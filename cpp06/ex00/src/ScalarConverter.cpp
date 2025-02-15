#include "../headers/ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &str)
{
	char	c;
	double result;
	double decimal, decimal_count;
	int sign;
	int i;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	if (!str[i] && str.length() == 1)
	{
		if (sign > 0)
			c = '+';
		else if (sign < 0)
			c = '-';
		if (c <= static_cast<double>('~') && c >= static_cast<double>('!'))
			std::cout << "char: " << static_cast<char>(c) << "\n";
		else
			std::cout << "char: " << "Non displayable" << "\n";
		std::cout << "int: " << static_cast<int>(c) << "\n";
		std::cout << "float: " << static_cast<float>(c) << ".0f"<< "\n";
		std::cout << "double: " << static_cast<double>(c) << ".0" <<  "\n";
		return ;
	}
	else if (!str[i])
		result = NAN;
	if ((str.substr(i, -1).length() == 1) &&
	(str[i] <= static_cast<double>('~') && str[i] >= static_cast<double>('!')) &&
	(str[i] > '9' || str[i] < '0'))
	{
		c = str[i];
		if (c <= static_cast<double>('~') && c >= static_cast<double>('!'))
			std::cout << "char: " << static_cast<char>(c) << "\n";
		else
			std::cout << "char: " << "Non displayable" << "\n";
		std::cout << "int: " << static_cast<int>(c) << "\n";
		std::cout << "float: " << static_cast<float>(c) << ".0f"<< "\n";
		std::cout << "double: " << static_cast<float>(c) << ".0" <<  "\n";
		return ;
	}
	if (str.substr(i, -1) == "inf" || str.substr(i, -1) == "inff")
	{
		std::cout << "char: " << "impossible" << "\n";
		if (sign > 0)
		{
			std::cout << "int: " << "+inf" << "\n";
			std::cout << "float: " << "+inff" << "\n";
			std::cout << "double: " << "+inf" << "\n";
		}
		else if (sign < 0)
		{
			std::cout << "int: " << "-inf" << "\n";
			std::cout << "float: " << "-inff" << "\n";
			std::cout << "double: " << "-inf" << "\n";
		}
		return ;
	}
	while(str[i] && str[i] != '.')
	{
		if (str[i] == 'f' && str[i + 1] == '\0')
			break ;
		if (str[i] > '9' || str[i] < '0')
		{
			result = NAN;
			break ;
		}
		result = (result * 10) + (str[i] - static_cast<double>('0')) * sign;
		i++;
	}
	if (str[i] == '.')
		i++;
	decimal = 0;
	decimal_count = 0;
	while (str[i])
	{
		if (str[i] == 'f' && str[i + 1] == '\0')
			break ;
		if (str[i] > '9' || str[i] < '0')
		{
			result = NAN;
			break ;
		}
		decimal_count++;
		decimal = (decimal * 10) + (str[i] - static_cast<double>('0'));
		i++;
	}

	result += decimal / pow(10, decimal_count);

	if (std::isnan(result))
	{
		std::cout << "char: " << "impossible" << "\n";
		std::cout << "int: " << "impossible" << "\n";
		std::cout << "float: " << "nanf" << "\n";
		std::cout << "double: " << "nan" << "\n";
		return ;
	}

	if (result <= static_cast<double>('~') && result >= static_cast<double>('!'))
		std::cout << "char: " << static_cast<char>(result) << "\n";
	else
		std::cout << "char: " << "Non displayable" << "\n";
	std::cout << "int: " << static_cast<int>(result) << "\n";
	if (decimal > 0)
	{
		std::cout << "float: " << static_cast<float>(result) << "f"<< "\n";
		std::cout << "double: " << result << "\n";
	}
	else if (decimal == 0)
	{
		std::cout << "float: " << static_cast<float>(result) << ".0f"<< "\n";
		std::cout << "double: " << result << ".0" <<  "\n";
	}
}
