//�γ̱���Ϣ�Ĵ�ӡ
#include"writeSche.h"
#include"writein.h"
#include"variable.h"

void writeSche(){
	fstream kitty; kitty.open("��ʦ�Ŀγ̱�.txt", ios::out);
	for (int i = 0; i < teacher.size(); i++){
		writein(&teacher[i], kitty, 1);
	}
	kitty.close();
	kitty.open("�༶�Ŀγ̱�.txt", ios::out);
	for (int i = 0; i < studentclass.size(); i++){
		writein(&studentclass[i], kitty, 2);
	}
	kitty.close();
	kitty.open("���ҵĿγ̱�.txt", ios::out);
	for (int i = 0; i < classroom.size(); i++){
		writein(&classroom[i], kitty, 3);
	}
	kitty.close();
}