#pragma once
#include "function.h"
class Course
{
private:
	string* course;//��̬����γ�
	int courseCount;//�γ���Ŀ

public:
	Course();//�޲ι��캯��
	Course(string* course,int count);
	Course(const Course& tmp);
	~Course();

	string* getCourse();
	int getCourseCount() const;

	bool setCourse(string* course, int count);
};

