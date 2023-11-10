#pragma once
#include"identity基类.h"
#include<string>
#include"globalfile.h"
#include<fstream>
#include"orderfile.h"

class student : public identity
{
public:
	
	student();
	//有参构造
	student(int id, string name, string pas);
	//菜单界面
	virtual void showmenu();
	//申请预约
	void applyorder();
	//查看自身预约
	void showorder();
//查看所有预约
	void showallorder();
	//取消预约
	void cancelorder();
	~student();
	int m_id;
};