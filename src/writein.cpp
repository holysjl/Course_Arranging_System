//�γ̱���Ϣ�ı���
#include<string>
#include<fstream>
#include"writein.h"
#include"variable.h"

void writein(Orignal* ppp, fstream& kitty, int t){
	switch (t)
	{
	case 1: t1 = dynamic_cast<Teacher*>(ppp); kitty  << t1->getNameOfTeacher() << endl; break;
	case 2: t2 = dynamic_cast<StudentClass*>(ppp);
		kitty << t2->getNumberOfClass() <<"�Ŀγ̱�" <<"\\" << endl; break;
	default: t3 = dynamic_cast<Classroom*>(ppp);
		kitty << t3->getNameOfClassroom() <<"�Ŀγ̱�"<< "\\" << endl; break;
	}
	for (int i = 0; i <8; i++){
		for (int j = 0; j < 5; j++){
			if (ppp->sche(j, i) == "\0") kitty << "free" << " ";
			else kitty << ppp->sche(j, i) << " ";
		}
		kitty << endl;
	}

}