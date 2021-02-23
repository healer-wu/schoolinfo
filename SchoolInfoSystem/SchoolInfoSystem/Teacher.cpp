#include "Teacher.h"

Teacher::Teacher()
{
	this->researchDirCount = 1;
	this->researchDirection = new string[this->researchDirCount];
	this->researchDirection[0] = "AI������������";
}

Teacher::Teacher(string* research, int count, Info info, Course course):Info(info), Course(course)
{
	this->researchDirCount = count;
	this->researchDirection = new string[this->researchDirCount];
	for (int i = 0; i < this->researchDirCount; ++i)
	{
		this->researchDirection[i] = research[i];
	}
}

Teacher::Teacher(string* research, int count, Address address, string phoneNumber, string identifyNumber, string name, Course course) : Info(address, phoneNumber, identifyNumber, name), Course(course)
{
	this->researchDirCount = count;
	this->researchDirection = new string[this->researchDirCount];
	for (int i = 0; i < this->researchDirCount; ++i)
	{
		this->researchDirection[i] = research[i];
	}
}

Teacher::Teacher(string* research, int researchCount, Address address, string phoneNumber, string identifyNumber, string name, string* course, int count): Info(address, phoneNumber, identifyNumber, name), Course(course, count)
{
	this->researchDirCount = researchCount;
	this->researchDirection = new string[this->researchDirCount];
	for (int i = 0; i < this->researchDirCount; ++i)
	{
		this->researchDirection[i] = research[i];
	}
}

Teacher::Teacher(const Teacher& tmp):Info(tmp),Course(tmp)
{
	this->researchDirection = new string[tmp.researchDirCount];
	this->researchDirCount = tmp.researchDirCount;
	for (int i = 0; i < tmp.researchDirCount; ++i)
	{
		this->researchDirection[i] = tmp.researchDirection[i];
	}
}

Teacher::~Teacher()
{
	delete[]this->researchDirection;
	researchDirection = NULL;
}

string* Teacher::getResearchDirection()
{
	return this->researchDirection;
}

int Teacher::getResearchCount()
{
	return this->researchDirCount;
}

bool Teacher::setResearch(string* research, int count)
{
	delete[]this->researchDirection;
	researchDirCount = count;
	researchDirection = new string[count];
	for (int i = 0; i < researchDirCount; ++i)
	{
		researchDirection[i] = research[i];
	}
	return true;
}

void Teacher::printInfo()
{
	printf("|��ʦ������%5s|��ʦѧ�ţ�%5s|��ʦ�绰���룺%10s|��ʦ��ַ��%15s|\n", this->getName().c_str(), this->getIdentifyNumber().c_str(), this->getPhoneNumber().c_str(), this->getAddressStr().c_str());
	printTeaInfo();
	setDefault();
	printf("|-----------------------------------------------------------------------------------------|\n");
}

void Teacher::printTeaInfo()
{
	int count = this->getCourseCount();
	printf("|\t|��ʦ���ڿγ���Ŀ��%2d|��ʦ���ڿγ̣�                                              |\n", count);
	string* name = this->getCourse();
	for (int i = 0; i < count; ++i)
	{
		printf("|\t|%5s|\n", name[i].c_str());
	}
	printf("|\t|��ʦ�о�������Ŀ��%2d|��ʦ�о�����                                              |\n", researchDirCount);
	for (int i = 0; i < researchDirCount; ++i)
	{
		printf("|\t\t|%5s|\n", researchDirection[i].c_str());
	}
}





