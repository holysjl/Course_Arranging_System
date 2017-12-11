//班级类
#include"StudentClass.h"

string& StudentClass::sche(int i, int j){
	return scheOfStudent[i][j];
}
StudentClass::StudentClass(){
	nameOfClass = "\0";
	numberOfClass = 000;
	countOfStudent = 0;
	courseNo = 0;
	for(int i = 0; i < 5; i++){					//将教师表信息初始化为"\0"
		for (int j = 0; j < 8; j++){
			scheOfStudent[i][j] = "\0";
		}
	}
}
string  StudentClass::getNameOfClass(){ 
	return nameOfClass; 
}
int StudentClass::getNumberOfClass(){
	return numberOfClass;
}
int StudentClass::getCountOfStudent(){
	return countOfStudent; 
}
int StudentClass::getCourseNo(){
	return courseNo;
}
int StudentClass::operator[](const int &index){ 
	return compulCourse.at(index); 
}
void StudentClass::setNumberOfClass(int numberOfClass){
	this->numberOfClass = numberOfClass;
}