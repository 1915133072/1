#include "Student.h"
#include<string>
#include<sstream>
using namespace std;
Student::Student() :number(0), math(0), chinese(0), english(0)
{
}

Student::Student(unsigned int number) :Student()
{
	this->number = number;
}
Student::Student(unsigned int number, const string& name) 
{
	this->number = number;
	this->name = name;
}
Student::Student(unsigned int number, const string& name, const string& grade, int math, int chinese, int english)
	: number(number), name(name), grade(grade), math(math), chinese(chinese), english(english)
{}

void Student::display()
{
	cout << this->number << "\t" << this->name << "\t" << this->grade << "\t" << this->math << "\t" << this->chinese << "\t" << this->english << endl;
}
//把学生的所有信息格式化成字符串
std::string Student::formatInfo()
{
	stringstream ss;
	ss << this->number << "\t" << this->name << "\t" << this->grade << "\t" << this->math << "\t" << this->chinese << "\t" << this->english << endl;
	return ss.str();
}

//字符串格式化写入学生的信息
void Student::formatWrite(const string& str)
{
	stringstream ss(str);
	ss >> this->number >> this->name >> this->grade >> this->math >> this->chinese >> this->english;
}

bool Student::operator==(const Student& right) const
{
	return this->number == right.number;
}

bool Student::operator>(const Student& right) const
{
	return this->number > right.number;
}

bool Student::operator<(const Student& right) const
{
	return this->number < right.number;
}
