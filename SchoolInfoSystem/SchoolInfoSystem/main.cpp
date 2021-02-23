#include "function.h"
#include "bachelor.h"
#include "Teacher.h"
#include <vector>
#include <iterator>

vector<Bachelor> bachelorVector;
vector<Teacher> teacherVector;
HANDLE hOut;//����̨���

int main()
{
	int choice;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	system("color f0");
	while (1)
	{
		getHutInfo();
		menu();
		cin >> choice;
		switch (choice)
		{
		case 1:
			entryInfo();//¼����Ϣ
			break;
		case 2:
			searchInfo();//������Ϣ
			break;
		case 3:
			deleteInfo();//ɾ����Ϣ
			break;
		case 4:
			modifyInfo();//�޸���Ϣ
			break;
		case 5:
			studentList();//ѧ����Ϣ
			break;
		case 6:
			teacherList();//��ʦ��Ϣ
			break;
		case 0:
			exit(0);
			break;
		}
	}
}

void menu()
{
	system("cls");
	cout << "\n\n\n\n";
	cout << "\t\t\t";
	printStars(8, "��");
	cout << "HUTѧУ��Ϣ����ϵͳ";
	printStars(8, "��");
	cout << endl;
	printStar(5,"\t\t\t��\t\t\t\t\t         ��\n");
	printStar(4, "\t\t\t��\t\t\t\t\t         ��\n");
	printStar(0,"\t\t\t��\t\t 1. ��¼����Ϣ\t\t         ��\n");
	printStar(1,"\t\t\t��\t\t 2. �������Ϣ\t\t         ��\n");
	printStar(3,"\t\t\t��\t\t 3. ��ɾ����Ϣ\t\t         ��\n");
	printStar(2,"\t\t\t��\t\t 4. ���޸���Ϣ\t\t         ��\n");
	printStar(5,"\t\t\t��\t\t 5. ��ѧ����Ϣ��\t         ��\n");
	printStar(1,"\t\t\t��\t\t 6. ����ʦ��Ϣ��\t         ��\n");
	printStar(3,"\t\t\t��\t\t 0. ���˳�ϵͳ\t\t         ��\n");
	printStar(4,"\t\t\t��\t\t\t\t\t         ��\n");
	printStar(5, "\t\t\t��\t\t\t\t\t         ��\n");
	cout << "\t\t\t";
	printStars(26, "��");
	cout << "\n\n\n";
	printStar(0,"\t\t\t\t\t��ѡ��(0-6):��");
}

void entryInfo()
{
	int isStudent;
	while (1)
	{
		system("cls");
		cout << "\t\t\t����������������������������¼����Ϣ����������������������������\n";
		cout << "��������Ҫ¼�����ݣ���0 �˳���1 ѧ����2 ��ʦ��\n";
		cin >> isStudent;
		if (isStudent == 0)
		{
			return;
		}
		else if (isStudent > 2 || isStudent < 0)
		{
			cout << "����ѡ��Ƿ������������룡\n";
			sleep;
		}
		else 
		{
			break;
		}
	}
	if (isStudent == 2)
	{
		string name, id, phone, province, city, region;
		int courseCount, researchCount;
		cout << "�������ʦ��������";
		cin >> name;
		cout << "�������ʦ�Ĺ��ţ�";
		cin >> id;
		cout << "�������ʦ�ĵ绰��";
		cin >> phone;
		cout << "�������ʦ��סַ��\nʡ��";
		cin >> province;
		cout << "�У�";
		cin >> city;
		cout << "����";
		cin >> region;
		cout << "�������ʦ���ڿγ̵���Ŀ��";
		cin >> courseCount;
		cout << "�������ʦ���ڿγ̵Ŀγ̣�";
		string* course = new string[courseCount];
		for (int i = 0; i < courseCount; ++i)
		{
			cin >> course[i];
		}
		cout << "�������ʦ���о��������Ŀ��";
		cin >> researchCount;
		cout << "�������ʦ���о�����";
		string* research = new string[researchCount];
		for (int i = 0; i < researchCount; ++i)
		{
			cin >> research[i];
		}
		Teacher tmp = Teacher(research, researchCount, Address(province, city, region), phone, id, name, course, courseCount);
		ofstream out;
		out.open("teacher.txt", ios::app);
		out << tmp;
		out.close();
		return;
	}
	string name, id, phone, province, city, region, major; 
	int num;
	cout << "������ѧ����������";
	cin >> name;
	cout << "������ѧ����ѧ�ţ�";
	cin >> id;
	cout << "������ѧ���ĵ绰��";
	cin >> phone;
	cout << "������ѧ����סַ��\nʡ��";
	cin >> province;
	cout << "�У�";
	cin >> city;
	cout << "����";
	cin >> region;
	cout << "������ѧ����רҵ��";
	cin >> major;
	cout << "������ѧ����רҵ�γ���Ŀ��";
	cin >> num;
	cout << "������ѧ����רҵ�γ̺ͳɼ���";
	string *course = new string[num];
	double *grade = new double[num];
	for (int i = 0; i < num; ++i)
	{
		cin >> course[i] >> grade[i];
	}
	Bachelor tmp = Bachelor(grade, major, Address(province, city, region), phone, id, name, course, num);
	ofstream out;
	out.open("student.txt", ios::app);
	out << tmp;
	out.close();
	sleep;
}

void headInfo()
{
	printf("\t\t\t����������������������ѧ����Ϣ����������������������\n\n\n");
	printf("|------------------------------------------------------------------------------------------------------|\n");
	for (int i = 0; i < bachelorVector.size(); ++i)
	{
		if (i % 6 == 4)
		{
			setDefault();
		}
		else
		{
			setColor(i % 6);
		}
		bachelorVector[i].printInfo();
		setDefault();
	}
	cout << "\n\n\t\t\t������������������������ʦ��Ϣ����������������������\n\n\n";
	printf("|---------------------------------------------------------------------------------------|\n");
	for (int i = 0; i < teacherVector.size(); ++i)
	{
		setColor(i % 6);
		teacherVector[i].printInfo();
		setDefault();
	}
}

void subMenuSearch()
{
	printStar(0, "\t\t\t\t\t 1. ����������\n");
	printStar(1, "\t\t\t\t\t 2. ���ֻ�������\n");
	printStar(3, "\t\t\t\t\t 3. ����ݺ�����\n");
	printStar(2, "\t\t\t\t\t 4. ��רҵ����\n");
	printStar(6, "\t\t\t\t\t 0. �ﷵ����һ��\n");
	printStar(0, "\t\t\t\t\t  ��ѡ��(0-4):��");
}

void subMenuDel()
{
	printStar(0, "\t\t\t\t\t 1. ������������ɾ��\n");
	printStar(1, "\t\t\t\t\t 2. ���ֻ���������ɾ��\n");
	printStar(3, "\t\t\t\t\t 3. ����ݺ�������ɾ��\n");
	printStar(2, "\t\t\t\t\t 4. ��רҵ������ɾ��\n");
	printStar(6, "\t\t\t\t\t 0. �ﷵ����һ��\n");
	printStar(0, "\t\t\t\t\t  ��ѡ��(0-4):��");
}

void subMenuModify()
{
	printStar(0, "\t\t\t\t\t 1. �������������޸�\n");
	printStar(1, "\t\t\t\t\t 2. ���ֻ����������޸�\n");
	printStar(3, "\t\t\t\t\t 3. ����ݺ��������޸�\n");
	printStar(2, "\t\t\t\t\t 4. ��רҵ�������޸�\n");
	printStar(6, "\t\t\t\t\t 0. �ﷵ����һ��\n");
	printStar(0, "\t\t\t\t\t  ��ѡ��(0-4):��");

}

void searchInfo()
{
	int num;
	while (1)
	{
		system("cls");
		printf("\t\t\t����������������������������Ϣ����������������������\n\n\n");
		headInfo();
		subMenuSearch();
		cin >> num;
		switch (num)
		{
		case 1:
			nameSearch();
			break;
		case 2:
			phoneSearch();
			break;
		case 3:
			idSearch();
			break;
		case 4:
			majorSearch();
			break;
		case 0:
			return;
		}
		cout << "�������������һ����";
		_getch();
	}
}

void deleteInfo()
{
	int num;
	while (1)
	{
		system("cls");
		printf("\t\t\t����������������������ɾ����Ϣ����������������������\n\n\n");
		headInfo();
		subMenuDel();
		cin >> num;
		switch (num)
		{
		case 1:
			nameSearchAndDel();
			break;
		case 2:
			phoneSearchAndDel();
			break;
		case 3:
			idSearchAndDel();
			break;
		case 4:
			majorSearchAndDel();
			break;
		case 0:
			return;
		}
	}
}

void modifyInfo()
{
	int num;
	while (1)
	{
		system("cls");
		printf("\t\t\t�����������������������޸���Ϣ����������������������\n\n\n");
		headInfo();
		subMenuModify();
		cin >> num;
		switch (num)
		{
		case 1:
			nameSearchAndModify();
			break;
		case 2:
			phoneSearchAndModify();
			break;
		case 3:
			idSearchAndModify();
			break;
		case 4:
			majorSearchAndModify();
			break;
		case 0:
			return;
		}
	}
}

void insertInfo()
{
}

void studentList()
{
	system("cls");
	printf("\t\t\t����������������������ѧ����Ϣ����������������������\n\n\n");
	printf("|-----------------------------------------------------------------------------------------------------------|\n");
	for (int i = 0; i < bachelorVector.size(); ++i)
	{
		if (i % 6 == 4)
		{
			setDefault();
		}
		else
		{
			setColor(i % 6);
		}
		bachelorVector[i].printInfo();
		setDefault();
	}
	cout << "�������������һ����";
	_getch();
}

void teacherList()
{
	system("cls");
	cout << "\t\t\t������������������������ʦ��Ϣ����������������������\n\n\n";
	printf("|-----------------------------------------------------------------------------------------|\n");
	for (int i = 0; i < teacherVector.size(); ++i)
	{
		if (i % 6 == 4)
		{
			setDefault();
		}
		else
		{
			setColor(i % 6);
		}
		teacherVector[i].printInfo();
		setDefault();
	}
	cout << "�������������һ����";
	_getch();
}

void getHutInfo()
{
	ifstream in;
	in.open("student.txt");
	Bachelor bachelorTmp;
	bachelorVector.clear();
	int count = 0;
	while (!in.eof() && in.peek() != EOF)
	{
		in >> bachelorTmp;
		bachelorVector.push_back(bachelorTmp);
	}
	in.close();

	in.open("teacher.txt");
	Teacher teacherTmp;
	teacherVector.clear();
	while (!in.eof() && in.peek() != EOF)
	{
		in >> teacherTmp;
		teacherVector.push_back(teacherTmp);
	}
	in.close();
}


void printStars(int n, string s)
{
	for (int i = 0; i < n; ++i)
	{
		printStar(i % 6, s);
	}
}

void setColor(int num)
{
	switch (num)
	{
	case 0:
		setRed();
		break;
	case 1:
		setBlue();
		break;
	case 2:
		setGreen();
		break;
	case 3:
		setPurple();
		break;
	case 4:
		setYellow();
		break;
	case 5:
		setCyan();
		break;
	}
}

void nameSearch()
{
	cout << "��������Ҫ���ҵ�������";
	string name;
	cin >> name;
	for (int i = 0; i < bachelorVector.size(); ++i)
	{
		if (name == bachelorVector[i].getName())
		{
			bachelorVector[i].printInfo();
		}
	}
	for (int i = 0; i < teacherVector.size(); ++i)
	{
		if (name == teacherVector[i].getName())
		{
			teacherVector[i].printInfo();
		}
	}
}

void phoneSearch()
{
	cout << "��������Ҫ���ҵĵ绰���룺";
	string name;
	cin >> name;
	bool isFind = false;
	for (int i = 0; i < bachelorVector.size(); ++i)
	{
		if (name == bachelorVector[i].getPhoneNumber())
		{
			bachelorVector[i].printInfo();
			isFind = true;
		}
	}
	for (int i = 0; i < teacherVector.size(); ++i)
	{
		if (name == teacherVector[i].getPhoneNumber())
		{
			teacherVector[i].printInfo();
			isFind = true;
		}
	}
	if (!isFind)
	{
		cout << "δ�ҵ�������Ϣ��";
	}
}
void idSearch()
{
	cout << "��������Ҫ���ҵ���ݺţ�";
	string id;
	cin >> id;
	bool isFind = false;
	for (int i = 0; i < bachelorVector.size(); ++i)
	{
		if (id == bachelorVector[i].getIdentifyNumber())
		{
			bachelorVector[i].printInfo();
			isFind = true;
		}
	}
	for (int i = 0; i < teacherVector.size(); ++i)
	{
		if (id == teacherVector[i].getIdentifyNumber())
		{
			teacherVector[i].printInfo();
			isFind = true;
		}
	}
	if (!isFind)
	{
		cout << "δ�ҵ�������Ϣ��";
	}
}

void majorSearch()
{
	cout << "��������Ҫ���ҵ�רҵ��";
	string id;
	cin >> id;
	bool isFind = false;
	for (int i = 0; i < bachelorVector.size(); ++i)
	{
		if (id == bachelorVector[i].getMajor())
		{
			bachelorVector[i].printInfo();
			isFind = true;
		}
	}
	if (!isFind)
	{
		cout << "δ�ҵ�������Ϣ��";
	}
}

void nameSearchAndDel()
{
	cout << "��������Ҫ���ҵ�������";
	string name;
	cin >> name;
	bool isFind = false;
	bool isBelongStu = false;
	int findPosition = 0;
	for (int i = 0; i < bachelorVector.size(); ++i)
	{
		if (name == bachelorVector[i].getName())
		{
			bachelorVector[i].printInfo();
			isFind = true;
			isBelongStu = true;
			findPosition = i;
		}
	}
	for (int i = 0; i < teacherVector.size(); ++i)
	{
		if (name == teacherVector[i].getName())
		{
			teacherVector[i].printInfo();
			isFind = true;
			isBelongStu = false;
			findPosition = i;
		}
	}
	if (!isFind)
	{
		cout << "δ�ҵ�������Ϣ��";
		sleep;
		return;
	}
	cout << "�Ƿ�ɾ������Ϣ��(y / n)";
	char ch;
	cin >> ch;
	if (ch == 'y')
	{
		if (isBelongStu)
		{
			/*
			bachelorVector.erase(beginIterator + findPosition);
			for (int i = 0; i < bachelorVector.size(); ++i)
			{
				bachelorVector[i].printInfo();
			}
			*/
			vector<Bachelor> tmp;
			for (int i = 0; i < bachelorVector.size(); ++i)
			{
				if (i != findPosition)
				{
					tmp.push_back(bachelorVector[i]);
				}
			}
			ofstream out;
			out.open("student.txt", ios::trunc);
			for (int i = 0; i < tmp.size(); ++i)
			{
				out << tmp[i];
				
			}
			out.close();
		}
		else
		{
			vector<Teacher> tmp;
			for (int i = 0; i < teacherVector.size(); ++i)
			{
				if (i != findPosition)
				{
					tmp.push_back(teacherVector[i]);
				}
			}
			ofstream out;
			out.open("teacher.txt", ios::trunc);
			for (int i = 0; i < tmp.size(); ++i)
			{
				out << tmp[i];

			}
			out.close();
		}
		cout << "�޸ĳɹ���";
	}
	else
	{
		cout << "�޸�ʧ�ܣ�";
	}
	sleep;
}

void phoneSearchAndDel()
{
	cout << "��������Ҫ���ҵĵ绰��";
	string name;
	cin >> name;
	bool isFind = false;
	bool isBelongStu = false;
	int findPosition = 0;
	for (int i = 0; i < bachelorVector.size(); ++i)
	{
		if (name == bachelorVector[i].getPhoneNumber())
		{
			bachelorVector[i].printInfo();
			isFind = true;
			isBelongStu = true;
			findPosition = i;
		}
	}
	for (int i = 0; i < teacherVector.size(); ++i)
	{
		if (name == teacherVector[i].getPhoneNumber())
		{
			teacherVector[i].printInfo();
			isFind = true;
			isBelongStu = false;
			findPosition = i;
		}
	}
	if (!isFind)
	{
		cout << "δ�ҵ�������Ϣ��";
		sleep;
		return;
	}
	cout << "�Ƿ�ɾ������Ϣ��(y / n)";
	char ch;
	cin >> ch;
	if (ch == 'y')
	{
		if (isBelongStu)
		{
			vector<Bachelor> tmp;
			for (int i = 0; i < bachelorVector.size(); ++i)
			{
				if (i != findPosition)
				{
					tmp.push_back(bachelorVector[i]);
				}
			}
			ofstream out;
			out.open("student.txt", ios::trunc);
			for (int i = 0; i < tmp.size(); ++i)
			{
				out << tmp[i];

			}
			out.close();
		}
		else
		{
			vector<Teacher> tmp;
			for (int i = 0; i < teacherVector.size(); ++i)
			{
				if (i != findPosition)
				{
					tmp.push_back(teacherVector[i]);
				}
			}
			ofstream out;
			out.open("teacher.txt", ios::trunc);
			for (int i = 0; i < tmp.size(); ++i)
			{
				out << tmp[i];

			}
			out.close();
		}
		cout << "�޸ĳɹ���";
	}
	else
	{
		cout << "�޸�ʧ�ܣ�";
	}
	sleep;
}

void idSearchAndDel()
{
	cout << "��������Ҫ���ҵ���ݺţ�";
	string name;
	cin >> name;
	bool isFind = false;
	bool isBelongStu = false;
	int findPosition = 0;
	for (int i = 0; i < bachelorVector.size(); ++i)
	{
		if (name == bachelorVector[i].getIdentifyNumber())
		{
			bachelorVector[i].printInfo();
			isFind = true;
			isBelongStu = true;
			findPosition = i;
		}
	}
	for (int i = 0; i < teacherVector.size(); ++i)
	{
		if (name == teacherVector[i].getIdentifyNumber())
		{
			teacherVector[i].printInfo();
			isFind = true;
			isBelongStu = false;
			findPosition = i;
		}
	}
	if (!isFind)
	{
		cout << "δ�ҵ�������Ϣ��";
		sleep;
		return;
	}
	cout << "�Ƿ�ɾ������Ϣ��(y / n)";
	char ch;
	cin >> ch;
	if (ch == 'y')
	{
		if (isBelongStu)
		{
			vector<Bachelor> tmp;
			for (int i = 0; i < bachelorVector.size(); ++i)
			{
				if (i != findPosition)
				{
					tmp.push_back(bachelorVector[i]);
				}
			}
			ofstream out;
			out.open("student.txt", ios::trunc);
			for (int i = 0; i < tmp.size(); ++i)
			{
				out << tmp[i];

			}
			out.close();
		}
		else
		{
			vector<Teacher> tmp;
			for (int i = 0; i < teacherVector.size(); ++i)
			{
				if (i != findPosition)
				{
					tmp.push_back(teacherVector[i]);
				}
			}
			ofstream out;
			out.open("teacher.txt", ios::trunc);
			for (int i = 0; i < tmp.size(); ++i)
			{
				out << tmp[i];

			}
			out.close();
		}
		cout << "�޸ĳɹ���";
	}
	else
	{
		cout << "�޸�ʧ�ܣ�";
	}
	sleep;
}

void majorSearchAndDel()
{
	cout << "��������Ҫ���ҵ�רҵ��";
	string name;
	cin >> name;
	bool isFind = false;
	bool isBelongStu = false;
	int findPosition = 0;
	for (int i = 0; i < bachelorVector.size(); ++i)
	{
		if (name == bachelorVector[i].getMajor())
		{
			bachelorVector[i].printInfo();
			isFind = true;
			isBelongStu = true;
			findPosition = i;
		}
	}
	if (!isFind)
	{
		cout << "δ�ҵ�������Ϣ��";
		sleep;
		return;
	}
	cout << "�Ƿ�ɾ������Ϣ��(y / n)";
	char ch;
	cin >> ch;
	if (ch == 'y')
	{
		if (isBelongStu)
		{
			vector<Bachelor> tmp;
			for (int i = 0; i < bachelorVector.size(); ++i)
			{
				if (i != findPosition)
				{
					tmp.push_back(bachelorVector[i]);
				}
			}
			ofstream out;
			out.open("student.txt", ios::trunc);
			for (int i = 0; i < tmp.size(); ++i)
			{
				out << tmp[i];

			}
			out.close();
		}
	}
	else
	{
		cout << "�޸�ʧ�ܣ�";
	}
	sleep;
}

void nameSearchAndModify()
{
	cout << "��������Ҫ���ҵ�������";
	string name;
	cin >> name;
	bool isFind = false;
	bool isBelongStu = false;
	int findPosition = 0;
	for (int i = 0; i < bachelorVector.size(); ++i)
	{
		if (name == bachelorVector[i].getName())
		{
			bachelorVector[i].printInfo();
			isFind = true;
			isBelongStu = true;
			findPosition = i;
		}
	}
	for (int i = 0; i < teacherVector.size(); ++i)
	{
		if (name == teacherVector[i].getName())
		{
			teacherVector[i].printInfo();
			isFind = true;
			isBelongStu = false;
			findPosition = i;
		}
	}
	if (!isFind)
	{
		cout << "δ�ҵ�������Ϣ��";
		sleep;
		return;
	}
	cout << "�Ƿ��޸ĸ���Ϣ��(y / n)";
	char ch;
	cin >> ch;
	if (ch == 'y')
	{
		if (isBelongStu)
		{
			string name, id, phone, province, city, region, major;
			int num;
			cout << "������ѧ����������";
			cin >> name;
			cout << "������ѧ����ѧ�ţ�";
			cin >> id;
			cout << "������ѧ���ĵ绰��";
			cin >> phone;
			cout << "������ѧ����סַ��\nʡ��";
			cin >> province;
			cout << "�У�";
			cin >> city;
			cout << "����";
			cin >> region;
			cout << "������ѧ����רҵ��";
			cin >> major;
			cout << "������ѧ����רҵ�γ���Ŀ��";
			cin >> num;
			cout << "������ѧ����רҵ�γ̺ͳɼ���";
			string* course = new string[num];
			double* grade = new double[num];
			for (int i = 0; i < num; ++i)
			{
				cin >> course[i] >> grade[i];
			}
			Bachelor modifyTmp = Bachelor(grade, major, Address(province, city, region), phone, id, name, course, num);
			vector<Bachelor> tmp;
			for (int i = 0; i < bachelorVector.size(); ++i)
			{
				if (i != findPosition)
				{
					tmp.push_back(bachelorVector[i]);
				}
				else
				{
					tmp.push_back(modifyTmp);
				}
			}
			ofstream out;
			out.open("student.txt", ios::trunc);
			for (int i = 0; i < tmp.size(); ++i)
			{
				out << tmp[i];

			}
			out.close();
		}
		else
		{
			string name, id, phone, province, city, region;
			int courseCount, researchCount;
			cout << "�������ʦ��������";
			cin >> name;
			cout << "�������ʦ�Ĺ��ţ�";
			cin >> id;
			cout << "�������ʦ�ĵ绰��";
			cin >> phone;
			cout << "�������ʦ��סַ��\nʡ��";
			cin >> province;
			cout << "�У�";
			cin >> city;
			cout << "����";
			cin >> region;
			cout << "�������ʦ���ڿγ̵���Ŀ��";
			cin >> courseCount;
			cout << "�������ʦ���ڿγ̵Ŀγ̣�";
			string* course = new string[courseCount];
			for (int i = 0; i < courseCount; ++i)
			{
				cin >> course[i];
			}
			cout << "�������ʦ���о��������Ŀ��";
			cin >> researchCount;
			cout << "�������ʦ���о�����";
			string* research = new string[researchCount];
			for (int i = 0; i < researchCount; ++i)
			{
				cin >> research[i];
			}
			Teacher modifyTmp = Teacher(research, researchCount, Address(province, city, region), phone, id, name, course, courseCount);
			vector<Teacher> tmp;
			for (int i = 0; i < teacherVector.size(); ++i)
			{
				if (i != findPosition)
				{
					tmp.push_back(teacherVector[i]);
				}
				else
				{
					tmp.push_back(modifyTmp);
				}
			}
			ofstream out;
			out.open("teacher.txt", ios::trunc);
			for (int i = 0; i < tmp.size(); ++i)
			{
				out << tmp[i];

			}
			out.close();
		}
		cout << "�޸ĳɹ���";
	}
	else
	{
		cout << "�޸�ʧ�ܣ�";
	}
	sleep;
}

void phoneSearchAndModify()
{
	cout << "��������Ҫ���ҵĵ绰��";
	string name;
	cin >> name;
	bool isFind = false;
	bool isBelongStu = false;
	int findPosition = 0;
	for (int i = 0; i < bachelorVector.size(); ++i)
	{
		if (name == bachelorVector[i].getPhoneNumber())
		{
			bachelorVector[i].printInfo();
			isFind = true;
			isBelongStu = true;
			findPosition = i;
		}
	}
	for (int i = 0; i < teacherVector.size(); ++i)
	{
		if (name == teacherVector[i].getPhoneNumber())
		{
			teacherVector[i].printInfo();
			isFind = true;
			isBelongStu = false;
			findPosition = i;
		}
	}
	if (!isFind)
	{
		cout << "δ�ҵ�������Ϣ��";
		sleep;
		return;
	}
	cout << "�Ƿ��޸ĸ���Ϣ��(y / n)";
	char ch;
	cin >> ch;
	if (ch == 'y')
	{
		if (isBelongStu)
		{
			string name, id, phone, province, city, region, major;
			int num;
			cout << "������ѧ����������";
			cin >> name;
			cout << "������ѧ����ѧ�ţ�";
			cin >> id;
			cout << "������ѧ���ĵ绰��";
			cin >> phone;
			cout << "������ѧ����סַ��\nʡ��";
			cin >> province;
			cout << "�У�";
			cin >> city;
			cout << "����";
			cin >> region;
			cout << "������ѧ����רҵ��";
			cin >> major;
			cout << "������ѧ����רҵ�γ���Ŀ��";
			cin >> num;
			cout << "������ѧ����רҵ�γ̺ͳɼ���";
			string* course = new string[num];
			double* grade = new double[num];
			for (int i = 0; i < num; ++i)
			{
				cin >> course[i] >> grade[i];
			}
			Bachelor modifyTmp = Bachelor(grade, major, Address(province, city, region), phone, id, name, course, num);
			vector<Bachelor> tmp;
			for (int i = 0; i < bachelorVector.size(); ++i)
			{
				if (i != findPosition)
				{
					tmp.push_back(bachelorVector[i]);
				}
				else
				{
					tmp.push_back(modifyTmp);
				}
			}
			ofstream out;
			out.open("student.txt", ios::trunc);
			for (int i = 0; i < tmp.size(); ++i)
			{
				out << tmp[i];

			}
			out.close();
		}
		else
		{
			string name, id, phone, province, city, region;
			int courseCount, researchCount;
			cout << "�������ʦ��������";
			cin >> name;
			cout << "�������ʦ�Ĺ��ţ�";
			cin >> id;
			cout << "�������ʦ�ĵ绰��";
			cin >> phone;
			cout << "�������ʦ��סַ��\nʡ��";
			cin >> province;
			cout << "�У�";
			cin >> city;
			cout << "����";
			cin >> region;
			cout << "�������ʦ���ڿγ̵���Ŀ��";
			cin >> courseCount;
			cout << "�������ʦ���ڿγ̵Ŀγ̣�";
			string* course = new string[courseCount];
			for (int i = 0; i < courseCount; ++i)
			{
				cin >> course[i];
			}
			cout << "�������ʦ���о��������Ŀ��";
			cin >> researchCount;
			cout << "�������ʦ���о�����";
			string* research = new string[researchCount];
			for (int i = 0; i < researchCount; ++i)
			{
				cin >> research[i];
			}
			Teacher modifyTmp = Teacher(research, researchCount, Address(province, city, region), phone, id, name, course, courseCount);
			vector<Teacher> tmp;
			for (int i = 0; i < teacherVector.size(); ++i)
			{
				if (i != findPosition)
				{
					tmp.push_back(teacherVector[i]);
				}
				else
				{
					tmp.push_back(modifyTmp);
				}
			}
			ofstream out;
			out.open("teacher.txt", ios::trunc);
			for (int i = 0; i < tmp.size(); ++i)
			{
				out << tmp[i];

			}
			out.close();
			cout << "�޸ĳɹ���";
		}
	}
	else
	{
		cout << "�޸�ʧ�ܣ�";
	}
	sleep;
}

void idSearchAndModify()
{
	cout << "��������Ҫ���ҵ���ݺţ�";
	string name;
	cin >> name;
	bool isFind = false;
	bool isBelongStu = false;
	int findPosition = 0;
	for (int i = 0; i < bachelorVector.size(); ++i)
	{
		if (name == bachelorVector[i].getIdentifyNumber())
		{
			bachelorVector[i].printInfo();
			isFind = true;
			isBelongStu = true;
			findPosition = i;
		}
	}
	for (int i = 0; i < teacherVector.size(); ++i)
	{
		if (name == teacherVector[i].getIdentifyNumber())
		{
			teacherVector[i].printInfo();
			isFind = true;
			isBelongStu = false;
			findPosition = i;
		}
	}
	if (!isFind)
	{
		cout << "δ�ҵ�������Ϣ��";
		sleep;
		return;
	}
	cout << "�Ƿ��޸ĸ���Ϣ��(y / n)";
	char ch;
	cin >> ch;
	if (ch == 'y')
	{
		if (isBelongStu)
		{
			string name, id, phone, province, city, region, major;
			int num;
			cout << "������ѧ����������";
			cin >> name;
			cout << "������ѧ����ѧ�ţ�";
			cin >> id;
			cout << "������ѧ���ĵ绰��";
			cin >> phone;
			cout << "������ѧ����סַ��\nʡ��";
			cin >> province;
			cout << "�У�";
			cin >> city;
			cout << "����";
			cin >> region;
			cout << "������ѧ����רҵ��";
			cin >> major;
			cout << "������ѧ����רҵ�γ���Ŀ��";
			cin >> num;
			cout << "������ѧ����רҵ�γ̺ͳɼ���";
			string* course = new string[num];
			double* grade = new double[num];
			for (int i = 0; i < num; ++i)
			{
				cin >> course[i] >> grade[i];
			}
			Bachelor modifyTmp = Bachelor(grade, major, Address(province, city, region), phone, id, name, course, num);
			vector<Bachelor> tmp;
			for (int i = 0; i < bachelorVector.size(); ++i)
			{
				if (i != findPosition)
				{
					tmp.push_back(bachelorVector[i]);
				}
				else
				{
					tmp.push_back(modifyTmp);
				}
			}
			ofstream out;
			out.open("student.txt", ios::trunc);
			for (int i = 0; i < tmp.size(); ++i)
			{
				out << tmp[i];

			}
			out.close();
		}
		else
		{
			string name, id, phone, province, city, region;
			int courseCount, researchCount;
			cout << "�������ʦ��������";
			cin >> name;
			cout << "�������ʦ�Ĺ��ţ�";
			cin >> id;
			cout << "�������ʦ�ĵ绰��";
			cin >> phone;
			cout << "�������ʦ��סַ��\nʡ��";
			cin >> province;
			cout << "�У�";
			cin >> city;
			cout << "����";
			cin >> region;
			cout << "�������ʦ���ڿγ̵���Ŀ��";
			cin >> courseCount;
			cout << "�������ʦ���ڿγ̵Ŀγ̣�";
			string* course = new string[courseCount];
			for (int i = 0; i < courseCount; ++i)
			{
				cin >> course[i];
			}
			cout << "�������ʦ���о��������Ŀ��";
			cin >> researchCount;
			cout << "�������ʦ���о�����";
			string* research = new string[researchCount];
			for (int i = 0; i < researchCount; ++i)
			{
				cin >> research[i];
			}
			Teacher modifyTmp = Teacher(research, researchCount, Address(province, city, region), phone, id, name, course, courseCount);
			vector<Teacher> tmp;
			for (int i = 0; i < teacherVector.size(); ++i)
			{
				if (i != findPosition)
				{
					tmp.push_back(teacherVector[i]);
				}
				else
				{
					tmp.push_back(modifyTmp);
				}
			}
			ofstream out;
			out.open("teacher.txt", ios::trunc);
			for (int i = 0; i < tmp.size(); ++i)
			{
				out << tmp[i];

			}
			out.close();
			cout << "�޸ĳɹ���";
		}
	}
	else
	{
		cout << "�޸�ʧ�ܣ�";
	}
	sleep;
}

void majorSearchAndModify()
{
	cout << "��������Ҫ���ҵ�רҵ��";
	string name;
	cin >> name;
	bool isFind = false;
	bool isBelongStu = false;
	int findPosition = 0;
	for (int i = 0; i < bachelorVector.size(); ++i)
	{
		if (name == bachelorVector[i].getIdentifyNumber())
		{
			bachelorVector[i].printInfo();
			isFind = true;
			isBelongStu = true;
			findPosition = i;
		}
	}
	if (!isFind)
	{
		cout << "δ�ҵ�������Ϣ��";
		sleep;
		return;
	}
	cout << "�Ƿ��޸ĸ���Ϣ��(y / n)";
	char ch;
	cin >> ch;
	if (ch == 'y')
	{
		if (isBelongStu)
		{
			string name, id, phone, province, city, region, major;
			int num;
			cout << "������ѧ����������";
			cin >> name;
			cout << "������ѧ����ѧ�ţ�";
			cin >> id;
			cout << "������ѧ���ĵ绰��";
			cin >> phone;
			cout << "������ѧ����סַ��\nʡ��";
			cin >> province;
			cout << "�У�";
			cin >> city;
			cout << "����";
			cin >> region;
			cout << "������ѧ����רҵ��";
			cin >> major;
			cout << "������ѧ����רҵ�γ���Ŀ��";
			cin >> num;
			cout << "������ѧ����רҵ�γ̺ͳɼ���";
			string* course = new string[num];
			double* grade = new double[num];
			for (int i = 0; i < num; ++i)
			{
				cin >> course[i] >> grade[i];
			}
			Bachelor modifyTmp = Bachelor(grade, major, Address(province, city, region), phone, id, name, course, num);
			vector<Bachelor> tmp;
			for (int i = 0; i < bachelorVector.size(); ++i)
			{
				if (i != findPosition)
				{
					tmp.push_back(bachelorVector[i]);
				}
				else
				{
					tmp.push_back(modifyTmp);
				}
			}
			ofstream out;
			out.open("student.txt", ios::trunc);
			for (int i = 0; i < tmp.size(); ++i)
			{
				out << tmp[i];

			}
			out.close();
		}
	}
	else
	{
		cout << "�޸�ʧ�ܣ�";
	}
	sleep;
}

void printStar(int num,string s)
{
	setColor(num);
	cout << s;
	setDefault();
}

void setRed()
{
	SetConsoleTextAttribute(hOut, FOREGROUND_INTENSITY | BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED);
}

void setBlue()
{
	SetConsoleTextAttribute(hOut, FOREGROUND_INTENSITY | BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_BLUE);
}

void setGreen()
{
	SetConsoleTextAttribute(hOut, FOREGROUND_INTENSITY | BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_GREEN);
}

void setPurple()
{
	SetConsoleTextAttribute(hOut, FOREGROUND_INTENSITY | BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | FOREGROUND_BLUE);
}

void setYellow()
{
	SetConsoleTextAttribute(hOut, FOREGROUND_INTENSITY | BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
}

void setCyan()
{
	SetConsoleTextAttribute(hOut, FOREGROUND_INTENSITY | BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_BLUE | FOREGROUND_GREEN);
}

void setDefault()
{
	SetConsoleTextAttribute(hOut, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
}