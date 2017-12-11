//排课的核心算法
#include"schedule.h"

//将非特殊教室按照教室容纳量从小到大排序
void sortClassroom(){
	Classroom cs;
	for (int i = 0; i < countOfClassroom; i++)
		for (int j = i + 1; j < countOfClassroom; j++)
			if (classroom[i].getCapacityOfClassroom() > classroom[j].getCapacityOfClassroom()){
		cs = classroom[i];
		classroom[i] = classroom[j];
		classroom[j] = cs;
			}
}
//将班级的应修课程按照课程的学分从高到低排序 
void sortCourse(StudentClass studentc, vector<Course> course){
	int t;
	Course s;
	tmpcourse = new Course[studentc.getCourseNo() + 1];
	int* tmp = new int[studentc.getCourseNo()];
	for (int i = 0; i < studentc.getCourseNo(); i++){
		tmpcourse[i] = (searchCourse(course, studentc[i]));
		*(tmp + i) = tmpcourse[i].getCredit();
	}
	for (int i = 0; i < studentc.getCourseNo(); i++)
		for (int j = i + 1; j < studentc.getCourseNo(); j++)
			if (tmp[i] < tmp[j]){
		t = tmp[i];
		tmp[i] = tmp[j];
		tmp[j] = t;
		s = tmpcourse[i];
		tmpcourse[i] = tmpcourse[j];
		tmpcourse[j] = s;
			}
	ttmpcourse = tmpcourse;
	delete[]tmp;
	return;
}
//根据课程号搜索对应的课程对象
Course searchCourse(vector<Course> course, int courseNo){
	for (int i = 0; i < countOfCourse; i++){
		if (course[i].getNumberOfCourse() == courseNo)
			return course[i];
	}
}
//搜索课程可用教室数组中下标对应的教室对象
Classroom& searchclassroom(Course &course_, int index){
	for (int i = 0; i < countOfClassroom; i++)
		if (course_[index] == (classroom[i]).getNameOfClassroom())
			return classroom[i];
}
//根据课程和班级对象搜索对应的教课老师的对象
Teacher* searchteacher(Course &course_, StudentClass&class_){
	for (int i = 0; i < countOfTeacher; i++){
		if ((teacher[i].isTeachCourse(course_.getNumberOfCourse())) && (teacher[i].isTeachClass(class_.getNumberOfClass())))
			return &(teacher[i]);
	}
}
//搜索班级号对应的班级对象
StudentClass searchclass(int no){
	for (int i = 0; i < countOfClass; i++)
		if (studentclass[i].getNumberOfClass() == no) return studentclass[i];
}
//判断指定时间段（i，j）老师课程表与班级课程表是否能够匹配
bool is_teacher_class(Teacher& teacher_, StudentClass& class_, int i, int j){
	if ((teacher_.sche(i, j) == "\0") && (class_.sche(i, j) == "\0")) return true;
	else return false;
}
//判断指定时间段（i，j）教室课程表与班级课程表是否能够匹配
bool is_classroom_class(Classroom&classroom_, StudentClass&class_, int i, int j){
	if ((classroom_.sche(i, j) == "\0") && (class_.sche(i, j) == "\0")) return true;
	else return false;
}
//判断指定的某一天中班级的某一门课程是否已经排过
bool isrepeat(int indexOfClass, Course& course_, int day){
	for (int i = 0; i < 8; i++){
		if (studentclass[indexOfClass].sche(day, i).find(course_.getNameOfCourse()) == 0) return true;
	}
	return false;
}
//判断某一门课程在指定的班级课表中是否已经排满全部课时
bool isschedule(int indexOfClass_, Course& course_){
	int count = 0;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 8; j++){
		if (studentclass[indexOfClass_].sche(i, j).find(course_.getNameOfCourse()) == 0) count++;
		if (count == course_.getTime()) return true;
		}
	return false;
}
//输入课程号得到对应的班级下标
int getindexofclass(int no){
	for (int i = 0; i < countOfClass; i++)
		if (studentclass[i].getNumberOfClass() == no) return i;
}
//排指定班级的课表
void schedule_class(int indexOfClass){
	countOfTeacher = teacher.size();
	countOfClass = studentclass.size();
	countOfClassroom = classroom.size();
	countOfCourse = course.size();
	sortClassroom();
	isfail = 0; isfind = 0; isback = 0;
	tmpcourse = new Course[2];
	ttmpcourse = tmpcourse;
	if (indexOfClass == countOfClass){//排完了全部班级的课表后，强行退出函数
		delete[]ttmpcourse;
		throw (indexOfClass);
		return;
	}
	if (isfail) {
		isfail = 0;
		indexOfClass--;
		if (indexOfClass == 0) exit(0);
		delete[]ttmpcourse;
		countOfCourse = studentclass[indexOfClass].getCourseNo();
		sortCourse(studentclass[indexOfClass], course);
		isback = 1;
		tmpcourse = tmpcourse + countOfCourse;
	}//如果当前班级排课失败则返回上一个班级的最后一门课程进行重新排课
	else {
		delete[]ttmpcourse;
		sortCourse(studentclass[indexOfClass], course);
		countOfCourse = studentclass[indexOfClass].getCourseNo();
		schedule_course(indexOfClass, 0);
	}
	return;
}
//排指定班级中的课程列表中指定下标的课程
//排课过程中使用的三目运算符是用来考虑特殊教室的情况
void schedule_course(int indexOfClass, int indexOfCourse){
	stringstream ss;
	Teacher*teacher_ = searchteacher(*tmpcourse, studentclass[indexOfClass]);
	if (indexOfCourse == countOfCourse)  {
		indexOfClass++;
		schedule_class(indexOfClass);
		return;
	}
	//排完指定班级中的全部课程后，开始排下一个班级的课程
	if (isschedule(indexOfClass, searchCourse(course, tmpcourse->getNumberOfCourse()))) {
		indexOfCourse++;
		tmpcourse++;
		schedule_course(indexOfClass, indexOfCourse);
		indexOfCourse--;
		tmpcourse--;
		return;
	}//当前课程在当前班级中排满课时之后，开始排当前班级下一个待排课程；失败后则回溯到上一个课程
	if (teacher_->getCountOfClass() > 1){//考虑多个班一起上课情况
		for (int i = 1; i <= ceil(teacher_->getCountOfClass() / 2.0); i++){
			int number = ceil(1.0*teacher_->getCountOfClass() / i);//每组班级的数量
			vector<StudentClass>*sclass = new vector<StudentClass>[i];//创建不同个数的班级数组
			for (int j = 0; j < i - 1; j++)//按照不同的班级分组情况将这些班级放到不同的班级数组中
				for (int k = 0; k < number; k++)
					sclass[j].push_back(searchclass(teacher_->getClassNumber()[number*j + k]));
			for (int j = (i - 1)*number; j < teacher_->getCountOfClass(); j++)//最后一个班级数组单独考虑
				sclass[i - 1].push_back(searchclass(teacher_->getClassNumber()[j]));
			for (int j = 0; j < i; j++){
				if (isschedule(getindexofclass(sclass[j][0].getNumberOfClass()), searchCourse(course, tmpcourse->getNumberOfCourse()))) continue;
				for (int ki = 0; ki < 5; ki++){
					int n = (ki + j + tmpcourse->getNumberOfCourse()) % 5;//日期，班级号，课程号均为单增数字，据此将课程在课表中散分
					if (isrepeat(getindexofclass(sclass[j][0].getNumberOfClass()), *tmpcourse, n)) continue;
					if (tmpcourse->getTime() >= 4){//课时数大于3
						for (int isafternoon = 0; isafternoon < 2; isafternoon++)//isafternoon取0和1两个值，代表上午和下午的课程时段
							for (int lesson = 0; lesson < 3; lesson++)//先排连堂的两节课
								for (int k = 0; k < (tmpcourse->getSize() > 0 ? tmpcourse->getSize() : countOfClassroom); k++){//根据课程有无特殊教室来确定搜索的教室的个数
							int issuccess = 1, kj = lesson + isafternoon * 4, capacity = 0;
							for (int lc = 0; lc < sclass[j].size(); lc++) capacity += sclass[j][lc].getCountOfStudent();//判断是否存在可利用的并且能够容纳下一个班级数组内全部学生的教室
							if (capacity>(tmpcourse->getSize()>0 ? searchclassroom(*tmpcourse, k) : classroom[k]).getCapacityOfClassroom()) issuccess = 0;
							else for (int lc = 0; lc < sclass[j].size(); lc++)//判断整个班级数组是否都可以匹配这两节课
								for (int lt = 0; lt < 2; lt++)
									if ((tmpcourse->getSize()>0 ? 0 : classroom[k].isspecial()) || !((is_teacher_class(*teacher_, studentclass[getindexofclass(sclass[j][lc].getNumberOfClass())], n, kj + lt)) && is_classroom_class((tmpcourse->getSize()>0 ? searchclassroom(*tmpcourse, k) : classroom[k]), studentclass[getindexofclass(sclass[j][lc].getNumberOfClass())], n, kj + lt)))
										issuccess = 0;
							if (issuccess) {
								ss << (tmpcourse->getSize()>0 ? searchclassroom(*tmpcourse, k) : classroom[k]).getNameOfClassroom();
								string classroomname_ = ss.str();
								for (int lc = 0; lc < sclass[j].size(); lc++)
									for (int l = 0; l < 2; l++)
										studentclass[getindexofclass(sclass[j][lc].getNumberOfClass())].sche(n, kj + l) = tmpcourse->getNameOfCourse() + "\n" + teacher_->getNameOfTeacher() + "\n" + classroomname_;
								for (int l = 0; l < 2; l++){
									(tmpcourse->getSize()>0 ? searchclassroom(*tmpcourse, k) : classroom[k]).sche(n, kj + l) = tmpcourse->getNameOfCourse() + "\n";
									for (int lc = 0; lc < sclass[j].size(); lc++){
										if ((lc != 0) && (lc % 2 == 0)) {//多个班级同时上课时，教室课表和老师课表内一行只打印两个班级
											teacher_->sche(n, kj + l) += "\n";
											(tmpcourse->getSize()>0 ? searchclassroom(*tmpcourse, k) : classroom[k]).sche(n, kj + l) += "\n";
										}
										teacher_->sche(n, kj + l) += studentclass[getindexofclass(sclass[j][lc].getNumberOfClass())].getNameOfClass() + " ";
										(tmpcourse->getSize()>0 ? searchclassroom(*tmpcourse, k) : classroom[k]).sche(n, kj + l) += studentclass[getindexofclass(sclass[j][lc].getNumberOfClass())].getNameOfClass() + " ";
									}
									teacher_->sche(n, kj + l) += "\n" + tmpcourse->getNameOfCourse() + "\n" + classroomname_;
									(tmpcourse->getSize()>0 ? searchclassroom(*tmpcourse, k) : classroom[k]).sche(n, kj + l) += "\n" + teacher_->getNameOfTeacher();
								}
								int t = tmpcourse->getTime();
								tmpcourse->setTime(t - 2);//将当前课程课时设置为剩余课时量
								isfind = 1;
								schedule_course(indexOfClass, indexOfCourse);
								tmpcourse->setTime(t + 2);//若排课失败则回溯到上一步
								isfind = 0;
								for (int lc = 0; lc < sclass[j].size(); lc++){
									for (int l = 0; l < 2; l++){
										studentclass[getindexofclass(sclass[j][lc].getNumberOfClass())].sche(n, kj + l) = "\0";
										teacher_->sche(n, kj + l) = "\0";
										(tmpcourse->getSize()>0 ? searchclassroom(*tmpcourse, k) : classroom[k]).sche(n, kj + l) = "\0";
									}
								}
							}
								}
					}
					else//课程数小于4的情况
						for (int isafternoon = 0; isafternoon < 2; isafternoon++)
							for (int lesson = 0; lesson < 5 - tmpcourse->getTime(); lesson++)
								for (int k = 0; k < (tmpcourse->getSize() > 0 ? tmpcourse->getSize() : countOfClassroom); k++){
						int issuccess = 1, kj = lesson + isafternoon * 4, capacity = 0;
						for (int lc = 0; lc < sclass[j].size(); lc++) capacity += sclass[j][lc].getCountOfStudent();
						if (capacity>(tmpcourse->getSize()>0 ? searchclassroom(*tmpcourse, k) : classroom[k]).getCapacityOfClassroom()) issuccess = 0;
						else
							for (int lc = 0; lc < sclass[j].size(); lc++)
								for (int lt = 0; lt < tmpcourse->getTime(); lt++)
									if ((tmpcourse->getSize()>0 ? 0 : classroom[k].isspecial()) || !((is_teacher_class(*teacher_, studentclass[getindexofclass(sclass[j][lc].getNumberOfClass())], n, kj + lt)) && is_classroom_class((tmpcourse->getSize()>0 ? searchclassroom(*tmpcourse, k) : classroom[k]), studentclass[getindexofclass(sclass[j][lc].getNumberOfClass())], n, kj + lt)))
										issuccess = 0;
						if (issuccess) {
							ss << (tmpcourse->getSize()>0 ? searchclassroom(*tmpcourse, k) : classroom[k]).getNameOfClassroom();
							string classroomname_ = ss.str();
							for (int lc = 0; lc < sclass[j].size(); lc++)
								for (int l = 0; l < tmpcourse->getTime(); l++)
									studentclass[getindexofclass(sclass[j][lc].getNumberOfClass())].sche(n, kj + l) = tmpcourse->getNameOfCourse() + "\n" + teacher_->getNameOfTeacher() + "\n" + classroomname_;
							for (int l = 0; l < tmpcourse->getTime(); l++){
								(tmpcourse->getSize()>0 ? searchclassroom(*tmpcourse, k) : classroom[k]).sche(n, kj + l) = tmpcourse->getNameOfCourse() + "\n";
								for (int lc = 0; lc < sclass[j].size(); lc++){
									if ((lc != 0) && (lc % 2 == 0)) {
										teacher_->sche(n, kj + l) += "\n";
										(tmpcourse->getSize()>0 ? searchclassroom(*tmpcourse, k) : classroom[k]).sche(n, kj + l) += "\n";
									}
									teacher_->sche(n, kj + l) += studentclass[getindexofclass(sclass[j][lc].getNumberOfClass())].getNameOfClass() + " ";
									(tmpcourse->getSize()>0 ? searchclassroom(*tmpcourse, k) : classroom[k]).sche(n, kj + l) += studentclass[getindexofclass(sclass[j][lc].getNumberOfClass())].getNameOfClass() + " ";
								}
								teacher_->sche(n, kj + l) += "\n" + tmpcourse->getNameOfCourse() + "\n" + classroomname_;
								(tmpcourse->getSize()>0 ? searchclassroom(*tmpcourse, k) : classroom[k]).sche(n, kj + l) += "\n" + teacher_->getNameOfTeacher();
							}
							indexOfCourse++;
							tmpcourse++;
							isfind = 1;
							schedule_course(indexOfClass, indexOfCourse);
							indexOfCourse--;
							tmpcourse--;
							isfind = 0;
							for (int lc = 0; lc < sclass[j].size(); lc++)
								for (int l = 0; l < tmpcourse->getTime(); l++){
								studentclass[getindexofclass(sclass[j][lc].getNumberOfClass())].sche(n, kj + l) = "\0";
								teacher_->sche(n, kj + l) = "\0";
								(tmpcourse->getSize()>0 ? searchclassroom(*tmpcourse, k) : classroom[k]).sche(n, kj + l) = "\0";
								}
						}
								}
				}
			}
			delete[]sclass;
		}
	}
	//单个班上课
	for (int i = 0; i < 5; i++){
		int n = (i + indexOfClass + tmpcourse->getNumberOfCourse()) % 5;//班级号和课程号输入要求 单增的数字
		if (isrepeat(indexOfClass, *tmpcourse, n)) continue;
		if (tmpcourse->getTime() >= 4) {//课时数大于3
			for (int isafternoon = 0; isafternoon < 2; isafternoon++)
				for (int lesson = 0; lesson < 3; lesson++)
					for (int k = 0; k < (tmpcourse->getSize() > 0 ? tmpcourse->getSize() : countOfClassroom); k++){
				int issuccess = 1, j = lesson + isafternoon * 4;
				for (int m = 0; m < 2; m++)
					if ((tmpcourse->getSize()>0 ? 0 : classroom[k].isspecial()) || !((tmpcourse->getSize() > 0 ? searchclassroom(*tmpcourse, k).getCapacityOfClassroom() : classroom[k].getCapacityOfClassroom() >= studentclass[indexOfClass].getCountOfStudent()) && (is_teacher_class(*teacher_, studentclass[indexOfClass], n, j + m)) && (is_classroom_class(tmpcourse->getSize() > 0 ? searchclassroom(*tmpcourse, k) : classroom[k], studentclass[indexOfClass], n, j + m))))
						issuccess = 0;
				if (issuccess){
					ss << (tmpcourse->getSize() > 0 ? searchclassroom(*tmpcourse, k) : classroom[k]).getNameOfClassroom();
					string classroomname_ = ss.str();
					for (int l = 0; l < 2; l++){
						studentclass[indexOfClass].sche(n, j + l) = tmpcourse->getNameOfCourse() + "\n" + teacher_->getNameOfTeacher() + "\n" + classroomname_;
						teacher_->sche(n, j + l) = studentclass[indexOfClass].getNameOfClass() + "\n" + tmpcourse->getNameOfCourse() + "\n" + classroomname_;
						(tmpcourse->getSize()>0 ? searchclassroom(*tmpcourse, k) : classroom[k]).sche(n, j + l) = tmpcourse->getNameOfCourse() + "\n" + studentclass[indexOfClass].getNameOfClass() + "\n" + teacher_->getNameOfTeacher();
					}
					int t = tmpcourse->getTime();
					tmpcourse->setTime(t - 2);
					isfind = 1;
					schedule_course(indexOfClass, indexOfCourse);
					tmpcourse->setTime(t + 2);
					isfind = 0;
					for (int m = 0; m < 2; m++){
						studentclass[indexOfClass].sche(n, j + m) = "\0";
						teacher_->sche(n, j + m) = "\0";
						(tmpcourse->getSize()>0 ? searchclassroom(*tmpcourse, k) : classroom[k]).sche(n, j + m) = "\0";
					}
				}
					}
		}
		else {//课程数小于4
			for (int isafternoon = 0; isafternoon < 2; isafternoon++)
				for (int lesson = 0; lesson < 5 - tmpcourse->getTime(); lesson++)
					for (int k = 0; k < (tmpcourse->getSize() > 0 ? tmpcourse->getSize() : countOfClassroom); k++){
				int issuccess = 1, j = lesson + isafternoon * 4;
				for (int m = 0; m < tmpcourse->getTime(); m++)
					if ((tmpcourse->getSize()>0 ? 0 : classroom[k].isspecial()) || !((tmpcourse->getSize() > 0 ? searchclassroom(*tmpcourse, k).getCapacityOfClassroom() : classroom[k].getCapacityOfClassroom() >= studentclass[indexOfClass].getCountOfStudent()) && (is_teacher_class(*teacher_, studentclass[indexOfClass], n, j + m)) && (is_classroom_class(tmpcourse->getSize() > 0 ? searchclassroom(*tmpcourse, k) : classroom[k], studentclass[indexOfClass], n, j + m))))
						issuccess = 0;
				if (issuccess){
					ss << (tmpcourse->getSize() > 0 ? searchclassroom(*tmpcourse, k) : classroom[k]).getNameOfClassroom();
					string classroomname_ = ss.str();
					for (int l = 0; l < tmpcourse->getTime(); l++){
						studentclass[indexOfClass].sche(n, j + l) = tmpcourse->getNameOfCourse() + "\n" + teacher_->getNameOfTeacher() + "\n" + classroomname_;
						teacher_->sche(n, j + l) = studentclass[indexOfClass].getNameOfClass() + "\n" + tmpcourse->getNameOfCourse() + "\n" + classroomname_;
						(tmpcourse->getSize()>0 ? searchclassroom(*tmpcourse, k) : classroom[k]).sche(n, j + l) = tmpcourse->getNameOfCourse() + "\n" + studentclass[indexOfClass].getNameOfClass() + "\n" + teacher_->getNameOfTeacher();
					}
					indexOfCourse++;
					tmpcourse++;
					isfind = 1;
					schedule_course(indexOfClass, indexOfCourse);
					indexOfCourse--;
					tmpcourse--;
					isfind = 0;
					for (int l = 0; l < tmpcourse->getTime(); l++){
						studentclass[indexOfClass].sche(n, j + l) = "\0";
						teacher_->sche(n, j + l) = "\0";
						(tmpcourse->getSize()>0 ? searchclassroom(*tmpcourse, k) : classroom[k]).sche(n, j + l) = "\0";
					}
				}
					}
		}
	}
	if ((isfind == 0) && (indexOfCourse == 0))  isfail = 1;
	return;
}