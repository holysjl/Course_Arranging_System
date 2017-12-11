#include "Classroom.h"

Classroom::Classroom(){
	nameOfClassroom = 0000;
	capacityOfClassroom = 0;
	for (int i = 0; i < 5; i++){					//将教师表信息初始化为"\0"
		for (int j = 0; j < 8; j++){
			scheOfClassroom[i][j] = "\0";
		}
	}
}

int Classroom::getNameOfClassroom(){
	return nameOfClassroom;
}

void Classroom::setNameOfClassroom(int &newName){
	nameOfClassroom = newName;
}

int Classroom::getCapacityOfClassroom(){
	return capacityOfClassroom;
}

void Classroom::setCapacityOfClassroom(int &newCapacity){
	capacityOfClassroom = newCapacity;
}

string & Classroom::sche(int i, int j){
	return scheOfClassroom[i][j];
}

istream &operator>>(istream &stream, Classroom &classroom){
	stream >> classroom.nameOfClassroom;
	stream >> classroom.capacityOfClassroom;
	stream >> classroom.kind;
	return stream;
}
bool Classroom::isspecial(){
	if (kind == 0) return false;
	else return true;
}