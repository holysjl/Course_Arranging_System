//教师类
#include "Teacher.h"

Teacher::Teacher(){
	nameOfTeacher = "None";
	for (int i = 0; i < 5; i++){					//将教师表信息初始化为"\0"
		for (int j = 0; j < 8; j++){
			scheOfTeacher[i][j] = "\0";
		}
	}
}

string Teacher::getNameOfTeacher(){
	return nameOfTeacher;
}

void Teacher::setNameOfTeacher(string &newName){
	nameOfTeacher = newName;
}

string &Teacher::sche(int i, int j){
	return scheOfTeacher[i][j];
}

istream &operator>>(istream &stream, Teacher &teacher){
	stream >> teacher.nameOfTeacher;
	int size = 0;
	int tmp = 0;
	stream >> size;									//读取教授课程的个数以便读取课程号，下同
	for (int i = 0; i < size; i++){
		stream >> tmp;
		teacher.teacherCourse.push_back(tmp);
	}
	stream >> size;
	for (int i = 0; i < size; i++){
		stream >> tmp;
		teacher.numberOfClass.push_back(tmp);
	}
	int m = 0, n = 0;
	stream >> size;
	for (int i = 0; i < size; i++){
		stream >> m;
		stream >> n;
		teacher.sche(m - 1, 2 * n - 2) = "Busy.\0";
		teacher.sche(m - 1, 2 * n - 1) = "Busy.\0";
	}
	return stream;
}

bool Teacher::isTeachCourse(int course_){
	for (int i = 0; i < teacherCourse.size(); i++)
		if (teacherCourse.at(i) == course_)
			return true;
	return false;
}

bool Teacher::isTeachClass(int class_){
	for (int i = 0; i < numberOfClass.size(); i++)
		if (numberOfClass.at(i) == class_)
			return true;
	return false;
}

int Teacher::getCountOfClass(){
	return numberOfClass.size();
}
vector<int> Teacher::getClassNumber(){
	return numberOfClass;
}