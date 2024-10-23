#pragma warning(disable: 4996)
#include <iostream>
#include "Date.hpp"
#include <string.h>

#define FEBRUARY 2
#define MY_ERROR_CODE -42

Date::Date(int day, int month, int year)
{
	set(day, month, year);
}

Date::Date(char* days)
{
	day = atoi(strtok(days, " .,/"));
	month = atoi(strtok(days, " ,./"));
	year = atoi(strtok(days, " ,./"));

	set(day, month, year);
}

Date::Date(int days)
{
	year = days / 365 + 1;
	int rest_days = days % 365;
	day = 1; 
	month = 1;

	for (auto i = 0; i < 12; i++)
	{
		auto _day = rest_days - DAYS_IN_MONTH[i] + (i == 1 && is_leep_year(year));
		if (_day <= 0) {
			month = i + 1;
			day = rest_days; 
			break;
		}
		rest_days = _day;
	}
}

Date::Date()
{
	year = rand() % 5 + 1999;
	month = rand() % 12 + 1;

	day = rand() % (DAYS_IN_MONTH[month]) + 1 + is_leep_year(year);
}

void Date::set(int day, int month, int year)
{
	if (year > 0) this->year = year;
	else this->year = 1;

	if (month > 0 && month <= NUMBER_OF_MONTHS) this->month = month;
	else this->month = 1;

	if (day <= 31 && day > 0 && is_correct_days(day, this->month, this->year)) this->day = day;
	else this->day = 1;
}

bool Date::is_leep_year(int year) const
{
	if ((year % 400 == 0)) return true;
	if ((year % 100 != 0) && (year % 4)) return true;
	return false;
}

bool Date::is_correct_days(int day, int month, int year) const
{
	for (auto i = 1; i < sizeof(DAYS_IN_MONTH[0] / sizeof(int)); i++)
	{
		if (month == i)
		{
			if (month == FEBRUARY && DAYS_IN_MONTH[i] + is_leep_year(year)) return false;
			if (month == i && DAYS_IN_MONTH[i] < i && month != FEBRUARY) return false;
		}
	}

	return true;
}

void Date::operator=(Date other) 
{
	this->day = other.day;
	this->month = other.month;
	this->year = other.year;
}

Date Date::age_calculation(Date& birthday) const
{
	Date age;
	Date today = get_today_date();

	age.year = today.year - birthday.year;

	if (today.month <= birthday.month)
	{
		age.year--;
		age.month = today.month + 12 - birthday.month;
	}
	else age.month = today.month - birthday.month;

	if (today.day <= birthday.day)
	{
		age.month--;
		age.day = today.day + DAYS_IN_MONTH[age.month] - birthday.day;
	}
	else age.day = today.day - birthday.day;

	return age;
}

Date Date::get_today_date() const
{
	std::time_t t = time(nullptr);
	std::tm* now = std::localtime(&t);

	Date today;
	today.day = now->tm_mday;
	today.month = now->tm_mon + 1;
	today.year = now->tm_year + 1900;

	return today;
}

const bool Date::operator<(const Date& other) const
{
	if (this->year < other.year) return true;
	if (this->year == other.year)
	{
		if (this->month < other.month) return true;
		if (this->month == other.month)
		{
			if (this->day < other.day) return true;
			
		}
	}

	return false;
}

const bool Date::operator>(const Date& other) const
{
	if (this->year > other.year) return true;
	if (this->year == other.year)
	{
		if (this->month > other.month) return true;
		if (this->month == other.month)
		{
			if (this->day > other.day) return true;
			return false;
		}
	}

	return false;
}

const bool Date::operator==(const Date& other) const
{
	if (this->year != other.year) return false;
	if (this->month != other.month) return false;
	if (this->day != other.day) return false;
	
	return true;
}

int Date::operator-(const Date& other) const
{
	auto first_term = convert_date_to_days(*this);
	auto second_term = convert_date_to_days(other);
	
	if (first_term > second_term) return first_term - second_term;
	else return MY_ERROR_CODE;
}

Date Date::operator-(const int second_term) const
{
	auto first_term = convert_date_to_days(*this);
	auto second_term_ = second_term;

	if (first_term > second_term)
	{
		Date new_date(first_term - second_term);
		return new_date;
	}
	else
	{
		Date new_date(1, 1, 1);
		return new_date;
	}
}

Date Date::operator+(const int second_term) const
{
	auto first_term = convert_date_to_days(*this);
	
	Date new_date(first_term + second_term);

	return new_date;
}

int Date::get_year() const
{
	return this->year;
}

int Date::get_day() const
{
	return this->day;
}

int Date::get_month() const
{
	return this->month;
}

int Date::convert_date_to_days(const Date&) const // ?
{
	int days = this->day + (this->year - 1) * 365;

	for (auto i = 1; i < this->month; i++)
	{
		days += DAYS_IN_MONTH[i];
	}

	auto year = 0;

	while (year != this->year)
	{
		year += 4;
		days += is_leep_year(year);
	}

	return days;
}