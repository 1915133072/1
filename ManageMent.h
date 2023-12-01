#pragma once
#include<iostream>
using namespace std;
#include"Student.h"
#include<vector>

class ManageMent
{
	enum Operator//枚举常量
	{
		Show = 1,
		Add,
		Del,
		Change,
		Search,
		Sort,
		Read,
		Write
	};
public:
	void run();
	//启动管理类
	void menu();
	//显示菜单
	void show();
	//显示所有学生信息
	void  add();
	//添加
	void  del();
	//删除
	void change();
	//修改
	void  search();
	//查找记录函数
	void sort();
	//排序
	ManageMent();
private:
	//从文件读取学生信息
	void readData(const string& fileName);
	//保存学生信息到文件
	void writeData(const string& fileName);
public:
string tableHeader;	//表头
vector<Student> vec_stu;

};
