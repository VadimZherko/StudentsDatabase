#pragma once
#include "Student.h"
#include "Students_generator.h"
#include "Date.h"

enum StudentsDatabaseType
{
	Technical,//Percentage of women - 30%
	Humanitarian, //Percentage of women - 70%
	Standart //Percentage of women - 50%
};

struct StudentsDatabase
{
private:

	int size_ = 0;
	Student* students_;

public:

	void generate(const int, const StudentsDatabaseType);
	const void print();
	const void save(const char* filename);
	StudentsDatabase& select_younger_than(Date&);
	StudentsDatabase& select_starts_with_letter(const char letter);
	StudentsDatabase& select_older_than(const Date&);
	const float get_avg();
	StudentsDatabase& select_more_than_avg(const float);
	StudentsDatabase& select_less_than_avg(const float);
	StudentsDatabase& select_by_course(const int);
	StudentsDatabase& add(const StudentsDatabase&);
	void load(const char* filename);
	void operator=(StudentsDatabase& other);
	void operator=(Date& age);
};
