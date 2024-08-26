#pragma warning(disable: 4996)
#include <fstream>
#include "FileHandler.hpp"

FileHandler::FileHandler()
{

}

FileHandler::FileHandler(const char* filename)
{
	std::ofstream file_(filename);
}

FileHandler::~FileHandler()
{
	file_.close();
}


char* FileHandler::get_random_line(std::ifstream& read, char* name)
{
	int num = 0, num_line = 0;
	num = rand() % 100;
	char* buffer = new char[20] {'\0'};

	while (num != num_line)
	{
		read.getline(buffer, 20);
		num_line++;
	}
	num_line = 0;
	name = new char[strlen(buffer)];

	strcpy(name, buffer);

	delete[] buffer;

	return name;
}