//班级类
#pragma once
#include<string>
#include"Course.h"
#include "Orignal.h"
using namespace std;
class StudentClass:public Orignal{
public:
	friend istream &operator>>(istream& out, StudentClass& studentclass){
		out >> studentclass.nameOfClass;
		out >> studentclass.numberOfClass;
		out >> studentclass.countOfStudent;
		out >> studentclass.courseNo; 
		int x;
		for (int i = 0; i < studentclass.courseNo; i++){
			out >> x;
			studentclass.compulCourse.push_back(x);
		}
		return out;
	}
	string& sche(int, int);
	StudentClass();
	int getCountOfStudent();
	string  getNameOfClass();
	int getNumberOfClass();
	int getCourseNo();								//返回应上课程的数量
	int operator[](const int& index);//返回应上课程其中一个的编号
	void setNumberOfClass(int);
private:
	string nameOfClass;//班级名称
	int numberOfClass;//班级号
	int countOfStudent;//学生数量
	int courseNo;//课程数量
	vector<int>compulCourse;//应上课程
	string scheOfStudent[5][8];//学生课表
};
