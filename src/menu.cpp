#include"menu.h"

void menu(yage_window* de){
	//yage_window* de1 = yage_init(1000, 600);
	yage_window_set_default(de);
	yage_window_set_title("自动排课系统");	
	yage_draw_set_auto_update(false);
	yage_canvas *background0 = yage_canvas_load_image("login.jpg");
	yage_draw_canvas(background0, 0, 0, 1, 1);
	yage_draw_update();
	yage_canvas *manageBefore = yage_canvas_load_image("manageBefore.jpg");
	yage_canvas *manageAfter = yage_canvas_load_image("manageAfter.jpg");
	yage_button *buttonManage = yage_button_create(342, 220, 300, 75, manageBefore, manageAfter, manageAfter);
	yage_button_update(buttonManage);
	yage_draw_update();
	yage_canvas *inquireBefore = yage_canvas_load_image("inquireBefore.jpg");
	yage_canvas *inquireAfter = yage_canvas_load_image("inquireAfter.jpg");
	yage_button *buttonInquire = yage_button_create(342, 335, 300, 75, inquireBefore, inquireAfter, inquireAfter);
	yage_button_update(buttonInquire);
	yage_draw_update();
	yage_canvas *escapeBefore = yage_canvas_load_image("escapeBefore.jpg");
	yage_canvas *escapeAfter = yage_canvas_load_image("escapeAfter.jpg");
	yage_button *buttonEscape = yage_button_create(827, 500, 93, 55, escapeBefore, escapeAfter, escapeAfter);
	yage_button_update(buttonEscape);
	yage_draw_update();
	yage_message msg;
	char* secret;
	while (yage_get_message(&msg, 0)){
		if (yage_button_clicked(buttonManage, &msg)){
			yage_draw_update();
			yage_canvas_delete(background0);
			yage_canvas_delete(manageBefore);
			yage_canvas_delete(manageAfter);
			yage_canvas_delete(inquireBefore);
			yage_canvas_delete(inquireAfter);
			yage_canvas_delete(escapeBefore);
			yage_canvas_delete(escapeAfter);
			yage_button_delete(buttonManage);
			yage_button_delete(buttonInquire);
			yage_button_delete(buttonEscape);
			manage(de);
		}
		else if (yage_button_clicked(buttonInquire, &msg)){
			yage_draw_update();
			yage_canvas_delete(background0);
			yage_canvas_delete(manageBefore);
			yage_canvas_delete(manageAfter);
			yage_canvas_delete(inquireBefore);
			yage_canvas_delete(inquireAfter);
			yage_canvas_delete(escapeBefore);
			yage_canvas_delete(escapeAfter);
			yage_button_delete(buttonManage);
			yage_button_delete(buttonInquire);
			yage_button_delete(buttonEscape);
			inquire(de);
		}
		else if (yage_button_clicked(buttonEscape, &msg)){
			//yage_draw_update();
			yage_canvas_delete(background0);
			yage_canvas_delete(manageBefore);
			yage_canvas_delete(manageAfter);
			yage_canvas_delete(inquireBefore);
			yage_canvas_delete(inquireAfter);
			yage_canvas_delete(escapeBefore);
			yage_canvas_delete(escapeAfter);
			yage_button_delete(buttonManage);
			yage_button_delete(buttonInquire);
			yage_button_delete(buttonEscape);
			yage_quit();
			return;
		}
	}
}

void show_txt(const string &path)
{
	string exec = "%windir%\\system32\\notepad.exe " + path;
	system(exec.c_str());
}

void manage(yage_window* de){
	yage_window_set_default(de);
	yage_window_set_title("自动排课系统");
	yage_canvas *manageBackground = yage_canvas_load_image("manageBackground.jpg");
	yage_draw_canvas(manageBackground, 0, 0, 1, 1);
	yage_draw_update();
	yage_canvas *teacherManageBefore = yage_canvas_load_image("teacherManageBefore.jpg");
	yage_canvas *teacherManageAfter = yage_canvas_load_image("teacherManageAfter.jpg");
	yage_button *buttonTeacherManage = yage_button_create(342, 150, 300, 75, teacherManageBefore, teacherManageAfter, teacherManageAfter);
	yage_button_update(buttonTeacherManage);
	yage_canvas *courseManageBefore = yage_canvas_load_image("courseManageBefore.jpg");
	yage_canvas *courseManageAfter = yage_canvas_load_image("courseManageAfter.jpg");
	yage_button *buttonCourseManage = yage_button_create(342, 230, 300, 75, courseManageBefore, courseManageAfter, courseManageAfter);
	yage_button_update(buttonCourseManage);
	yage_canvas *classroomManageBefore = yage_canvas_load_image("classroomManageBefore.jpg");
	yage_canvas *classroomManageAfter = yage_canvas_load_image("classroomManageAfter.jpg");
	yage_button *buttonClassroomManage = yage_button_create(342, 310, 300, 75, classroomManageBefore, classroomManageAfter, classroomManageAfter);
	yage_button_update(buttonClassroomManage);
	yage_canvas *classManageBefore = yage_canvas_load_image("classManageBefore.jpg");
	yage_canvas *classManageAfter = yage_canvas_load_image("classManageAfter.jpg");
	yage_button *buttonClassManage = yage_button_create(342, 390, 300, 75, classManageBefore, classManageAfter, classManageAfter);
	yage_button_update(buttonClassManage);
	yage_canvas *geneScheduleBefore = yage_canvas_load_image("geneScheduleBefore.jpg");
	yage_canvas *geneScheduleAfter = yage_canvas_load_image("geneScheduleAfter.jpg");
	yage_button *buttonGeneSchedule = yage_button_create(342, 470, 300, 75, geneScheduleBefore, geneScheduleAfter, geneScheduleAfter);
	yage_button_update(buttonGeneSchedule);
	yage_canvas *returnBefore = yage_canvas_load_image("returnBefore.jpg");
	yage_canvas *returnAfter = yage_canvas_load_image("returnAfter.jpg");
	yage_button *buttonReturn = yage_button_create(717, 500, 93, 55, returnBefore, returnAfter, returnAfter);
	yage_button_update(buttonReturn);
	yage_canvas *escapeBefore = yage_canvas_load_image("escapeBefore.jpg");
	yage_canvas *escapeAfter = yage_canvas_load_image("escapeAfter.jpg");
	yage_button *buttonEscape = yage_button_create(827, 500, 93, 55, escapeBefore, escapeAfter, escapeAfter);
	yage_button_update(buttonEscape);
	yage_draw_update();
	yage_message msg;
	while (yage_get_message(&msg, 0))
	{
		if (yage_button_clicked(buttonTeacherManage, &msg)){
			yage_draw_update();
			show_txt("teacher.txt");
		}
		else if (yage_button_clicked(buttonCourseManage, &msg)){
			yage_draw_update();
			show_txt("course.txt");
		}
		else if (yage_button_clicked(buttonClassroomManage, &msg)){
			yage_draw_update();
			show_txt("classroom.txt");
		}
		else if (yage_button_clicked(buttonClassManage, &msg)){
			yage_draw_update();
			show_txt("studentclass.txt");
		}
		else if (yage_button_clicked(buttonGeneSchedule, &msg)){
			yage_draw_update();
			readFile(classroom, course, studentclass, teacher);
			try{
				schedule_class(0);
			}
			catch (int e){}
			writeSche();
		}
		else if (yage_button_clicked(buttonReturn, &msg)){
			yage_draw_update();
			yage_canvas_delete(manageBackground);
			yage_canvas_delete(teacherManageBefore);
			yage_canvas_delete(teacherManageAfter);
			yage_canvas_delete(courseManageBefore);
			yage_canvas_delete(courseManageAfter);
			yage_canvas_delete(classManageBefore);
			yage_canvas_delete(classManageAfter);
			yage_canvas_delete(classroomManageBefore);
			yage_canvas_delete(classroomManageAfter);
			yage_canvas_delete(geneScheduleBefore);
			yage_canvas_delete(geneScheduleAfter);
			yage_canvas_delete(returnBefore);
			yage_canvas_delete(returnAfter);
			yage_canvas_delete(escapeBefore);
			yage_canvas_delete(escapeAfter);
			yage_button_delete(buttonTeacherManage);
			yage_button_delete(buttonCourseManage);
			yage_button_delete(buttonClassroomManage);
			yage_button_delete(buttonClassManage);
			yage_button_delete(buttonGeneSchedule);
			yage_button_delete(buttonReturn);
			yage_button_delete(buttonEscape);
			menu(de);
		}
		else if (yage_button_clicked(buttonEscape, &msg)){
			//yage_draw_update();
			yage_canvas_delete(manageBackground);
			yage_canvas_delete(teacherManageBefore);
			yage_canvas_delete(teacherManageAfter);
			yage_canvas_delete(courseManageBefore);
			yage_canvas_delete(courseManageAfter);
			yage_canvas_delete(classManageBefore);
			yage_canvas_delete(classManageAfter);
			yage_canvas_delete(classroomManageBefore);
			yage_canvas_delete(classroomManageAfter);
			yage_canvas_delete(geneScheduleBefore);
			yage_canvas_delete(geneScheduleAfter);
			yage_canvas_delete(returnBefore);
			yage_canvas_delete(returnAfter);
			yage_canvas_delete(escapeBefore);
			yage_canvas_delete(escapeAfter);
			yage_button_delete(buttonTeacherManage);
			yage_button_delete(buttonCourseManage);
			yage_button_delete(buttonClassroomManage);
			yage_button_delete(buttonClassManage);
			yage_button_delete(buttonGeneSchedule);
			yage_button_delete(buttonReturn);
			yage_button_delete(buttonEscape);
			yage_quit();
			return;
		}
	}
}

bool isin1(int &nnn, int number)
{
	for (int i = 0; i < classroom.size(); i++){
		if (number == classroom[i].getNameOfClassroom()){
			nnn = i;
			return true;
		}
	}
	return false;
}

bool isin2(int &nnn, int number)
{
	for (int i = 0; i < studentclass.size(); i++){
		if (number == studentclass[i].getNumberOfClass()){
			nnn = i;
			return true;
		}
	}
	return false;
}

bool isin3(int &nnn, char *name)
{
	for (int i = 0; i < teacher.size(); i++){
		if (name == teacher[i].getNameOfTeacher()){
			nnn = i;
			return true;
		}
	}
	return false;
}

void inquire(yage_window* de){
	//readSche();
	yage_window_set_default(de);
	yage_window_set_title("自动排课系统");
	yage_canvas *background = yage_canvas_load_image("Background.jpg");
	yage_draw_canvas(background, 0, 0, 1, 1);
	yage_draw_update();
	yage_canvas *classroomBefore = yage_canvas_load_image("Classroom_Before.jpg");
	yage_canvas *classroomAfter = yage_canvas_load_image("Classroom_After.jpg");
	yage_button *buttonClassroom = yage_button_create(342, 220, 300, 75, classroomBefore, classroomAfter, classroomAfter);
	yage_button_update(buttonClassroom);
	yage_draw_update();
	yage_canvas *studentBefore = yage_canvas_load_image("Student_Before.jpg");
	yage_canvas *studentAfter = yage_canvas_load_image("Student_After.jpg");
	yage_button *buttonStudentClass = yage_button_create(342, 320, 300, 75, studentBefore, studentAfter, studentAfter);
	yage_button_update(buttonStudentClass);
	yage_draw_update();
	yage_canvas *teacherBefore = yage_canvas_load_image("Teacher_Before.jpg");
	yage_canvas *teacherAfter = yage_canvas_load_image("Teacher_After.jpg");
	yage_button *buttonTeacher = yage_button_create(342, 420, 300, 75, teacherBefore, teacherAfter, teacherAfter);
	yage_button_update(buttonTeacher);
	yage_draw_update();
	yage_canvas *returnBefore = yage_canvas_load_image("returnBefore.jpg");
	yage_canvas *returnAfter = yage_canvas_load_image("returnAfter.jpg");
	yage_button *buttonReturn = yage_button_create(717, 500, 93, 55, returnBefore, returnAfter, returnAfter);
	yage_button_update(buttonReturn);
	yage_draw_update();
	yage_canvas *escapeBefore = yage_canvas_load_image("escapeBefore.jpg");
	yage_canvas *escapeAfter = yage_canvas_load_image("escapeAfter.jpg");
	yage_button *buttonEscape = yage_button_create(827, 500, 93, 55, escapeBefore, escapeAfter, escapeAfter);
	yage_button_update(buttonEscape);
	yage_draw_update();
	yage_window* pp; 
	char* name("");
	DisplaySches dis;
	yage_message msg;
	first:
	while (yage_get_message(&msg, 0)){
		int number(-1), nnn(-1);
		if (yage_button_clicked(buttonClassroom, &msg)){
			yage_draw_update();
			number = yage_input_int("请输入教室对应号码", "例如：学二楼529，输入2529");
			while (!isin1(nnn, number) && number != INT_MIN)
				number = yage_input_int("信息有误！", "请重新输入有效的教室信息。例如：学二楼529，输入2529");
			if (number == INT_MIN)
				goto first;
			pp = yage_window_create(1200, 720);
			yage_window_set_default(pp);
			yage_window_set_title("教室应用情况");
			yage_draw_update();
			dis.displaySche(&classroom[nnn], 1);
			yage_window_set_default(de);
			yage_draw_set_auto_update(false);
		}
		else if (yage_button_clicked(buttonStudentClass, &msg)){
			yage_draw_update();
			number = yage_input_int("请输入班级号码", "例如：2014211301");
			while (!isin2(nnn, number) && number != INT_MIN)
				number = yage_input_int("信息有误！", "请重新输入有效的班级信息。例如：2014211301");
			if (number == INT_MIN)
				goto first;
			pp = yage_window_create(1200, 720);
			yage_window_set_default(pp);
			yage_window_set_title("班级的时间表");
			yage_draw_update();
			dis.displaySche(&studentclass[nnn], 2);
			yage_window_set_default(de);
			yage_draw_set_auto_update(false);
		}
		else if (yage_button_clicked(buttonTeacher, &msg)){
			yage_draw_update();
			name = yage_input_line("请输入教师的姓名", "例如：刘利");
			while (name != NULL && !isin3(nnn, name))
				name = yage_input_line("信息有误！", "请重新输入有效的教师信息。例如：刘利");
			if (name == NULL)
				goto first;
			pp = yage_window_create(1200, 720);
			yage_window_set_default(pp);
			yage_window_set_title("老师的时间表");
			yage_draw_update();
			dis.displaySche(&teacher[nnn], 3);
			yage_window_set_default(de);
			yage_draw_set_auto_update(false);
		}
		else if (yage_button_clicked(buttonReturn, &msg)){
			yage_draw_update();
			yage_canvas_delete(background);
			yage_canvas_delete(classroomBefore);
			yage_canvas_delete(classroomAfter);
			yage_canvas_delete(studentBefore);
			yage_canvas_delete(studentAfter);
			yage_canvas_delete(teacherBefore);
			yage_canvas_delete(teacherAfter);
			yage_canvas_delete(returnBefore);
			yage_canvas_delete(returnAfter);
			yage_canvas_delete(escapeBefore);
			yage_canvas_delete(escapeAfter);
			yage_button_delete(buttonClassroom);
			yage_button_delete(buttonStudentClass);
			yage_button_delete(buttonTeacher);
			yage_button_delete(buttonReturn);
			yage_button_delete(buttonEscape);
			menu(de);
		}
		else if (yage_button_clicked(buttonEscape, &msg)) {
			//yage_draw_update();
			yage_canvas_delete(background);
			yage_canvas_delete(classroomBefore);
			yage_canvas_delete(classroomAfter);
			yage_canvas_delete(studentBefore);
			yage_canvas_delete(studentAfter);
			yage_canvas_delete(teacherBefore);
			yage_canvas_delete(teacherAfter);
			yage_canvas_delete(returnBefore);
			yage_canvas_delete(returnAfter);
			yage_canvas_delete(escapeBefore);
			yage_canvas_delete(escapeAfter);
			yage_button_delete(buttonClassroom);
			yage_button_delete(buttonStudentClass);
			yage_button_delete(buttonTeacher);
			yage_button_delete(buttonReturn);
			yage_button_delete(buttonEscape);
			yage_quit();
			return;
		}
	}
}
