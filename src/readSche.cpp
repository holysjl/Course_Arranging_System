//��ȡ�������ļ��еĿγ̱�
#include"readSche.h"
#include"variable.h"
#include"readin.h"

void readSche(){
	fstream kitty;  string ss; int i = 0, index; char s[100];
	kitty.open("��ʦ�Ŀγ̱�.txt", ios::in);
	while (!kitty.eof())	{
		kitty >> ss;	
		 teacher.push_back(Teacher());
		readin(&teacher[i], kitty); teacher[i].setNameOfTeacher(ss);
		i++;
	}kitty.close();
	kitty.open("�༶�Ŀγ̱�.txt", ios::in);
	i = 0;
	while (!kitty.eof()){
		kitty.getline(s, 100, '\\');
		ss = s; ss.substr(0, 4); index = atof(ss.c_str()); studentclass.push_back(StudentClass());
		studentclass[i].setNumberOfClass(index);
		readin(&studentclass[i], kitty);
		i++;
	}kitty.close();
	kitty.open("���ҵĿγ̱�.txt", ios::in); i = 0;
	while (!kitty.eof()){
		kitty.getline(s, 100, '\\'); ss = s; ss.substr(0, 10); index = atof(ss.c_str());
		classroom.push_back(Classroom());
		classroom[i].setNameOfClassroom(index);
		readin(&classroom[i], kitty);
		i++;
	}kitty.close();
}
