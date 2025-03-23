#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <cstdlib>

struct Date
{
	int year;
	int month;
	int day;

	Date():year(0), month(0), day(0) {}
	Date(int y, int m, int d):year(y), month(m), day(d) {}
};

std::ostream &operator<<(std::ostream &os, const Date &date);

std::map<std::string, float>	get_data(void);
void 							print_map(std::map<std::string, float> map_data);
void							exchange(std::map<std::string, float> map_data, char *argv);
Date							get_date(std::string input_date);
void							strtrim(std::string &input_date);
