#pragma warning(disable:4996)
#include <fstream>
#include <iostream>
#include <string.h>
#include "StudentsDatabase.hpp"


StudentsGenerator StudentsDatabase::generator_;

StudentsDatabase::StudentsDatabase(const int size, StudentsDatabaseType type)
{
	generate(size, type);
}

StudentsDatabase::StudentsDatabase() 
{
}

StudentsDatabase::~StudentsDatabase()
{
	if (students_)
	{
		std::cout << "Good bye" << std::endl;
		delete[] students_;
	}
}

void StudentsDatabase::generate(const int size, const StudentsDatabaseType type)
{
	size_ = size; 

	if (type == StudentsDatabaseType::Humanitarian) students_ = generator_.generate(size, type);
	else if (type == StudentsDatabaseType::Technical) students_ = generator_.generate(size, type);
	else if (type == StudentsDatabaseType::Standart) students_ = generator_.generate(size, type);
}

void StudentsDatabase::save(const char* filename) const
{
	FileHandler write(filename);

	for (int i = 0; i < size_; i++)
	{
		write << students_[i];
	}
}

void StudentsDatabase::print() const
{
	for (int i = 0; i < this->size_; i++)
	{
		std::cout << students_[i].name << ' ' << students_[i].second_name << ' ' << this->students_[i].surname << ", " << this->students_[i].sex << ", ";
		std::cout << students_[i].age.get_day() << '/' << students_[i].age.get_month() << '/' << students_[i].age.get_year() << ", ";
		std::cout << students_[i].avg << ", " << students_[i].course << std::endl;
	}
}

StudentsDatabase StudentsDatabase::select_younger_than(const Date& age_) const
{
	StudentsDatabase new_data;
	auto new_size = 0;

	for (auto i = 0; i < size_; i++)
	{
		new_size++;
	}

	new_data.students_ = new Student[new_size];

	for (auto i = 0; i < new_size; i++)
	{
		if (this->students_->age < age_)
		{
			new_data.students_[new_data.size_] = this->students_[i];
			new_data.size_++;
		}
	}

	return new_data;
}

StudentsDatabase StudentsDatabase::select_starts_with_letter(char letter) const
{
	StudentsDatabase new_data;

	if (letter < 65 || letter > 123) return new_data;
	if ((int)letter > 96 && (int)letter < 123) letter = (int)letter - 32;

	auto new_size = 0;

	for (auto i = 0; i < size_; i++)
	{
		new_size++;
	}

	new_data.students_ = new Student[new_size];

	for (auto i = 0; i < new_size; i++)
	{
		if (students_[i].name[0] == letter)
		{
			new_data.students_[new_data.size_] = students_[i];
			new_data.size_++;
		}
	}

	return new_data;
}

StudentsDatabase StudentsDatabase::select_older_than(const Date& age_) const
{
	StudentsDatabase new_data;
	auto new_size = 0;

	for (auto i = 0; i < size_; i++)
	{
		new_size++;
	}

	new_data.students_ = new Student[new_size];

	for (auto i = 0; i < new_size; i++)
	{
		if (this->students_->age > age_)
		{
			new_data.students_[new_data.size_] = this->students_[i];
			new_data.size_++;
		}
	}

	return new_data;
}


StudentsDatabase StudentsDatabase::select_by_course(const int course) const
{
	StudentsDatabase new_data;
	auto new_size = 0;

	for (auto i = 0; i < size_; i++)
	{
		if (course == students_[i].course)
		{
			new_size++;
		}
	}

	new_data.students_ = new Student[new_size];

	for (auto i = 0; i < new_size; i++)
	{
		if (course == students_[i].course)
		{
			new_data.students_[new_data.size_] = this->students_[i];
			new_data.size_++;
		}
	}
	
	return new_data;
}

double StudentsDatabase::get_avg() const 
{
	double general_avg = 0;

	for (auto i = 0; i < size_; i++)
	{
		general_avg += students_[i].avg;
	}

	general_avg /= size_;

	return general_avg;
}

StudentsDatabase StudentsDatabase::select_avg_more_than(const double general_avg) const
{
	StudentsDatabase new_data;
	auto new_size = 0;

	for (auto i = 0; i < size_; i++)
	{
		if (students_[i].avg > general_avg)
		{
			new_size++;
		}
	}

	new_data.students_ = new Student[new_size];

	for (auto i = 0; i < new_size; i++)
	{
		if (students_[i].avg > general_avg)
		{
			new_data.students_[new_data.size_] = this->students_[i];
			new_data.size_++;
		}
	}

	return new_data;
}

StudentsDatabase StudentsDatabase::select_avg_less_than(const double general_avg) const
{
	StudentsDatabase new_data;
	auto new_size = 0;

	for (auto i = 0; i < size_; i++)
	{
		if (students_[i].avg < general_avg)
		{
			new_size++;
		}
	}

	new_data.students_ = new Student[new_size];

	for (auto i = 0; i < new_size; i++)
	{
		if (students_[i].avg < general_avg)
		{
			new_data.students_[new_data.size_] = this->students_[i];
			new_data.size_++;
		}
	}

	return new_data;
}

StudentsDatabase StudentsDatabase::insert(const StudentsDatabase & old_data)
{
	int new_size = size_ + old_data.size_;
	Student* buffer = new Student[new_size];
	
	for (auto i = 0; i < size_; i++)
	{
		buffer[i] = students_[i];
	}

	for (auto i = 0; i < old_data.size_; i++)
	{
		#pragma warning( disable : 6385 )
		buffer[i + size_] = old_data.students_[i];
	}

	delete[] students_;
	students_ = buffer;
	size_ = new_size;

	return *this;
}

bool StudentsDatabase::is_number(const char* str)
{
	if (strpbrk(str, "1234567890") == NULL) return 0;
	return 1;
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
		if (is_number(str)) this->students_[i].sex = atoi(str);
		else this->students_[i].sex = -1;

		str = strtok(str, " ,");
		if (is_number(str)) this->students_[i].age = atoi(str);

		else this->students_[i].age = -1;
		this->students_[i].age = atoi(str);

		str = strtok(str, " ,");
		this->students_[i].avg = atof(str);

		if (is_number(str)) this->students_[i].avg = atoi(str);
		else this->students_[i].avg = -1;

		str = strtok(str, " ,");
		if (is_number(str)) this->students_[i].course = atoi(str);
		else this->students_[i].course = -1;

		this->students_[i].course = atoi(str);
	}

	delete[] str;
}

void StudentsDatabase::operator=(StudentsDatabase other)
{
	this->size_ = other.size_;
	this->students_ = other.students_;
}

StudentsDatabase StudentsDatabase::operator+(const StudentsDatabase& other) const
{
	StudentsDatabase new_data;
	new_data.size_ = this->size_ + other.size_;
	
	new_data.students_ = new Student[new_data.size_];

	for (auto i = 0; i < new_data.size_; i++)
	{
		new_data.students_[i] = this->students_[i];
	}

	for (auto i = new_data.size_; i > this->size_; i--)
	{
		new_data.students_[i] = other.students_[i - this->size_];
	}

	return new_data;
}
