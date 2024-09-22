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
	Student* generate(const int size, StudentsDatabaseType type = Standart);

private:

	FileHandler surname;
	FileHandler male_name;
	FileHandler male_second_name;
	FileHandler female_name;
	FileHandler female_second_name;

	void generate_male(Student& student);
	void generate_female(Student& student);
};