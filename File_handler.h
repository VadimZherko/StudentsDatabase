#pragma once
#include <fstream>

class FileHandler {
public:

	std::fstream file;
	size_t size;

	FileHandler(const char* filename);
	void get_random_line(...)
};
