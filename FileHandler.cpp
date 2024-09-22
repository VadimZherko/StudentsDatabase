#pragma warning(disable: 4996)
#include <fstream>
#include <iostream>
#include "FileHandler.hpp"
#include <string.h>

FileHandler::FileHandler()
{

}

FileHandler::FileHandler(const char* filename)
{
	file_.open(filename);
}

FileHandler::~FileHandler()
{
	file_.close();
}

FileHandler& FileHandler::operator<<(Student& student)
{
	this->file_ << student.name << ' ' << student.second_name << ' ' << student.surname << ", " << student.sex << ", ";
	this->file_ << student.age.get_day() << '/' << student.age.get_month() << '/' << student.age.get_year() << ", ";
	this->file_ << student.avg << ", " << student.course << std::endl;
	return *this;
}

char* FileHandler::get_random_line(char* name)
{
	int num = 0, num_line = 0;
	num = rand() % 100;
	char* buffer = new char[20] {'\0'};

	while (num != num_line)
	{
		this->file_.getline(buffer, 20);
		num_line++;
	}
	num_line = 0;

	name = new char[strlen(buffer) + 1];
	strcpy(name, buffer);

	delete[] buffer;
	this->file_.seekg(0);

	return name;
}