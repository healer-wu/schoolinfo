#pragma once
#include "Info.h"
#include "Course.h"
class Bachelor: public Info, public Course
{
private:
	double* courseGrade;
	string major;
	void printCourseInfo();
public:
	Bachelor();
	Bachelor(double* grade, string major, Info info, Course course);
	Bachelor(double* grade, string major, Address address, string phone, string num, string name, Course course);
	Bachelor(double* grade, string major, Address address, string phone, string num, string name, string* course, int count);
	Bachelor(const Bachelor& tmp);
	~Bachelor();
	double* getCourseGrade();
	string getMajor();
	bool setCourseGrade(double* grade, int num);
	bool setMajor(string major);
	void printInfo();
	friend ofstream& operator<<(ofstream& out, Bachelor& tmp)
	{
		out << endl << tmp.getName() << endl;
		out << tmp.getIdentifyNumber() << endl;
		out << tmp.getPhoneNumber() << endl;
		out << tmp.getProvince() << endl;
		out << tmp.getCity() << endl;
		out << tmp.getRegion() << endl;
		out << tmp.getMajor() << endl;
		out << tmp.getCourseCount() << endl;
		for (int i = 0; i < tmp.getCourseCount(); ++i)
		{
			out << tmp.getCourse()[i] << " " << tmp.getCourseGrade()[i];
			if (i != tmp.getCourseCount() - 1)
			{
				out << endl;
			}
		}
		return out;
	}
	friend ifstream& operator>>(ifstream& is, Bachelor& tmp)
	{
		string name, id, tel, province, city, region, major;
		int num;
		is >> name;
		is >> id;
		is >> tel;
		is >> province;
		is >> city;
		is >> region;
		is >> major;
		is >> num;
		string* course = new string[num];
		double* grade = new double[num];
		for (int i = 0; i < num; ++i)
		{
			is >> course[i] >> grade[i];
		}
		tmp.setName(name);
		tmp.setPhoneNumber(tel);
		tmp.setIdentifyNumber(id);
		tmp.setProvince(province);
		tmp.setCity(city);
		tmp.setRegion(region);
		tmp.setMajor(major);
		tmp.setCourse(course, num);
		tmp.setCourseGrade(grade, num);
		delete[]course;
		delete[]grade;
		return is;
	}
};
