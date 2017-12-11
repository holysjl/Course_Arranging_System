//教师类
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Orignal.h"
using namespace std;
class Teacher:public Orignal{
public:
	Teacher();										
	string getNameOfTeacher();						
	void setNameOfTeacher(string &);
	string &sche(int i, int j);						//返回教师表相应时间段的信息
	friend istream &operator>>(istream &stream, Teacher &teacher);				//重载>>运算符以便读取数据
	bool isTeachCourse(int course_);
	bool isTeachClass(int class_);
	int getCountOfClass();
	vector<int> getClassNumber();               //得到所教班级vector
private:
	string nameOfTeacher;				//教师名称
	vector<int> teacherCourse;			//教授课程
	vector<int> numberOfClass;			//教哪些班级
	string scheOfTeacher[5][8];         //教师课表
};