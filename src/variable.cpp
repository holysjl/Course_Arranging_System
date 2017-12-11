//变量定义
#include"variable.h"

int countOfTeacher = 0, countOfClass = 0, countOfClassroom = 0, countOfCourse = 0;
vector<Course> course;
vector<StudentClass> studentclass;
vector<Teacher> teacher;
vector<Classroom> classroom;
int isfail = 0, isfind = 0, isback = 0;
Course* tmpcourse = new Course[2];
Course* ttmpcourse=tmpcourse;
string  x = "",x1 ="", x2 = " ";
Teacher* t1=new Teacher();
StudentClass* t2=new StudentClass();
Classroom* t3=new Classroom();