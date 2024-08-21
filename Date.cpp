#pragma warning(disable: 4996)
#include <iostream>
#include "Date.h"

//—читать даты

Date::Date(int day, int month, int year)
{
	input(day, month, year);
}

Date::Date(char* days)
{
	day = atoi(strtok(days, " .,/"));
	month = atoi(strtok(days, " ,./"));
	year = atoi(strtok(days, " ,./"));

	input(day, month, year);
}

Date::Date(int days)
{
	year = days / 365;
	int rest_days = days % 365;
	day = 1; 
	month = 1;

	if (year == 0) year = 1;

	for (auto i = 0; i < 12; i++)
	{
		if (rest_days <= DAYS_IN_MONTH[i] && i != 1)
		{
			month = i + 1;
			day = rest_days;
			break;
		}

		if(i == 1 && rest_days <= DAYS_IN_MONTH[i] + is_leep_year(year))
		{
			month = i + 1;
			day = rest_days;
			break;
		}

		if (i == 1)
		{
			is_leep_year(year) ? rest_days -= DAYS_IN_MONTH[i] + 1 : rest_days -= DAYS_IN_MONTH[i];
			month++;
			continue;
		}

		rest_days -= DAYS_IN_MONTH[i];
	}
}

Date::Date()
{
	year = rand() % 5 + 1999;
	month = rand() % 12 + 1;

	if (month == FEBRUARY)
	{
		day = rand() % (DAYS_IN_MONTH[FEBRUARY] + is_leep_year(year)) + 1;
	}
	else day = rand() % (DAYS_IN_MONTH[month]) + 1;
}

void Date::input(int day, int month, int year)
{
	if (year > 0) this->year = year;
	else this->year = rand() % 10000;

	if (month > 0 && month <= NUMBER_OF_MONTHS) this->month = month;
	else this->month = rand() / 12 + 1;

	if (day <= 31 && day > 0 && is_correct_days(day, this->month, this->year)) this->day = day;
	else this->day = rand() % 28;
}

bool Date::is_leep_year(int year)
{
	if ((year % 100 == 0) && (year % 400 == 0)) return true;
	else if ((year % 100 != 0) && (year % 4)) return true;
	else return false;
}

bool Date::is_correct_days(int day, int month, int year)
{
	bool is_correct = true;

	if (month == FEBRUARY)
	{
		if (is_leep_year(year)) if (day > 29) is_correct = false;
		else if (day > 28) is_correct = false;
	}
	
	for (auto i = 0; i < sizeof(MONTHS_WITH_30_DAYS[0]) / sizeof(int); i++)
	{
		if (month == MONTHS_WITH_30_DAYS[i] && day > 30) is_correct = false;
	}

	return is_correct;
}

void Date::operator =(Date other)
{
	this->day = other.day;
	this->month = other.month;
	this->year = other.year;
}

Date Date::age_calculation(Date& birthday)
{
	Date age;
	age.year = today_year - birthday.year;

	if (today_month <= birthday.month)
	{
		age.year--;
		age.month = today_month + 12 - birthday.month;
	}
	else age.month = today_month - birthday.month;

	if (today_day <= birthday.day)
	{
		age.month--;
		age.day = DAYS_IN_MONTH[age.month] + today_day - birthday.day;
	}
	else age.day = today_day - birthday.day;

	return age;
}

const bool Date::operator < (const Date& other)
{
	if (this->year < other.year) return true;
	if (this->year == other.year)
	{
		if (this->month < other.month) return true;
		if (this->month == other.month)
		{
			if (this->day < other.day) return true;
			return false;
		}
	}
}

const bool Date::operator > (const Date& other)
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
}

const bool Date::operator == (const Date& other)
{
	bool is_correct = true;

	if (this->year != other.year) is_correct = false;
	if (this->month != other.month) is_correct = false;
	if (this->day != other.day) is_correct = false;
	
	return is_correct;
}

int Date::get_year()
{
	return this->year;
}

int Date::get_day()
{
	return this->day;
}

int Date::get_month()
{
	return this->month;
}