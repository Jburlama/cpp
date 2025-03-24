#pragma once
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <math.h>

struct Date
{
	int year;
	int month;
	int day;

	Date():year(0), month(0), day(0) {}
	Date(int y, int m, int d):year(y), month(m), day(d) {}

	Date operator--();
	Date operator--(int);
	bool operator<(const Date &other) const;
	bool operator==(const Date &other) const;
};

std::ostream &operator<<(std::ostream &os, const Date &date);


// get_db.cpp
std::map<Date, float>			get_data(void);

// BitcoinExchange.cpp
void							exchange(std::map<Date, float> map_data, char *argv);
void							display_results(std::map<Date, float> db, Date date, float value);
float							get_value(std::string input_value);
Date							get_date(std::string input_date);
void							strtrim(std::string &input_date);
