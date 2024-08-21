#include <iostream>
#include <fstream>
#include "Students_database.h"

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
	StudentsDatabase data; // TODO: конструктор для генерации
	const int SIZE = 1000;
	data.generate(SIZE, StudentsDatabaseType::Technical);
	data.print();
	task5(data);
	data.save("students_0.txt");
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

	data1.add(data2).add(data3).add(data4).add(data4);
	data1.save("task1.txt");
}

void task2(StudentsDatabase& data)
{
	cout << "Введите букву для сравнения" << endl;
	char letter;
	cin >> letter;

	StudentsDatabase new_data = data.select_starts_with_letter(letter);
	new_data.save("task2.txt");
}

void task3(StudentsDatabase& data)
{
	Date new_age;

	StudentsDatabase new_data = data.select_older_than(new_age);
	new_data.save("task3.txt");
}

void task4(StudentsDatabase& data)
{
	StudentsDatabase new_data = data.select_more_than_avg(4.0);
	new_data.save("task4.txt");
}

void task5(StudentsDatabase& data)
{
	StudentsDatabase new_data = data.select_less_than_avg(4.0);
	new_data.save("task5.txt");
}

void task6(StudentsDatabase& data)
{
	float general_avg = data.get_avg();
	StudentsDatabase new_data = data.select_more_than_avg(general_avg);
	new_data.save("task6.txt");
}

void task7(StudentsDatabase& data)
{
	StudentsDatabase data1 = data.select_by_course(1);
	data1.print();
	StudentsDatabase data2 = data.select_by_course(2);
	StudentsDatabase data3 = data.select_by_course(3);
	StudentsDatabase data4 = data.select_by_course(4);
	StudentsDatabase data5 = data.select_by_course(5);

	data1 = data1.select_more_than_avg(data1.get_avg());
	data2 = data2.select_more_than_avg(data2.get_avg());
	data3 = data3.select_more_than_avg(data3.get_avg());
	data4 = data4.select_more_than_avg(data4.get_avg());
	data5 = data5.select_more_than_avg(data5.get_avg());

	data1.add(data2).add(data3).add(data4).add(data4);
	data1.save("task7.txt");
}