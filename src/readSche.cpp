//读取保存在文件中的课程表
#include"readSche.h"
#include"variable.h"
#include"readin.h"

void readSche(){
	fstream kitty;  string ss; int i = 0, index; char s[100];
	kitty.open("老师的课程表.txt", ios::in);
	while (!kitty.eof())	{
		kitty >> ss;	
		 teacher.push_back(Teacher());
		readin(&teacher[i], kitty); teacher[i].setNameOfTeacher(ss);
		i++;
	}kitty.close();
	kitty.open("班级的课程表.txt", ios::in);
	i = 0;
	while (!kitty.eof()){
		kitty.getline(s, 100, '\\');
		ss = s; ss.substr(0, 4); index = atof(ss.c_str()); studentclass.push_back(StudentClass());
		studentclass[i].setNumberOfClass(index);
		readin(&studentclass[i], kitty);
		i++;
	}kitty.close();
	kitty.open("教室的课程表.txt", ios::in); i = 0;
	while (!kitty.eof()){
		kitty.getline(s, 100, '\\'); ss = s; ss.substr(0, 10); index = atof(ss.c_str());
		classroom.push_back(Classroom());
		classroom[i].setNameOfClassroom(index);
		readin(&classroom[i], kitty);
		i++;
	}kitty.close();
}
