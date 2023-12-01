#include "ManageMent.h"
#include<sstream>//�ַ�����������������
#include<fstream>//��ȡ��д���ļ�
#include<string>
#include<algorithm>

#include <locale>
//���ػ����ṩ�����ַ����롢���ڡ�ʱ�䡢���ҡ����ָ�ʽ�ȱ��ػ������Ĺ��ܡ�
#include <codecvt>
//�ַ�����ת��
ManageMent::ManageMent() {//���ض�д�ļ�
	writeData("D:\\student.txt");
	readData("D:\\test.txt");
}
void ManageMent::run()
{
	menu();
	while (true)
	{
		cout << "��ѡ��˵�>>";
		int op = -1;
		cin >> op;
		switch (op)
		{
		case 0:
			system("cls");//����
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
	cout << "***** ѧ���ɼ�����ϵͳ *****" << endl;
	cout << "***** 1,�鿴ѧ��       *****" << endl;
	cout << "***** 2,���ѧ��       *****" << endl;
	cout << "***** 3,ɾ��ѧ��       *****" << endl;
	cout << "***** 4,�޸�ѧ��       *****" << endl;
	cout << "***** 5,����ѧ��       *****" << endl;
	cout << "***** 6,����           *****" << endl;
	cout << "***** 7,д�ļ�         *****" << endl;
	cout << "***** 8,���ļ�         *****" << endl;
	cout << "***** 0,�����Ļ       *****" << endl;
	cout << endl;
}

void ManageMent::show()
{
	cout << this->tableHeader << endl;//������ı�ͷ��Ϣ
	for (auto& val : vec_stu)//auto �Զ��Ƶ� val ������ʹ���������е�Ԫ��������ƥ��
	{
		val.display();
	}
	cout <<"****************************"<< endl;
	cout << "��" << vec_stu.size() << "������" << endl;
}

void ManageMent::add()
{
	Student stu;
	cout << "������<ѧ�š��������꼶����ѧ�ɼ������ĳɼ���Ӣ��ɼ�> ";
	cin >> stu.number >> stu.name >> stu.grade >> stu.math >> stu.chinese >> stu.english;

	// ���ѧ���Ƿ��ظ�
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
		cout << "��ѧ���Ѵ��ڣ������벻�ظ���ѧ�ţ�" << endl;
	}
	else
	{
		vec_stu.push_back(stu);//��ӵ����������һ��Ԫ��
		cout << "��ӳɹ���" << endl;
	}
}

void ManageMent::del()
{
	int number = -1;
	cout << "������Ҫɾ����ѧ����ѧ��: ";
	cin >> number;
	auto delIt = find(vec_stu.begin(), vec_stu.end(), Student(number));
	if (delIt != vec_stu.end())//����ҵ�
	{
		vec_stu.erase(delIt);//ɾ��
		cout << "ɾ���ɹ���" << endl;
	}
	else
	{
		cout << "δ�ҵ���ѧ�ţ�ɾ��ʧ��" << endl;
	}
}
void ManageMent::change()
{
	int number = -1;
	cout << "������Ҫ�޸ĵ�ѧ����ѧ��: ";
	cin >> number;

	auto it = find_if(vec_stu.begin(), vec_stu.end(), [number](const Student& s) {
		return s.number == number;
		});
	//Lambda���ʽ

	if (it != vec_stu.end())
	{
		cout << "������ѧ���µ���Ϣ:" << endl;
		cout << "������<ѧ�š��������꼶����ѧ�ɼ������ĳɼ���Ӣ��ɼ�> ";
		cin >> it->number >> it->name >> it->grade >> it->math >> it->chinese >> it->english;
		cout << "�޸ĳɹ���" << endl;
	}
	else
	{
		cout << "δ�ҵ���ѧ�ŵ�ѧ����" << endl;
	}
}


void ManageMent::search()
{
	cout << "*** ѡ���������     ***" << endl;
	cout << "*** 1,��ѧ�Ų���     ***" << endl;
	cout << "*** 2,����������     ***" << endl;
	int op = -1;
	cout << "��ѡ���������>>";
	cin >> op;
	Student stu;
	if (op == 1)
	{
		cout << "����ѧ��>>";
		cin >> stu.number;
		auto findIt = std::find(vec_stu.begin(), vec_stu.end(), stu);
		if (findIt != vec_stu.end())
		{
			cout << "�ҵ���^_^ ";
			findIt->display();
		}
		else
		{
			cout << "δ�ҵ���ѧ�ŵ�ѧ����" << endl;
		}
	}
	else if (op == 2)
	{
		cout << "��������>>";
		cin >> stu.name;
		bool found = false;
		for (Student& s : vec_stu)
		{
			if (s.name == stu.name)
			{
				cout << "�ҵ���^_^ ";
				s.display();
				found = true;
			}
		}
		if (!found)
		{
			cout << "δ�ҵ���������ѧ����" << endl;
		}
	}
	else
	{
		cout << "��Чѡ�" << endl;
	}
}

void ManageMent::sort()
{
	int option;
	cout << "***��ѡ������ʽ��***" << endl;
	cout << "***1. ��ѧ������***" << endl;
	cout << "***2. ���ܳɼ�����***" << endl;
	cout << "***3. ��ƽ��������***" << endl;
	cout << "��ѡ������ʽ>> ";
	cin >> option;

	switch (option)
	{
	case 1:
		std::sort(vec_stu.begin(), vec_stu.end(), [](const Student& a, const Student& b) {
			return a.number < b.number;
			});
		cout << "��ѧ������ɹ�^-^" << endl;
		break;
	case 2:
		std::sort(vec_stu.begin(), vec_stu.end(), [](const Student& a, const Student& b) {
			return (a.math + a.chinese + a.english) > (b.math + b.chinese + b.english);
			});
		cout << "���ܳɼ�����ɹ�^-^" << endl;
		break;
	case 3:
		std::sort(vec_stu.begin(), vec_stu.end(), [](const Student& a, const Student& b) {
			return (a.math + a.chinese + a.english) / 3.0 > (b.math + b.chinese + b.english) / 3.0;
			});
		cout << "��ƽ��������ɹ�^-^" << endl;
		break;
	default:
		cout << "��Ч��ѡ�" << endl;
		break;
	}
}

void ManageMent::readData(const std::string& fileName)
{
	fstream stream(fileName.c_str(), ios::in | ios::binary);
	//ͬʱָ��ios::in�Զ�ȡģʽ�򿪺�ios::binary�Զ�����ģʽ��
	if (!stream.is_open())
	{
		cerr << fileName << " �ļ���ʧ��" << endl;
		return;
	}
	//�����ļ����ı���ΪUTF - 8
		stream.imbue(locale(locale::empty(), new codecvt_utf8<wchar_t>));

	//����ļ���ԭ������
	vec_stu.clear();
	tableHeader = "";

	Student stu;
	char buf[1024] = { 0 };
	//��ȡ��ͷ
	tableHeader = buf;
	//��ȡ����
	while (!stream.eof())//����ļ����Ƿ��Ѿ������ļ�ĩβ
	{
		memset(buf, 0, sizeof(buf));//���ڴ������
		stream.getline(buf, 1024);

		// ��������
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
		cerr << fileName << " �ļ�����ʧ��";
		return;
	}
	
	// ��ӱ�ͷ��Ϣ
	string tableHeader = "ѧ�� ���� �༶ ��ѧ�ɼ� ���ĳɼ� Ӣ��ɼ�\n";
	write.write(tableHeader.c_str(), tableHeader.size());

	// д��ÿ��ѧ��������
	for (auto& val : vec_stu)
	{
		string info = val.formatInfo();
		write.write(info.c_str(), info.size());
	}
	write.close();
}