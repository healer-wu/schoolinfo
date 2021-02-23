#include "function.h"
#include "bachelor.h"
#include "Teacher.h"
#include <vector>
#include <iterator>

vector<Bachelor> bachelorVector;
vector<Teacher> teacherVector;
HANDLE hOut;//控制台句柄

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
			entryInfo();//录入信息
			break;
		case 2:
			searchInfo();//搜索信息
			break;
		case 3:
			deleteInfo();//删除信息
			break;
		case 4:
			modifyInfo();//修改信息
			break;
		case 5:
			studentList();//学生信息
			break;
		case 6:
			teacherList();//老师信息
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
	printStars(8, "★");
	cout << "HUT学校信息管理系统";
	printStars(8, "★");
	cout << endl;
	printStar(5,"\t\t\t●\t\t\t\t\t         ●\n");
	printStar(4, "\t\t\t●\t\t\t\t\t         ●\n");
	printStar(0,"\t\t\t●\t\t 1. ★录入信息\t\t         ●\n");
	printStar(1,"\t\t\t●\t\t 2. ★查找信息\t\t         ●\n");
	printStar(3,"\t\t\t●\t\t 3. ★删除信息\t\t         ●\n");
	printStar(2,"\t\t\t●\t\t 4. ★修改信息\t\t         ●\n");
	printStar(5,"\t\t\t●\t\t 5. ★学生信息表\t         ●\n");
	printStar(1,"\t\t\t●\t\t 6. ★老师信息表\t         ●\n");
	printStar(3,"\t\t\t●\t\t 0. ★退出系统\t\t         ●\n");
	printStar(4,"\t\t\t●\t\t\t\t\t         ●\n");
	printStar(5, "\t\t\t●\t\t\t\t\t         ●\n");
	cout << "\t\t\t";
	printStars(26, "★");
	cout << "\n\n\n";
	printStar(0,"\t\t\t\t\t请选择(0-6):★");
}

void entryInfo()
{
	int isStudent;
	while (1)
	{
		system("cls");
		cout << "\t\t\t··············录入信息··············\n";
		cout << "请输入你要录入的身份：（0 退出，1 学生，2 教师）\n";
		cin >> isStudent;
		if (isStudent == 0)
		{
			return;
		}
		else if (isStudent > 2 || isStudent < 0)
		{
			cout << "输入选择非法，请重新输入！\n";
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
		cout << "请输入教师的姓名：";
		cin >> name;
		cout << "请输入教师的工号：";
		cin >> id;
		cout << "请输入教师的电话：";
		cin >> phone;
		cout << "请输入教师的住址：\n省：";
		cin >> province;
		cout << "市：";
		cin >> city;
		cout << "区：";
		cin >> region;
		cout << "请输入教师教授课程的数目：";
		cin >> courseCount;
		cout << "请输入教师教授课程的课程：";
		string* course = new string[courseCount];
		for (int i = 0; i < courseCount; ++i)
		{
			cin >> course[i];
		}
		cout << "请输入教师的研究方向的数目：";
		cin >> researchCount;
		cout << "请输入教师的研究方向：";
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
	cout << "请输入学生的姓名：";
	cin >> name;
	cout << "请输入学生的学号：";
	cin >> id;
	cout << "请输入学生的电话：";
	cin >> phone;
	cout << "请输入学生的住址：\n省：";
	cin >> province;
	cout << "市：";
	cin >> city;
	cout << "区：";
	cin >> region;
	cout << "请输入学生的专业：";
	cin >> major;
	cout << "请输入学生的专业课程数目：";
	cin >> num;
	cout << "请输入学生的专业课程和成绩：";
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
	printf("\t\t\t···········学生信息···········\n\n\n");
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
	cout << "\n\n\t\t\t···········教师信息···········\n\n\n";
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
	printStar(0, "\t\t\t\t\t 1. ★姓名搜索\n");
	printStar(1, "\t\t\t\t\t 2. ★手机号搜索\n");
	printStar(3, "\t\t\t\t\t 3. ★身份号搜索\n");
	printStar(2, "\t\t\t\t\t 4. ★专业搜索\n");
	printStar(6, "\t\t\t\t\t 0. ★返回上一级\n");
	printStar(0, "\t\t\t\t\t  请选择(0-4):★");
}

void subMenuDel()
{
	printStar(0, "\t\t\t\t\t 1. ★姓名搜索并删除\n");
	printStar(1, "\t\t\t\t\t 2. ★手机号搜索并删除\n");
	printStar(3, "\t\t\t\t\t 3. ★身份号搜索并删除\n");
	printStar(2, "\t\t\t\t\t 4. ★专业搜索并删除\n");
	printStar(6, "\t\t\t\t\t 0. ★返回上一级\n");
	printStar(0, "\t\t\t\t\t  请选择(0-4):★");
}

void subMenuModify()
{
	printStar(0, "\t\t\t\t\t 1. ★姓名搜索并修改\n");
	printStar(1, "\t\t\t\t\t 2. ★手机号搜索并修改\n");
	printStar(3, "\t\t\t\t\t 3. ★身份号搜索并修改\n");
	printStar(2, "\t\t\t\t\t 4. ★专业搜索并修改\n");
	printStar(6, "\t\t\t\t\t 0. ★返回上一级\n");
	printStar(0, "\t\t\t\t\t  请选择(0-4):★");

}

void searchInfo()
{
	int num;
	while (1)
	{
		system("cls");
		printf("\t\t\t···········搜索信息···········\n\n\n");
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
		cout << "按任意键返回上一级：";
		_getch();
	}
}

void deleteInfo()
{
	int num;
	while (1)
	{
		system("cls");
		printf("\t\t\t···········删除信息···········\n\n\n");
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
		printf("\t\t\t···········修改信息···········\n\n\n");
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
	printf("\t\t\t···········学生信息···········\n\n\n");
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
	cout << "按任意键返回上一级：";
	_getch();
}

void teacherList()
{
	system("cls");
	cout << "\t\t\t···········教师信息···········\n\n\n";
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
	cout << "按任意键返回上一级：";
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
	cout << "请输入你要查找的姓名：";
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
	cout << "请输入你要查找的电话号码：";
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
		cout << "未找到该条信息！";
	}
}
void idSearch()
{
	cout << "请输入你要查找的身份号：";
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
		cout << "未找到该条信息！";
	}
}

void majorSearch()
{
	cout << "请输入你要查找的专业：";
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
		cout << "未找到该条信息！";
	}
}

void nameSearchAndDel()
{
	cout << "请输入你要查找的姓名：";
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
		cout << "未找到该条信息！";
		sleep;
		return;
	}
	cout << "是否删除该信息：(y / n)";
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
		cout << "修改成功！";
	}
	else
	{
		cout << "修改失败！";
	}
	sleep;
}

void phoneSearchAndDel()
{
	cout << "请输入你要查找的电话：";
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
		cout << "未找到该条信息！";
		sleep;
		return;
	}
	cout << "是否删除该信息：(y / n)";
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
		cout << "修改成功！";
	}
	else
	{
		cout << "修改失败！";
	}
	sleep;
}

void idSearchAndDel()
{
	cout << "请输入你要查找的身份号：";
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
		cout << "未找到该条信息！";
		sleep;
		return;
	}
	cout << "是否删除该信息：(y / n)";
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
		cout << "修改成功！";
	}
	else
	{
		cout << "修改失败！";
	}
	sleep;
}

void majorSearchAndDel()
{
	cout << "请输入你要查找的专业：";
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
		cout << "未找到该条信息！";
		sleep;
		return;
	}
	cout << "是否删除该信息：(y / n)";
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
		cout << "修改失败！";
	}
	sleep;
}

void nameSearchAndModify()
{
	cout << "请输入你要查找的姓名：";
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
		cout << "未找到该条信息！";
		sleep;
		return;
	}
	cout << "是否修改该信息：(y / n)";
	char ch;
	cin >> ch;
	if (ch == 'y')
	{
		if (isBelongStu)
		{
			string name, id, phone, province, city, region, major;
			int num;
			cout << "请输入学生的姓名：";
			cin >> name;
			cout << "请输入学生的学号：";
			cin >> id;
			cout << "请输入学生的电话：";
			cin >> phone;
			cout << "请输入学生的住址：\n省：";
			cin >> province;
			cout << "市：";
			cin >> city;
			cout << "区：";
			cin >> region;
			cout << "请输入学生的专业：";
			cin >> major;
			cout << "请输入学生的专业课程数目：";
			cin >> num;
			cout << "请输入学生的专业课程和成绩：";
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
			cout << "请输入教师的姓名：";
			cin >> name;
			cout << "请输入教师的工号：";
			cin >> id;
			cout << "请输入教师的电话：";
			cin >> phone;
			cout << "请输入教师的住址：\n省：";
			cin >> province;
			cout << "市：";
			cin >> city;
			cout << "区：";
			cin >> region;
			cout << "请输入教师教授课程的数目：";
			cin >> courseCount;
			cout << "请输入教师教授课程的课程：";
			string* course = new string[courseCount];
			for (int i = 0; i < courseCount; ++i)
			{
				cin >> course[i];
			}
			cout << "请输入教师的研究方向的数目：";
			cin >> researchCount;
			cout << "请输入教师的研究方向：";
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
		cout << "修改成功！";
	}
	else
	{
		cout << "修改失败！";
	}
	sleep;
}

void phoneSearchAndModify()
{
	cout << "请输入你要查找的电话：";
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
		cout << "未找到该条信息！";
		sleep;
		return;
	}
	cout << "是否修改该信息：(y / n)";
	char ch;
	cin >> ch;
	if (ch == 'y')
	{
		if (isBelongStu)
		{
			string name, id, phone, province, city, region, major;
			int num;
			cout << "请输入学生的姓名：";
			cin >> name;
			cout << "请输入学生的学号：";
			cin >> id;
			cout << "请输入学生的电话：";
			cin >> phone;
			cout << "请输入学生的住址：\n省：";
			cin >> province;
			cout << "市：";
			cin >> city;
			cout << "区：";
			cin >> region;
			cout << "请输入学生的专业：";
			cin >> major;
			cout << "请输入学生的专业课程数目：";
			cin >> num;
			cout << "请输入学生的专业课程和成绩：";
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
			cout << "请输入教师的姓名：";
			cin >> name;
			cout << "请输入教师的工号：";
			cin >> id;
			cout << "请输入教师的电话：";
			cin >> phone;
			cout << "请输入教师的住址：\n省：";
			cin >> province;
			cout << "市：";
			cin >> city;
			cout << "区：";
			cin >> region;
			cout << "请输入教师教授课程的数目：";
			cin >> courseCount;
			cout << "请输入教师教授课程的课程：";
			string* course = new string[courseCount];
			for (int i = 0; i < courseCount; ++i)
			{
				cin >> course[i];
			}
			cout << "请输入教师的研究方向的数目：";
			cin >> researchCount;
			cout << "请输入教师的研究方向：";
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
			cout << "修改成功！";
		}
	}
	else
	{
		cout << "修改失败！";
	}
	sleep;
}

void idSearchAndModify()
{
	cout << "请输入你要查找的身份号：";
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
		cout << "未找到该条信息！";
		sleep;
		return;
	}
	cout << "是否修改该信息：(y / n)";
	char ch;
	cin >> ch;
	if (ch == 'y')
	{
		if (isBelongStu)
		{
			string name, id, phone, province, city, region, major;
			int num;
			cout << "请输入学生的姓名：";
			cin >> name;
			cout << "请输入学生的学号：";
			cin >> id;
			cout << "请输入学生的电话：";
			cin >> phone;
			cout << "请输入学生的住址：\n省：";
			cin >> province;
			cout << "市：";
			cin >> city;
			cout << "区：";
			cin >> region;
			cout << "请输入学生的专业：";
			cin >> major;
			cout << "请输入学生的专业课程数目：";
			cin >> num;
			cout << "请输入学生的专业课程和成绩：";
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
			cout << "请输入教师的姓名：";
			cin >> name;
			cout << "请输入教师的工号：";
			cin >> id;
			cout << "请输入教师的电话：";
			cin >> phone;
			cout << "请输入教师的住址：\n省：";
			cin >> province;
			cout << "市：";
			cin >> city;
			cout << "区：";
			cin >> region;
			cout << "请输入教师教授课程的数目：";
			cin >> courseCount;
			cout << "请输入教师教授课程的课程：";
			string* course = new string[courseCount];
			for (int i = 0; i < courseCount; ++i)
			{
				cin >> course[i];
			}
			cout << "请输入教师的研究方向的数目：";
			cin >> researchCount;
			cout << "请输入教师的研究方向：";
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
			cout << "修改成功！";
		}
	}
	else
	{
		cout << "修改失败！";
	}
	sleep;
}

void majorSearchAndModify()
{
	cout << "请输入你要查找的专业：";
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
		cout << "未找到该条信息！";
		sleep;
		return;
	}
	cout << "是否修改该信息：(y / n)";
	char ch;
	cin >> ch;
	if (ch == 'y')
	{
		if (isBelongStu)
		{
			string name, id, phone, province, city, region, major;
			int num;
			cout << "请输入学生的姓名：";
			cin >> name;
			cout << "请输入学生的学号：";
			cin >> id;
			cout << "请输入学生的电话：";
			cin >> phone;
			cout << "请输入学生的住址：\n省：";
			cin >> province;
			cout << "市：";
			cin >> city;
			cout << "区：";
			cin >> region;
			cout << "请输入学生的专业：";
			cin >> major;
			cout << "请输入学生的专业课程数目：";
			cin >> num;
			cout << "请输入学生的专业课程和成绩：";
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
		cout << "修改失败！";
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