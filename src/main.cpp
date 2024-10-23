#include <iostream>
#include <fstream>
#include <StudentsDatabase.hpp>

using namespace std;

void task1(StudentsDatabase&);
void task2(StudentsDatabase&);
void task3(StudentsDatabase&);
void task4(StudentsDatabase&);
void task5(StudentsDatabase&);
void task6(StudentsDatabase&);
void task7(StudentsDatabase&);

int main()
{
	const int SIZE = 100;

	StudentsDatabase data(SIZE, StudentsDatabaseType::Technical);
	int number_of_task = 0;

	std::cout << "List of tasks:" << std::endl;
	std::cout << "Task 1" << std::endl;
	std::cout << "Task 2" << std::endl;
	std::cout << "Task 3" << std::endl;
	std::cout << "Task 4" << std::endl;
	std::cout << "Task 5" << std::endl;
	std::cout << "Task 6" << std::endl;
	std::cout << "Task 7" << std::endl;
	std::cout << "Output base 8" << std::endl;
	std::cout << "Enter the task number to run it" << std::endl;

	std::cin >> number_of_task;

	switch(number_of_task)
	{
		case 1:
		{
			task1(data);
			break;
		}
		case 2:
		{
			task2(data);
			break;
		}
		case 3:
		{
			task3(data);
			break;
		}
		case 4:
		{
			task4(data);
			break;
		}
		case 5:
		{
			task5(data);
			break;
		}
		case 6:
		{
			task6(data);
			break;
		}
		case 7:
		{
			task7(data);
			break;
		}
		case 8:
		{
			data.print();
			break;
		}
		default:
		{
			std::cout << "Error_input" << std::endl;
		}
	}
	
}

void task1(StudentsDatabase& data)
{
	StudentsDatabase data1 = data.select_by_course(1);
	StudentsDatabase data2 = data.select_by_course(2);
	StudentsDatabase data3 = data.select_by_course(3);
	StudentsDatabase data4 = data.select_by_course(4);
	StudentsDatabase data5 = data.select_by_course(5);
	
	Date age(31, 12, 2222);

	data1 = data1.select_younger_than(age);
	data2 = data2.select_younger_than(age);
	data3 = data3.select_younger_than(age);
	data4 = data4.select_younger_than(age);
	data5 = data5.select_younger_than(age);

	data1.insert(data2)->insert(data3)->insert(data4)->insert(data5);
	data1.save("task1.txt");
	data1.print();
}

void task2(StudentsDatabase& data)
{
	cout << "Input letter" << endl;
	char letter;
	cin >> letter;

	StudentsDatabase new_data = data.select_starts_with_letter(letter);
	new_data.save("task2.txt");
	new_data.print();
}

void task3(StudentsDatabase& data)
{
	Date new_age;

	StudentsDatabase new_data = data.select_older_than(new_age);
	new_data.save("task3.txt");
	new_data.print();
}

void task4(StudentsDatabase& data)
{
	StudentsDatabase new_data = data.select_avg_more_than(4.0);
	new_data.save("task4.txt");
	new_data.print();
}

void task5(StudentsDatabase& data)
{
	StudentsDatabase new_data = data.select_avg_less_than(4.0);
	new_data.save("task5.txt");
	new_data.print();
}

void task6(StudentsDatabase& data)
{
	double general_avg = data.get_avg();
	StudentsDatabase new_data = data.select_avg_more_than(general_avg);
	new_data.save("task6.txt");
	new_data.print();
}

void task7(StudentsDatabase& data)
{
	StudentsDatabase data1 = data.select_by_course(1);
	data1.print();
	StudentsDatabase data2 = data.select_by_course(2);
	StudentsDatabase data3 = data.select_by_course(3);
	StudentsDatabase data4 = data.select_by_course(4);
	StudentsDatabase data5 = data.select_by_course(5);

	data1 = data1.select_avg_more_than(data1.get_avg());
	data2 = data2.select_avg_more_than(data2.get_avg());
	data3 = data3.select_avg_more_than(data3.get_avg());
	data4 = data4.select_avg_more_than(data4.get_avg());
	data5 = data5.select_avg_more_than(data5.get_avg());

	data1.insert(data2)->insert(data3)->insert(data4)->insert(data4);
	data1.save("task7.txt");
	data1.print();
}