#pragma warning(disable: 4996)
#include <fstream>
#include <iostream>
#include "StudentsGenerator.hpp"

FileHandler StudentsGenerator::filer_;

StudentsGenerator::StudentsGenerator()
{
	read_surname.open("surname.txt");

	read_male_name.open("male_name.txt");
	read_male_second_name.open("male_second_name.txt");
	
	read_female_name.open("female_name.txt");
	read_female_second_name.open("female_second_name.txt");
}

StudentsGenerator::~StudentsGenerator()
{
	read_surname.close();

	read_male_name.close();
	read_male_second_name.close();

	read_female_name.close();
	read_female_second_name.close();
}

Student* StudentsGenerator::generate(int size, int type = Standart)
{
	int percent_womens = type;
	if (type == StudentsDatabaseType::Humanitarian) percent_womens = 70;
	else if (type == StudentsDatabaseType::Technical) percent_womens = 30;
	else if (type == StudentsDatabaseType::Standart)percent_womens = 50;
	else
	{
		printf("ERROR: type mismatch");
		return nullptr;
	}

	Student* students = new Student[size];

	for (auto i = 0; i < size; i++)
	{
		int random = rand() % 100;
		if (random >= percent_womens) students[i] = generate_male();
		else students[i] = generate_female();
	}

	return students;
}

Student StudentsGenerator::generate_male()
{
	int num = 0, num_line = 0, course = 0;
	Student male_student;
	
	//name selection
	male_student.name = filer_.get_random_line(read_male_name, male_student.name);

	//second name selection
	male_student.second_name = filer_.get_random_line(read_male_second_name, male_student.second_name);

	//surname selection
	male_student.surname = filer_.get_random_line(read_surname, male_student.surname);

	//Age calculation
	male_student.age;

	//Select gender
	male_student.sex = 1;

	//Course calculation
	male_student.course = (int)(rand() % 5 + 1);

	//Avg calculation
	male_student.avg = (rand() % 100) / 10.0 + 2; 

	read_surname.seekg(0);
	read_male_name.seekg(0);
	read_male_second_name.seekg(0);

	return male_student;
}

Student StudentsGenerator::generate_female()
{
	int num = 0, num_line = 0, course = 0;
	Student female_student;

	//Select name
	female_student.name = filer_.get_random_line(read_female_name, female_student.name);

	//Select second name
	female_student.second_name = filer_.get_random_line(read_female_second_name, female_student.second_name);

	//Select surname
	female_student.surname = filer_.get_random_line(read_surname, female_student.surname);

	//Age calculation
	female_student.age;

	//Select gender
	female_student.sex = 0;

	//Course calculation
	female_student.course = (int)(rand() % 5 + 1);

	//Avg calculation
	female_student.avg = (rand() % 90) / 10.0 + 1;

	read_surname.seekg(0);
	read_female_name.seekg(0);
	read_female_second_name.seekg(0);

	return female_student;
}