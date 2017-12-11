//读取原始数据文件
#include "readFile.h"

void readFile(vector<Classroom> &classroom, vector<Course> &course, vector<StudentClass> &studentclass, vector<Teacher> &teacher){
	fstream readin;
	char s[100];

	classroom.clear(); course.clear(); studentclass.clear(); teacher.clear();

	readin.open("classroom.txt", ios::in);
	readin.getline(s, 100, '\n');
	while (!readin.eof()){
		Classroom classroom1;
		readin >> classroom1;
		classroom.push_back(classroom1);
	}
	readin.close();

	readin.open("course.txt", ios::in);
	readin.getline(s, 100, '\n');
	while (!readin.eof()){
		Course course1;
		readin >> course1;
		course.push_back(course1);
	}
	readin.close();

	readin.open("studentclass.txt", ios::in);
	readin.getline(s, 100, '\n');
	while (!readin.eof()){
		StudentClass studentclass1;
		readin >> studentclass1;
		studentclass.push_back(studentclass1);
	}
	readin.close();

	readin.open("teacher.txt", ios::in);
	readin.getline(s, 100, '\n');
	while (!readin.eof()){
		Teacher teacher1;
		readin >> teacher1;
		teacher.push_back(teacher1);
	}
	readin.close();

	return;
}