#pragma once

class Date
{
private:
	int day, month, year;
	const int NUMBER_OF_MONTHS = 12;
	const int MONTHS_WITH_30_DAYS[4]{ 4,6,8,11 };
	const int FEBRUARY = 2;
	const int DAYS_IN_MONTH[12]{ 31,28,31,30,31,30,31,31,30,31,30,31 };
	
	int today_day = 20, today_month = 8, today_year = 2024;

	bool is_leep_year(int);
	bool is_correct_days(int, int, int);
	void input(int, int, int);

public:
	Date(int, int, int);
	Date(char*);
	Date(const int);
	Date();
	Date age_calculation(Date&);
	const bool operator <(const Date& other);
	const bool operator >(const Date& other);
	const bool operator ==(const Date& other);
	void operator =(Date other);
	int get_day();
	int get_year();
	int get_month();
};
