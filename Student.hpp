#pragma once
#include <iostream>
#include "Date.hpp"

struct Student
{
public:

	char* surname = nullptr;
	char* name = nullptr;
	char* second_name = nullptr;
	Date age;
	bool sex = 0;
	int course = 1;
	double avg = 1.0;

	Student operator=(Student other);

	//PROBLEMS WITH PEREGRUZKA
	//Вот тута вот проблемы//

	//PROBLEMS
//	~Student()
//	{
//		delete[] second_name;
//		delete[] surname;
//		delete[] name;
//	}
};
