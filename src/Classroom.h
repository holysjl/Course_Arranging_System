//教室类
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Orignal.h"
using namespace std;
class Classroom:public Orignal{
public:
	Classroom();							
	int getNameOfClassroom();						
	void setNameOfClassroom(int &);
	int getCapacityOfClassroom();
	void setCapacityOfClassroom(int &);
	string &sche(int i, int j);						//返回教室表相应时间段的信息
	friend istream &operator>>(istream &stream, Classroom &classroom);			//重载>>运算符以便读取数据
	bool isspecial();                                 //判断是否为特殊教室
private:
	int nameOfClassroom;				//教室名称
	int capacityOfClassroom;			//教室容量
	string scheOfClassroom[5][8];		//教室表
	bool kind;                          //是否为特殊教室的标识
};