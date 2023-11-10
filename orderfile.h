#pragma once
#include<iostream>
using namespace std;
#include<map>
#include<fstream>
#include"globalfile.h"

class orderfile
{
public:
	//构造函数
	orderfile();
	//更新预约记录
	void updateorder();
	//记录预约条数
	int m_size;
	//记录所有预约信息的容器 key记录条数(每一行) value 具体记录键值对信息
	map<int, map<string, string>>order_data;//嵌套容器
};
