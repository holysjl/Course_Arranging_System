//������
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
	string &sche(int i, int j);						//���ؽ��ұ���Ӧʱ��ε���Ϣ
	friend istream &operator>>(istream &stream, Classroom &classroom);			//����>>������Ա��ȡ����
	bool isspecial();                                 //�ж��Ƿ�Ϊ�������
private:
	int nameOfClassroom;				//��������
	int capacityOfClassroom;			//��������
	string scheOfClassroom[5][8];		//���ұ�
	bool kind;                          //�Ƿ�Ϊ������ҵı�ʶ
};