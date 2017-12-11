#include"DisplaySches.h"
#include"yage.h"
#include"Teacher.h"
#include<string>
#include"Classroom.h"
#include"Course.h"
#include"DisplaySches.h"
#include"StudentClass.h"
#include"Orignal.h"

using namespace std;

void DisplaySches::displaySche(Orignal* a, int aaa){ 
	yage_draw_set_auto_update(false);
	yage_set_border_thickness(10);
	yage_set_border_color(yage_color_from_string("white"));
	yage_set_font("楷体", 20, 0, 0);
	yage_rectangle(0, 0, 1200, 720);
	switch (aaa){
	case 1:
		background2 = yage_canvas_load_image("class.jpg");
		yage_draw_canvas(background2, 0, 0, 1, 1);
		yage_draw_update();
		yage_canvas_delete(background2); break;
	case 2:background1 = yage_canvas_load_image("classroom.jpg"); yage_draw_canvas(background1, 0, 0, 1, 1);
		yage_draw_update();
		yage_canvas_delete(background1); break;
	default:background3 = yage_canvas_load_image("teacher.jpg");
		yage_draw_canvas(background3, 0, 0, 1, 1);
		yage_draw_update();
		yage_canvas_delete(background3); break;
	}
	yage_set_border_thickness(5); x = 0;
	for (int i = 0; i < 9; i++){ x += 80; yage_line_border(0, x, 1200, x); }
	x = 0;
	for (int i = 0; i < 5; i++){ x += 200; yage_line_border(x, 0, x, 720); }
	yage_printf(50, 40, "时间         星期一         星期二         星期三         星期四         星期五"); x = 0;
	for (int i = 0; i < 4; i++){ x = 8 + i; yage_printf(10, 120 + i * 80, "%d:00-%d:00", x, x + 1); }
	for (int i = 4; i < 8; i++){ x = 9 + i; yage_printf(10, 120 + i * 80, "%d:30-%d:30", x, x + 1); }
	yage_set_font("楷体", 13, 0, 0);
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 8; j++){
			yage_printf(200 * i + 210, 80 * j + 85, "%s", a->sche(i, j).c_str());
		}
	}
	yage_draw_update();
	yage_draw_set_auto_update(true);
}