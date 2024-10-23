#pragma once
#include <ctime>

class Date
{
private:
	unsigned int day, month, year;
	const int NUMBER_OF_MONTHS = 12;
	const int DAYS_IN_MONTH[13]{0, 31,28,31,30,31,30,31,31,30,31,30,31 };
	
	bool is_leep_year(int) const;
	bool is_correct_days(int, int, int) const;
	void set(int, int, int);

public:
	Date(int, int, int);
	Date(char*);
	Date(const int);
	Date();
	Date age_calculation(Date&) const;
	Date get_today_date() const;

	const bool operator<(const Date&) const;
	const bool operator>(const Date&) const;
	const bool operator==(const Date&) const;
	void operator=(Date other);
	int get_day() const;
	int get_year() const;
	int get_month() const;
	int convert_date_to_days(const Date&) const;


	int operator-(const Date& other) const;
	Date operator-(const int days) const;
	Date operator+(const int days) const;
};
