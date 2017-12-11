//定义抽象类纯虚函数，便于读取课表
#pragma once
#include<string>
using namespace std;
class Orignal{
public:
	virtual string & sche(int, int) = 0;
};