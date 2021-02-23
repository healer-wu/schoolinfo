#include "bachelor.h"

Bachelor::Bachelor()
{
	this->courseGrade = new double[1];
	(this->courseGrade)[0] = 88;
	this->major = "计算机专业";
}

Bachelor::Bachelor(double* grade, string major,Info info, Course course): Info(info), Course(course)
{
	int count = course.getCourseCount();
	this->courseGrade = new double[count];
	for (int i = 0; i < count; ++i)
	{
		(this->courseGrade)[i] = grade[i];
	}
	this->major = major;
}

Bachelor::Bachelor(double* grade, string major, Address address, string phone, string num, string name, Course course): Info(address, phone, num, name), Course(course)
{
	int count = course.getCourseCount();
	this->courseGrade = new double[count];
	for (int i = 0; i < count; ++i)
	{
		(this->courseGrade)[i] = grade[i];
	}
	this->major = major;
}

Bachelor::Bachelor(double* grade, string major, Address address, string phone, string num, string name, string* course, int count): Info(address, phone, num, name), Course(course, count)
{
	this->courseGrade = new double[count];
	for (int i = 0; i < count; ++i)
	{
		(this->courseGrade)[i] = grade[i];
	}
	this->major = major;
}

Bachelor::Bachelor(const Bachelor& tmp):Info(tmp),Course(tmp)
{
	this->major = tmp.major;
	this->courseGrade = new double[this->getCourseCount()];
	for (int i = 0; i < this->getCourseCount(); ++i)
	{
		this->courseGrade[i] = tmp.courseGrade[i];
	}
}

Bachelor::~Bachelor()
{
	delete[]this->courseGrade;
	this->courseGrade = NULL;
}

double* Bachelor::getCourseGrade()
{
	return this->courseGrade;
}

string Bachelor::getMajor()
{
	return this->major;
}

bool Bachelor::setCourseGrade(  double* grade,   int num)
{
	delete[](this->courseGrade);
	this->courseGrade = new double[num];
	for (int i = 0; i < num; ++i)
	{
		(this->courseGrade)[i] = grade[i];
	}
	return true;
}

bool Bachelor::setMajor(string  major)
{
	this->major = major;
	return true;
}

void Bachelor::printInfo()
{
	printf("|学生姓名：%-5s|学生学号：%-5s|学生电话号码：%-13s|学生地址：%-15s|学生专业：%-8s|\n", this->getName().c_str(), this->getIdentifyNumber().c_str(), this->getPhoneNumber().c_str(), this->getAddressStr().c_str(), this->getMajor().c_str());
	printCourseInfo();
	setDefault();
	printf("|-----------------------------------------------------------------------------------------------------------|\n");
}

void Bachelor::printCourseInfo()
{
	int count = this->getCourseCount();
	printf("|\t|学生课程数目：%2d|学生课程成绩：                                                                    |\n", count);
	string* name = this->getCourse();
	for (int i = 0; i < count; ++i)
	{
		printf("|\t\t|%-5s - %-.0lf|\n", name[i].c_str(), courseGrade[i]);
	}
}


