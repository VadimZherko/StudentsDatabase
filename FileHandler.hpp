#pragma once
#include <fstream>

class FileHandler {
public:

	static FileHandler read_file_;

	FileHandler();
	FileHandler(const char*);
	~FileHandler();

	char* get_random_line(std::ifstream& read, char* name);

private:
	std::fstream file_;
};
