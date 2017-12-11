//�ſεĺ����㷨
#include"schedule.h"

//����������Ұ��ս�����������С��������
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
//���༶��Ӧ�޿γ̰��տγ̵�ѧ�ִӸߵ������� 
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
//���ݿγ̺�������Ӧ�Ŀγ̶���
Course searchCourse(vector<Course> course, int courseNo){
	for (int i = 0; i < countOfCourse; i++){
		if (course[i].getNumberOfCourse() == courseNo)
			return course[i];
	}
}
//�����γ̿��ý����������±��Ӧ�Ľ��Ҷ���
Classroom& searchclassroom(Course &course_, int index){
	for (int i = 0; i < countOfClassroom; i++)
		if (course_[index] == (classroom[i]).getNameOfClassroom())
			return classroom[i];
}
//���ݿγ̺Ͱ༶����������Ӧ�Ľ̿���ʦ�Ķ���
Teacher* searchteacher(Course &course_, StudentClass&class_){
	for (int i = 0; i < countOfTeacher; i++){
		if ((teacher[i].isTeachCourse(course_.getNumberOfCourse())) && (teacher[i].isTeachClass(class_.getNumberOfClass())))
			return &(teacher[i]);
	}
}
//�����༶�Ŷ�Ӧ�İ༶����
StudentClass searchclass(int no){
	for (int i = 0; i < countOfClass; i++)
		if (studentclass[i].getNumberOfClass() == no) return studentclass[i];
}
//�ж�ָ��ʱ��Σ�i��j����ʦ�γ̱���༶�γ̱��Ƿ��ܹ�ƥ��
bool is_teacher_class(Teacher& teacher_, StudentClass& class_, int i, int j){
	if ((teacher_.sche(i, j) == "\0") && (class_.sche(i, j) == "\0")) return true;
	else return false;
}
//�ж�ָ��ʱ��Σ�i��j�����ҿγ̱���༶�γ̱��Ƿ��ܹ�ƥ��
bool is_classroom_class(Classroom&classroom_, StudentClass&class_, int i, int j){
	if ((classroom_.sche(i, j) == "\0") && (class_.sche(i, j) == "\0")) return true;
	else return false;
}
//�ж�ָ����ĳһ���а༶��ĳһ�ſγ��Ƿ��Ѿ��Ź�
bool isrepeat(int indexOfClass, Course& course_, int day){
	for (int i = 0; i < 8; i++){
		if (studentclass[indexOfClass].sche(day, i).find(course_.getNameOfCourse()) == 0) return true;
	}
	return false;
}
//�ж�ĳһ�ſγ���ָ���İ༶�α����Ƿ��Ѿ�����ȫ����ʱ
bool isschedule(int indexOfClass_, Course& course_){
	int count = 0;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 8; j++){
		if (studentclass[indexOfClass_].sche(i, j).find(course_.getNameOfCourse()) == 0) count++;
		if (count == course_.getTime()) return true;
		}
	return false;
}
//����γ̺ŵõ���Ӧ�İ༶�±�
int getindexofclass(int no){
	for (int i = 0; i < countOfClass; i++)
		if (studentclass[i].getNumberOfClass() == no) return i;
}
//��ָ���༶�Ŀα�
void schedule_class(int indexOfClass){
	countOfTeacher = teacher.size();
	countOfClass = studentclass.size();
	countOfClassroom = classroom.size();
	countOfCourse = course.size();
	sortClassroom();
	isfail = 0; isfind = 0; isback = 0;
	tmpcourse = new Course[2];
	ttmpcourse = tmpcourse;
	if (indexOfClass == countOfClass){//������ȫ���༶�Ŀα��ǿ���˳�����
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
	}//�����ǰ�༶�ſ�ʧ���򷵻���һ���༶�����һ�ſγ̽��������ſ�
	else {
		delete[]ttmpcourse;
		sortCourse(studentclass[indexOfClass], course);
		countOfCourse = studentclass[indexOfClass].getCourseNo();
		schedule_course(indexOfClass, 0);
	}
	return;
}
//��ָ���༶�еĿγ��б���ָ���±�Ŀγ�
//�ſι�����ʹ�õ���Ŀ���������������������ҵ����
void schedule_course(int indexOfClass, int indexOfCourse){
	stringstream ss;
	Teacher*teacher_ = searchteacher(*tmpcourse, studentclass[indexOfClass]);
	if (indexOfCourse == countOfCourse)  {
		indexOfClass++;
		schedule_class(indexOfClass);
		return;
	}
	//����ָ���༶�е�ȫ���γ̺󣬿�ʼ����һ���༶�Ŀγ�
	if (isschedule(indexOfClass, searchCourse(course, tmpcourse->getNumberOfCourse()))) {
		indexOfCourse++;
		tmpcourse++;
		schedule_course(indexOfClass, indexOfCourse);
		indexOfCourse--;
		tmpcourse--;
		return;
	}//��ǰ�γ��ڵ�ǰ�༶��������ʱ֮�󣬿�ʼ�ŵ�ǰ�༶��һ�����ſγ̣�ʧ�ܺ�����ݵ���һ���γ�
	if (teacher_->getCountOfClass() > 1){//���Ƕ����һ���Ͽ����
		for (int i = 1; i <= ceil(teacher_->getCountOfClass() / 2.0); i++){
			int number = ceil(1.0*teacher_->getCountOfClass() / i);//ÿ��༶������
			vector<StudentClass>*sclass = new vector<StudentClass>[i];//������ͬ�����İ༶����
			for (int j = 0; j < i - 1; j++)//���ղ�ͬ�İ༶�����������Щ�༶�ŵ���ͬ�İ༶������
				for (int k = 0; k < number; k++)
					sclass[j].push_back(searchclass(teacher_->getClassNumber()[number*j + k]));
			for (int j = (i - 1)*number; j < teacher_->getCountOfClass(); j++)//���һ���༶���鵥������
				sclass[i - 1].push_back(searchclass(teacher_->getClassNumber()[j]));
			for (int j = 0; j < i; j++){
				if (isschedule(getindexofclass(sclass[j][0].getNumberOfClass()), searchCourse(course, tmpcourse->getNumberOfCourse()))) continue;
				for (int ki = 0; ki < 5; ki++){
					int n = (ki + j + tmpcourse->getNumberOfCourse()) % 5;//���ڣ��༶�ţ��γ̺ž�Ϊ�������֣��ݴ˽��γ��ڿα���ɢ��
					if (isrepeat(getindexofclass(sclass[j][0].getNumberOfClass()), *tmpcourse, n)) continue;
					if (tmpcourse->getTime() >= 4){//��ʱ������3
						for (int isafternoon = 0; isafternoon < 2; isafternoon++)//isafternoonȡ0��1����ֵ���������������Ŀγ�ʱ��
							for (int lesson = 0; lesson < 3; lesson++)//�������õ����ڿ�
								for (int k = 0; k < (tmpcourse->getSize() > 0 ? tmpcourse->getSize() : countOfClassroom); k++){//���ݿγ��������������ȷ�������Ľ��ҵĸ���
							int issuccess = 1, kj = lesson + isafternoon * 4, capacity = 0;
							for (int lc = 0; lc < sclass[j].size(); lc++) capacity += sclass[j][lc].getCountOfStudent();//�ж��Ƿ���ڿ����õĲ����ܹ�������һ���༶������ȫ��ѧ���Ľ���
							if (capacity>(tmpcourse->getSize()>0 ? searchclassroom(*tmpcourse, k) : classroom[k]).getCapacityOfClassroom()) issuccess = 0;
							else for (int lc = 0; lc < sclass[j].size(); lc++)//�ж������༶�����Ƿ񶼿���ƥ�������ڿ�
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
										if ((lc != 0) && (lc % 2 == 0)) {//����༶ͬʱ�Ͽ�ʱ�����ҿα����ʦ�α���һ��ֻ��ӡ�����༶
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
								tmpcourse->setTime(t - 2);//����ǰ�γ̿�ʱ����Ϊʣ���ʱ��
								isfind = 1;
								schedule_course(indexOfClass, indexOfCourse);
								tmpcourse->setTime(t + 2);//���ſ�ʧ������ݵ���һ��
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
					else//�γ���С��4�����
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
	//�������Ͽ�
	for (int i = 0; i < 5; i++){
		int n = (i + indexOfClass + tmpcourse->getNumberOfCourse()) % 5;//�༶�źͿγ̺�����Ҫ�� ����������
		if (isrepeat(indexOfClass, *tmpcourse, n)) continue;
		if (tmpcourse->getTime() >= 4) {//��ʱ������3
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
		else {//�γ���С��4
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