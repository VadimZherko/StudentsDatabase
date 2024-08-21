#pragma once
#pragma warning(disable: 4996)
#include <iostream>
#include "Date.h"

struct Student
{
public:

	char* surname;
	char* name;
	char* second_name;
	Date age;
	bool sex;
	int course;
	float avg;

	Student& operator = (Student other)
	{
		int size = 0;
		size = strlen(other.name);
		name = new char[size];
		strcpy(name, other.name);

		size = strlen(other.surname);
		surname = new char[size];
		strcpy(surname, other.surname);

		size = strlen(other.second_name);
		second_name = new char[size];
		strcpy(second_name, other.second_name);

		age = other.age;
		course = other.course;
		avg = other.avg;
		sex = other.sex;

		return *this;
	}

	//PROBLEMS WITH PEREGRUZKA
	//Вот тута вот проблемы//

	//PROBLEMS
	//~Student()
	//{
	//	delete[] second_name;
	//	delete[] surname;
	//	delete[] name;
	//}
};
