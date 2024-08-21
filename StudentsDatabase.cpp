#pragma warning(disable:4996)
#include <fstream>
#include <iostream>
#include "Students_database.h"


void StudentsDatabase::generate(const int size,const StudentsDatabaseType type)
{
	static::StudentsGenerator gen; 
	size_ = size;
	students_ = gen.generate(size, type);

	int percent_womens = type;

	if (type == StudentsDatabaseType::Humanitarian) students_ = gen.generate(size, type);
	else if (type == StudentsDatabaseType::Technical) students_ = gen.generate(size, type);
	else if (type == StudentsDatabaseType::Standart) students_ = gen.generate(size, type);
}

const void StudentsDatabase::save(const char* filename)
{
	std::ofstream write(filename);
	for (int i = 0; i < size_; i++)
	{
		write << students_[i].name << ' ' << students_[i].second_name << ' ' << students_[i].surname << ", " << students_[i].sex << ", ";
		write << students_[i].age.get_day() << '/' << students_[i].age.get_month() << '/' << students_[i].age.get_year() << ", ";
		write << students_[i].avg << ", " << students_[i].course << std::endl;
	}
	write.close();
}

const void StudentsDatabase::print()
{
	for (int i = 0; i < this->size_; i++)
	{
		std::cout << students_[i].name << ' ' << students_[i].second_name << ' ' << this->students_[i].surname << ", " << this->students_[i].sex << ", ";
		std::cout << students_[i].age.get_day() << '/' << students_[i].age.get_month() << '/' << students_[i].age.get_year() << ", ";
		std::cout << students_[i].avg << ", " << students_[i].course << std::endl;
	}
}

StudentsDatabase& StudentsDatabase::select_younger_than(Date& age_)
{
	StudentsDatabase new_data;

	for (auto i = 0; i < size_; i++)
	{
		if (this->students_->age < age_) new_data.size_++;
	}

	new_data.students_ = new Student[new_data.size_];
	new_data.size_ = 0;

	for (auto i = 0; i < size_; i++)
	{
		if (this->students_->age < age_)
		{
			new_data.students_[new_data.size_] = this->students_[i];
			new_data.size_++;
		}
	}

	return new_data;
}

StudentsDatabase& StudentsDatabase::select_starts_with_letter(char letter)
{
	StudentsDatabase new_data;

	if (letter < 65 || letter > 123) return new_data;
	if ((int)letter > 96 && (int)letter < 123) letter = (int)letter - 32;

	for (auto i = 0; i < size_; i++)
	{
		if (students_[i].name[0] == letter) new_data.size_++;
	}

	new_data.students_ = new Student[new_data.size_];
	new_data.size_ = 0;

	for (auto i = 0; i < size_; i++)
	{
		if (students_[i].name[0] == letter)
		{
			new_data.students_[new_data.size_] = students_[i];
			new_data.size_++;
		}
	}

	return new_data;
}

StudentsDatabase& StudentsDatabase::select_older_than(const Date& age_)
{
	StudentsDatabase new_data;

	for (auto i = 0; i < size_; i++)
	{
		if (this->students_->age > age_) new_data.size_++;
	}

	new_data.students_ = new Student[new_data.size_];
	new_data.size_ = 0;

	for (auto i = 0; i < size_; i++)
	{
		if (this->students_->age > age_)
		{
			new_data.students_[new_data.size_] = this->students_[i];
			new_data.size_++;
		}
	}

	return new_data;
}


StudentsDatabase& StudentsDatabase::select_by_course(const int course)
{
	StudentsDatabase new_data;

	if (course > 5 && course < 1) return new_data;


	for (auto i = 0; i < size_; i++)
	{
		if (course == students_[i].course)
		{
			new_data.size_++;
		}
	}

	new_data.students_ = new Student[new_data.size_];
	new_data.size_ = 0;

	for (auto i = 0; i < size_; i++)
	{
		if (course == students_[i].course)
		{
			new_data.students_[new_data.size_] = students_[i];
			new_data.size_++;
		}
	}
	
	return new_data;
}

const float StudentsDatabase::get_avg()
{
	float general_avg = 0;

	for (auto i = 0; i < size_; i++)
	{
		general_avg += students_[i].avg;
	}

	general_avg /= size_;

	return general_avg;
}

StudentsDatabase& StudentsDatabase::select_more_than_avg(float general_avg)
{
	StudentsDatabase new_data;

	for (auto i = 0; i < size_; i++)
	{
		if (students_[i].avg > general_avg)
		{
			new_data.size_++;
		}
	}

	new_data.students_ = new Student[new_data.size_];
	new_data.size_ = 0;

	for (auto i = 0; i < size_; i++)
	{
		if (students_[i].avg > general_avg)
		{
			new_data.students_[new_data.size_] = students_[i];
			new_data.size_++;
		}
	}

	return new_data;
}

StudentsDatabase& StudentsDatabase::select_less_than_avg(float general_avg)
{
	StudentsDatabase new_data;

	for (auto i = 0; i < size_; i++)
	{
		if (students_[i].avg < general_avg)
		{
			new_data.size_++;
		}
	}

	new_data.students_ = new Student[new_data.size_];
	new_data.size_ = 0;

	for (auto i = 0; i < size_; i++)
	{
		if (students_[i].avg < general_avg)
		{
			new_data.students_[new_data.size_] = students_[i];
			new_data.size_++;
		}
	}

	return new_data;
}


StudentsDatabase& StudentsDatabase::add(const StudentsDatabase & old_data)
{
	int new_size = size_ + old_data.size_;
	Student *buffer = new Student[new_size];
	
	for (auto i = 0; i < size_; i++)
	{
		buffer[i] = students_[i];
	}

	for (auto i = 0; i < old_data.size_; i++)
	{
		buffer[i + size_] = old_data.students_[i];
	}

	delete students_;

	students_ = buffer;
	size_ = new_size;

	return *this;
}

void StudentsDatabase::load(const char* filename)
{
	std::ifstream read(filename);
	char* str = new char[50];
	int size = 0;

	while (!read.eof())
	{
		read.getline(str, 50);
		size++;
	}

	this->students_ = new Student[size];

	for(auto i = 0; i < size; i++)
	{
		read.getline(str, 50);
		str = strtok(str, " ,");
		strcpy(this->students_[i].name, str);
		str = strtok(str, " ,");
		strcpy(this->students_[i].second_name, str);
		str = strtok(str, " ,");
		strcpy(this->students_[i].surname,str);
		str = strtok(str, " ,");
		this->students_[i].sex = atoi(str);
		str = strtok(str, " ,");
		this->students_[i].age = atoi(str);
		str = strtok(str, " ,");
		this->students_[i].avg = atof(str);
		str = strtok(str, " ,");
		this->students_[i].course = atoi(str);
	}

	delete[] str;
}

void StudentsDatabase::operator=(StudentsDatabase& other)
{
	this->size_ = other.size_;
	this->students_ = other.students_;
}

//void StudentsDatabase::operator=(Date& age)
//{
//	this->students_.age = 
//}