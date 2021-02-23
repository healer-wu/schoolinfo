#include "Course.h"

Course::Course()
{
	this->course = new string[1];
	(this->course)[0] = "¼ÆËã»ú";
	this->courseCount = 1;
}

Course::Course(string* course, int count)
{
	this->courseCount = count;
	this->course = new string[this->courseCount];
	for (int i = 0; i < this->courseCount; ++i)
	{
		(this->course)[i] = course[i];
	}
}

Course::Course(const Course& tmp)
{
	this->courseCount = tmp.courseCount;
	this->course = new string[this->courseCount];
	for (int i = 0; i < this->courseCount; ++i)
	{
		this->course[i] = tmp.course[i];
	}
}


Course::~Course()
{
	delete[]this->course;
	this->course = NULL;
}

string* Course::getCourse()
{
	return this->course;
}

int Course::getCourseCount() const
{
	return this->courseCount;
}

bool Course::setCourse( string* course, int count)
{
	delete[]this->course;
	this->courseCount = count;
	this->course = new string[this->courseCount];
	for (int i = 0; i < this->courseCount; ++i)
	{
		(this->course)[i] = course[i];
	}
	return true;
}

