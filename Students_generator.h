#pragma once
#include <fstream>
#include "Student.h"
#include "Students_database.h"
#include "Date.h"

struct StudentsGenerator
{
public:

	StudentsGenerator();
	~StudentsGenerator();
	Student* generate(const int SIZE, int type);
	static StudentsGenerator gen;

private:

	std::ifstream read_surname;
	std::ifstream read_male_name;
	std::ifstream read_male_second_name;
	std::ifstream read_female_name;
	std::ifstream read_female_second_name;

	Student generate_male();
	Student generate_female();
	char* get_random_line(std::ifstream&, char*);
};