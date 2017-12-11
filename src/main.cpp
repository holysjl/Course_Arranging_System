#include <iostream>
#include "readFile.h"
#include "yage.h"
#include "DisplaySches.h"
#include"menu.h"
#include"variable.h"

using namespace std;

int main(){
	readFile(classroom, course, studentclass, teacher);
	try{
		schedule_class(0);
	}
	catch (int e){ }
	yage_window* de = yage_init(1000, 600);
	yage_player* playmusic = yage_player_load_music("music.mp3");
	writeSche();
	menu(de);
	yage_draw_set_auto_update(true);
	return 0;
}