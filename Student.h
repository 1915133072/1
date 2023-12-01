#pragma once//确保头文件只被编译一次，防止重复包含
#include<iostream>
#include<string>
using namespace std;
class Student
{
public:
	Student();// 默认构造函数
	Student(unsigned int number);//创建一个具有指定学号的 Student 对象
	Student(unsigned int number, const string& name);
	Student(unsigned int number , const string& name, const string& grade, int math, int chinese, int englist);
	// <学号、姓名、年级、数学成绩、语文成绩和英语成绩>的构造函数
	void display();//显示信息

	string formatInfo();//把学生的所有信息格式化成字符串
	void formatWrite(const string& str);//字符串格式化写入学生的信息
public:
	//比较两个学生对象的大小关系
	bool operator==(const Student& right) const;
	bool operator>(const Student& right) const;
	bool operator<(const Student& right) const;
public:
	unsigned int number;
    string name;
    string grade;
	int math;
	int chinese;
	int english;
};

