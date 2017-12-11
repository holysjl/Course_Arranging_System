//对于各变量的定义
#pragma once
#include<vector>
#include"Classroom.h"
#include"Course.h"
#include"StudentClass.h"
#include"Teacher.h"
#include<string>

extern int countOfTeacher, countOfClass, countOfClassroom, countOfCourse;
extern vector<Course> course;
extern vector<StudentClass> studentclass;
extern vector<Teacher> teacher;
extern vector<Classroom> classroom;
extern int isfail , isfind, isback ;
extern Course* tmpcourse;
extern Course* ttmpcourse;
extern string  x, x1, x2;
extern Teacher* t1;
extern StudentClass* t2;
extern Classroom* t3;
