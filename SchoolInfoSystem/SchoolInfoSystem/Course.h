#pragma once
#include "function.h"
class Course
{
private:
	string* course;//动态分配课程
	int courseCount;//课程数目

public:
	Course();//无参构造函数
	Course(string* course,int count);
	Course(const Course& tmp);
	~Course();

	string* getCourse();
	int getCourseCount() const;

	bool setCourse(string* course, int count);
};

