#pragma once//ȷ��ͷ�ļ�ֻ������һ�Σ���ֹ�ظ�����
#include<iostream>
#include<string>
using namespace std;
class Student
{
public:
	Student();// Ĭ�Ϲ��캯��
	Student(unsigned int number);//����һ������ָ��ѧ�ŵ� Student ����
	Student(unsigned int number, const string& name);
	Student(unsigned int number , const string& name, const string& grade, int math, int chinese, int englist);
	// <ѧ�š��������꼶����ѧ�ɼ������ĳɼ���Ӣ��ɼ�>�Ĺ��캯��
	void display();//��ʾ��Ϣ

	string formatInfo();//��ѧ����������Ϣ��ʽ�����ַ���
	void formatWrite(const string& str);//�ַ�����ʽ��д��ѧ������Ϣ
public:
	//�Ƚ�����ѧ������Ĵ�С��ϵ
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

