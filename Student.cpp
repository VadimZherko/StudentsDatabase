#pragma warning(disable: 4996)
#include <iostream>
#include "Date.hpp"
#include <string.h>
#include "Student.hpp"

void Student::operator=(Student& other)
{
	size_t size = 0;

	size = strlen(other.name);
	name = new char[size + 1] {'\0'};
	strcpy(name, other.name);

	size = strlen(other.surname);
	surname = new char[size + 1] {'\0'};
	strcpy(surname, other.surname);

	size = strlen(other.second_name);
	second_name = new char[size + 1] {'\0'};
	strcpy(second_name, other.second_name);

	age = other.age;
	course = other.course;
	avg = other.avg;
	sex = other.sex;
}



Student::~Student()
{
	if (surname) delete surname;
	if (name) delete name;
	if (second_name) delete second_name;
}
