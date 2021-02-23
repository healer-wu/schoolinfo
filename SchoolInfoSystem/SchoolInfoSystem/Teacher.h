#pragma once
#include "Info.h"
#include "Course.h"
class Teacher : public Info, public Course
{
private:
	string* researchDirection;
	int researchDirCount;
	void printTeaInfo();
public:
	Teacher();
	Teacher(string* research, int count, Info  info, Course course);
	Teacher(string* research, int count, Address address, string phoneNumber, string identifyNumber, string name, Course course);
	Teacher(string* research, int researchCount, Address address, string phoneNumber, string identifyNumber, string name, string* course, int count);
	Teacher(const Teacher& tmp);
	~Teacher();
	string* getResearchDirection();
	int getResearchCount();
	bool setResearch(string* research, int count);
	void printInfo();

	friend ofstream& operator<<(ofstream& out, Teacher& tmp)
	{
		out << endl;
		out << tmp.getName() << endl;
		out << tmp.getIdentifyNumber() << endl;
		out << tmp.getPhoneNumber() << endl;
		out << tmp.getProvince() << endl;
		out << tmp.getCity() << endl;
		out << tmp.getRegion() << endl;
		out << tmp.getCourseCount() << endl;
		for (int i = 0; i < tmp.getCourseCount(); ++i)
		{
			out << tmp.getCourse()[i] << endl;
		}
		out << tmp.getResearchCount() << endl;
		for (int i = 0; i < tmp.getResearchCount(); ++i)
		{
			out << tmp.getResearchDirection()[i];
			if (i != tmp.getResearchCount() - 1)
			{
				out << endl;
			}
		}
		return out;
	}

	friend ifstream& operator>>(ifstream& is, Teacher& tmp)
	{
		string name, id, tel, province, city, region;
		int courseNum, researchCount;
		is >> name;
		is >> id;
		is >> tel;
		is >> province;
		is >> city;
		is >> region;
		is >> courseNum;
		string* course = new string[courseNum];
		for (int i = 0; i < courseNum; ++i)
		{
			is >> course[i];
		}
		is >> researchCount;
		string* research = new string[researchCount];
		for (int i = 0; i < researchCount; ++i)
		{
			is >> research[i];
		}
		tmp.setName(name);
		tmp.setPhoneNumber(tel);
		tmp.setIdentifyNumber(id);
		tmp.setProvince(province);
		tmp.setCity(city);
		tmp.setRegion(region);
		tmp.setCourse(course, courseNum);
		tmp.setResearch(research, researchCount);
		delete[]course;
		delete[]research;
		return is;
	}
};
