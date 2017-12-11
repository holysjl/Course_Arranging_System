#include"Course.h"
Course::Course(string nameOfCourse, int numberOfCourse, int credit,int time){
	this->nameOfCourse = nameOfCourse; this->numberOfCourse = numberOfCourse; this->credit = credit; this->time = time;
}
string Course::getNameOfCourse(){
	return nameOfCourse;
}
Course::Course(){
	nameOfCourse = "\n"; numberOfCourse = 0; credit = 0;
}
 int &Course::operator[](const int &index){
	return tmpRoom[index];
}
int Course::getSize(){
	return tmpRoom.size();
}
int Course::getNumberOfCourse(){ return numberOfCourse; }
int Course::getTmpRoomno(){ return tmpRoomno; }
int Course::getCredit(){ return credit; }
int Course::getTime(){ return time; }
void Course::setTime(int time_){ time = time_; }
