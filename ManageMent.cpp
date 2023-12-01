#include "ManageMent.h"
#include<sstream>//字符串的输入和输出操作
#include<fstream>//读取和写入文件
#include<string>
#include<algorithm>

#include <locale>
//本地化，提供处理字符编码、日期、时间、货币、数字格式等本地化操作的功能。
#include <codecvt>
//字符编码转换
ManageMent::ManageMent() {//加载读写文件
	writeData("D:\\student.txt");
	readData("D:\\test.txt");
}
void ManageMent::run()
{
	menu();
	while (true)
	{
		cout << "请选择菜单>>";
		int op = -1;
		cin >> op;
		switch (op)
		{
		case 0:
			system("cls");//清屏
			menu();
			break;
		case  ManageMent::Show://1
			show();
			break;
		case ManageMent::Add://2
			add();
			break;
		case ManageMent::Del://3
			del();
			break;
		case ManageMent::Change://4
			change();
			break;
		case ManageMent::Search://5
			search();
			break;
		case ManageMent::Sort://6
			sort();
			break;
		case ManageMent::Read://7
			writeData("D:\\student.txt");
			break;
		case ManageMent::Write://8
			readData("D:\\test.txt");
			break;
		default:
			break;
		}
	}
}

void ManageMent::menu()
{
	cout << "***** 学生成绩管理系统 *****" << endl;
	cout << "***** 1,查看学生       *****" << endl;
	cout << "***** 2,添加学生       *****" << endl;
	cout << "***** 3,删除学生       *****" << endl;
	cout << "***** 4,修改学生       *****" << endl;
	cout << "***** 5,查找学生       *****" << endl;
	cout << "***** 6,排序           *****" << endl;
	cout << "***** 7,写文件         *****" << endl;
	cout << "***** 8,读文件         *****" << endl;
	cout << "***** 0,清除屏幕       *****" << endl;
	cout << endl;
}

void ManageMent::show()
{
	cout << this->tableHeader << endl;//输出表格的表头信息
	for (auto& val : vec_stu)//auto 自动推导 val 的类型使其与容器中的元素类型相匹配
	{
		val.display();
	}
	cout <<"****************************"<< endl;
	cout << "共" << vec_stu.size() << "条数据" << endl;
}

void ManageMent::add()
{
	Student stu;
	cout << "请输入<学号、姓名、年级、数学成绩、语文成绩和英语成绩> ";
	cin >> stu.number >> stu.name >> stu.grade >> stu.math >> stu.chinese >> stu.english;

	// 检查学号是否重复
	bool isDuplicate = false;
	for (const auto& s : vec_stu)
	{
		if (s.number == stu.number)
		{
			isDuplicate = true;
			break;
		}
	}
	if (isDuplicate)
	{
		cout << "该学号已存在，请输入不重复的学号！" << endl;
	}
	else
	{
		vec_stu.push_back(stu);//添加到容器中最后一个元素
		cout << "添加成功！" << endl;
	}
}

void ManageMent::del()
{
	int number = -1;
	cout << "请输入要删除的学生的学号: ";
	cin >> number;
	auto delIt = find(vec_stu.begin(), vec_stu.end(), Student(number));
	if (delIt != vec_stu.end())//如果找到
	{
		vec_stu.erase(delIt);//删除
		cout << "删除成功！" << endl;
	}
	else
	{
		cout << "未找到此学号，删除失败" << endl;
	}
}
void ManageMent::change()
{
	int number = -1;
	cout << "请输入要修改的学生的学号: ";
	cin >> number;

	auto it = find_if(vec_stu.begin(), vec_stu.end(), [number](const Student& s) {
		return s.number == number;
		});
	//Lambda表达式

	if (it != vec_stu.end())
	{
		cout << "请输入学生新的信息:" << endl;
		cout << "请输入<学号、姓名、年级、数学成绩、语文成绩和英语成绩> ";
		cin >> it->number >> it->name >> it->grade >> it->math >> it->chinese >> it->english;
		cout << "修改成功！" << endl;
	}
	else
	{
		cout << "未找到该学号的学生！" << endl;
	}
}


void ManageMent::search()
{
	cout << "*** 选择查找属性     ***" << endl;
	cout << "*** 1,按学号查找     ***" << endl;
	cout << "*** 2,按姓名查找     ***" << endl;
	int op = -1;
	cout << "请选择查找属性>>";
	cin >> op;
	Student stu;
	if (op == 1)
	{
		cout << "输入学号>>";
		cin >> stu.number;
		auto findIt = std::find(vec_stu.begin(), vec_stu.end(), stu);
		if (findIt != vec_stu.end())
		{
			cout << "找到咯^_^ ";
			findIt->display();
		}
		else
		{
			cout << "未找到该学号的学生！" << endl;
		}
	}
	else if (op == 2)
	{
		cout << "输入姓名>>";
		cin >> stu.name;
		bool found = false;
		for (Student& s : vec_stu)
		{
			if (s.name == stu.name)
			{
				cout << "找到咯^_^ ";
				s.display();
				found = true;
			}
		}
		if (!found)
		{
			cout << "未找到该姓名的学生！" << endl;
		}
	}
	else
	{
		cout << "无效选项！" << endl;
	}
}

void ManageMent::sort()
{
	int option;
	cout << "***请选择排序方式：***" << endl;
	cout << "***1. 按学号排序***" << endl;
	cout << "***2. 按总成绩排序***" << endl;
	cout << "***3. 按平均分排序***" << endl;
	cout << "请选择排序方式>> ";
	cin >> option;

	switch (option)
	{
	case 1:
		std::sort(vec_stu.begin(), vec_stu.end(), [](const Student& a, const Student& b) {
			return a.number < b.number;
			});
		cout << "按学号排序成功^-^" << endl;
		break;
	case 2:
		std::sort(vec_stu.begin(), vec_stu.end(), [](const Student& a, const Student& b) {
			return (a.math + a.chinese + a.english) > (b.math + b.chinese + b.english);
			});
		cout << "按总成绩排序成功^-^" << endl;
		break;
	case 3:
		std::sort(vec_stu.begin(), vec_stu.end(), [](const Student& a, const Student& b) {
			return (a.math + a.chinese + a.english) / 3.0 > (b.math + b.chinese + b.english) / 3.0;
			});
		cout << "按平均分排序成功^-^" << endl;
		break;
	default:
		cout << "无效的选项！" << endl;
		break;
	}
}

void ManageMent::readData(const std::string& fileName)
{
	fstream stream(fileName.c_str(), ios::in | ios::binary);
	//同时指定ios::in以读取模式打开和ios::binary以二进制模式打开
	if (!stream.is_open())
	{
		cerr << fileName << " 文件打开失败" << endl;
		return;
	}
	//设置文件流的编码为UTF - 8
		stream.imbue(locale(locale::empty(), new codecvt_utf8<wchar_t>));

	//清除文件中原有数据
	vec_stu.clear();
	tableHeader = "";

	Student stu;
	char buf[1024] = { 0 };
	//读取表头
	tableHeader = buf;
	//读取数据
	while (!stream.eof())//检测文件流是否已经到达文件末尾
	{
		memset(buf, 0, sizeof(buf));//将内存块清零
		stream.getline(buf, 1024);

		// 跳过空行
		if (strlen(buf) == 0) {
			continue;
		}
		stringstream ss(buf);
		ss >> stu.number >> stu.name >> stu.grade >> stu.math >> stu.chinese >> stu.english;
		vec_stu.push_back(stu);
	}
	stream.close();
}

void ManageMent::writeData(const string& fileName)
{
	fstream write(fileName.c_str(), ios::trunc | ios::out);
	if (!write.is_open())
	{
		cerr << fileName << " 文件保存失败";
		return;
	}
	
	// 添加表头信息
	string tableHeader = "学号 姓名 班级 数学成绩 语文成绩 英语成绩\n";
	write.write(tableHeader.c_str(), tableHeader.size());

	// 写入每个学生的数据
	for (auto& val : vec_stu)
	{
		string info = val.formatInfo();
		write.write(info.c_str(), info.size());
	}
	write.close();
}