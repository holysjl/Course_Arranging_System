//保存的课表文件的读取
#include"readin.h"
#include<string>
#include<fstream>
#include"variable.h"

void readin(Orignal* ppp, fstream& kitty){
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 5; j++){
			kitty >> x;
			if (x != "free"){
				if (x != "Busy."){
					kitty >> x1 >> x2;
					ppp->sche(j, i) = x + "\n" + x1 + "\n" + x2 + "\n";
				}
				else ppp->sche(j, i) = "Busy.";
			}
		}
	}

}