//�γ���
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
	string nameOfCourse;//�γ���
	int numberOfCourse;//�γ̺�
	int tmpRoomno;//������ý�������
	vector<int> tmpRoom;//����Ŀ��ý���
	int credit;//ѧ��
	int time;//��ʱ
public:
	Course();
	Course(string,int,int,int);
	string getNameOfCourse();
	int getNumberOfCourse();
	int getTmpRoomno();
	int getTime();
	void setTime(int time_);
	int getCredit(); 
	int &operator[](const int &index); //�����±���������ڵõ�������Һ�
	int getSize();    //�õ�������ҵĿ�������
};