//��ʦ��
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
	string &sche(int i, int j);						//���ؽ�ʦ����Ӧʱ��ε���Ϣ
	friend istream &operator>>(istream &stream, Teacher &teacher);				//����>>������Ա��ȡ����
	bool isTeachCourse(int course_);
	bool isTeachClass(int class_);
	int getCountOfClass();
	vector<int> getClassNumber();               //�õ����̰༶vector
private:
	string nameOfTeacher;				//��ʦ����
	vector<int> teacherCourse;			//���ڿγ�
	vector<int> numberOfClass;			//����Щ�༶
	string scheOfTeacher[5][8];         //��ʦ�α�
};