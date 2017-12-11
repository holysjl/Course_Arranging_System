//核心算法中函数头的定义
#pragma once
#include<sstream>
#include <iostream>
#include <string>
#include <fstream>
#include "Orignal.h"
#include<vector>
#include"Classroom.h"
#include"Course.h"
#include"StudentClass.h"
#include"Teacher.h"
#include"variable.h"
using namespace std;

void sortClassroom();
void sortCourse(StudentClass studentc, vector<Course> course);
void schedule_class(int indexOfClass);
void schedule_course(int indexOfClass, int indexOfCourse);
bool is_teacher_class(Teacher& teacher_, StudentClass& class_, int i, int j);
bool is_classroom_class(Classroom&classroom_, StudentClass&class_, int i, int j);
bool isrepeat(int indexOfClass, Course& course_, int day);
bool isschedule(int, Course&);
int getindexofclass(int);
Course searchCourse(vector<Course> course, int courseNo);
Classroom& searchclassroom(Course &course_, int index);
Teacher* searchteacher(Course &course_, StudentClass&class_);
StudentClass searchclass(int);
