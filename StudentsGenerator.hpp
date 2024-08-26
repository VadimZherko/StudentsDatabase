#pragma once
#include <fstream>
#include "Date.hpp"
#include "Student.hpp"
#include "FileHandler.hpp"

enum StudentsDatabaseType
{
	Technical,//Percentage of women - 30%
	Humanitarian, //Percentage of women - 70%
	Standart //Percentage of women - 50%
};

struct StudentsGenerator
{
public:

	StudentsGenerator();
	~StudentsGenerator();
	Student* generate(const int SIZE, int type);
	static FileHandler filer_;

private:

	std::ifstream read_surname;
	std::ifstream read_male_name;
	std::ifstream read_male_second_name;
	std::ifstream read_female_name;
	std::ifstream read_female_second_name;

	Student generate_male();
	Student generate_female();
};