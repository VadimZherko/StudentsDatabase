#pragma once
#include <fstream>
#include "Student.hpp"

class FileHandler {
public:

	FileHandler();
	FileHandler(const char*);
	~FileHandler();
	FileHandler& operator<<(Student&);
	char* get_random_line(char* name);

private:

	std::fstream file_;
};