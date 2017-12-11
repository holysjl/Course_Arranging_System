//课程类
#pragma once
#include<string>
#include"Classroom.h"
#include<fstream>
#include<vector>

using namespace std;
class Course{
	friend istream &operator>>(istream& out, Course& course){
		out >> course.nameOfCourse;
		out >> course.numberOfCourse;
		out >> course.time;
		out >> course.credit;
		out >> course.tmpRoomno; int x;
		for (int i = 0; i < course.tmpRoomno; i++){
			
			out >> x; course.tmpRoom.push_back(x);
		}


		return out;
	}
private:
	string nameOfCourse;//课程名
	int numberOfCourse;//课程号
	int tmpRoomno;//特殊可用教室数量
	vector<int> tmpRoom;//特殊的可用教室
	int credit;//学分
	int time;//课时
public:
	Course();
	Course(string,int,int,int);
	string getNameOfCourse();
	int getNumberOfCourse();
	int getTmpRoomno();
	int getTime();
	void setTime(int time_);
	int getCredit(); 
	int &operator[](const int &index); //重载下标运算符便于得到特殊教室号
	int getSize();    //得到特殊教室的可用数量
};