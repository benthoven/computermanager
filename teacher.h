#pragma once
#include"identity基类.h"


class teacher: public identity
{
public:

	//默认构造
	teacher();

	teacher(int tempid, string tname, string tpas);
	//显示页面
	virtual void showmenu();
//查看预约
	void showallorder();
	//审核预约
	void validorder();
	~teacher();

	int empid;//教师编号

};