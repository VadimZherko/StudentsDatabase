#pragma warning(disable: 4996)
#include <fstream>
#include <iostream>
#include "StudentsGenerator.hpp"


StudentsGenerator::StudentsGenerator() :
	surname("../data/names/surname.txt"),
	male_name("../data/names/male_name.txt"),
	male_second_name("../data/names/male_second_name.txt"),
	female_name("../data/names/female_name.txt"),
	female_second_name("../data/names/female_second_name.txt"){}

Student* StudentsGenerator::generate(const int size, StudentsDatabaseType type)
{
	int percent_womens = type;
	if (type == StudentsDatabaseType::Humanitarian) percent_womens = 70;
	else if (type == StudentsDatabaseType::Technical) percent_womens = 30;
	else if (type == StudentsDatabaseType::Standart) percent_womens = 50;
	else if (type = StudentsDatabaseType::Mens) percent_womens = 0;
	else
	{
		printf("ERROR: type mismatch");
		return nullptr;
	}

	Student* students = new Student[size];

	for (auto i = 0; i < size; i++)
	{	
		int random = rand() % 100;
		if (random >= percent_womens) generate_male(students[i]);
		else generate_female(students[i]);
	}

	return students;
}

void StudentsGenerator::generate_male(Student& student)
{
	int num = 0, num_line = 0, course = 0;

	//name selection
	student.name = male_name.get_random_line(student.name);

	//second name selection
	student.second_name = male_second_name.get_random_line(student.second_name);

	//surname selection
	student.surname = surname.get_random_line(student.surname);

	//Age calculation
	student.age;

	//Select gender
	student.sex = 1;

	//Course calculation
	student.course = (int)(rand() % 5 + 1);

	//Avg calculation
	student.avg = (rand() % 90) / 10.0 + 1;
}

void StudentsGenerator::generate_female(Student& student)
{
	int num = 0, num_line = 0, course = 0;

	//Select name
	student.name = female_name.get_random_line(student.name);

	//Select second name
	student.second_name = female_second_name.get_random_line(student.second_name);

	//Select surname
	student.surname = surname.get_random_line(student.surname);

	//Age calculation
	student.age;

	//Select gender
	student.sex = 0;

	//Course calculation
	student.course = (int)(rand() % 5 + 1);

	//Avg calculation
	student.avg = (rand() % 90) / 10.0 + 1;
}
