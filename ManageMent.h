#pragma once
#include<iostream>
using namespace std;
#include"Student.h"
#include<vector>

class ManageMent
{
	enum Operator//ö�ٳ���
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
	//����������
	void menu();
	//��ʾ�˵�
	void show();
	//��ʾ����ѧ����Ϣ
	void  add();
	//���
	void  del();
	//ɾ��
	void change();
	//�޸�
	void  search();
	//���Ҽ�¼����
	void sort();
	//����
	ManageMent();
private:
	//���ļ���ȡѧ����Ϣ
	void readData(const string& fileName);
	//����ѧ����Ϣ���ļ�
	void writeData(const string& fileName);
public:
string tableHeader;	//��ͷ
vector<Student> vec_stu;

};
