//�༶��
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
	int getCourseNo();								//����Ӧ�Ͽγ̵�����
	int operator[](const int& index);//����Ӧ�Ͽγ�����һ���ı��
	void setNumberOfClass(int);
private:
	string nameOfClass;//�༶����
	int numberOfClass;//�༶��
	int countOfStudent;//ѧ������
	int courseNo;//�γ�����
	vector<int>compulCourse;//Ӧ�Ͽγ�
	string scheOfStudent[5][8];//ѧ���α�
};
