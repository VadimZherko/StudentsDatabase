#pragma once
#include "Date.hpp"
#include "Student.hpp"
#include "StudentsGenerator.hpp"

struct StudentsDatabase
{
private:

	int size_ = 0;
	Student* students_ = nullptr;
	static StudentsGenerator generator_;
	
	bool is_number(const char*);

public:
	
	StudentsDatabase();
	StudentsDatabase(const int SIZE, StudentsDatabaseType);
	~StudentsDatabase();

	double get_avg() const;

	void generate(const int, const StudentsDatabaseType);
	void print() const;
	void save(const char* filename) const;
	void load(const char* filename);

	StudentsDatabase select_younger_than(const Date&) const;
	StudentsDatabase select_starts_with_letter(const char letter) const;
	StudentsDatabase select_older_than(const Date&) const;
	StudentsDatabase select_avg_more_than(const double) const;
	StudentsDatabase select_avg_less_than(const double) const;
	StudentsDatabase select_by_course(const int) const;
	StudentsDatabase* insert(const StudentsDatabase&);

	void operator=(const StudentsDatabase& other);
	StudentsDatabase operator+(const StudentsDatabase&) const;
};
