#pragma once
#include"identity基类.h"
#include"globalfile.h"
#include<fstream>
#include<vector>
#include"student.h"
#include"teacher.h"
#include<algorithm>
#include"computer.h"

class manager:virtual public identity
{
public:
	
	manager();

	manager(string name, string pas);

	//菜单界面
	void showmenu();
	//t添加账号
	void addperson();
	//查看账号
	void showperson();
	//查看机房信息
	void showcomputer();
	//清空预约记录
	void clearfile();
	//初始化容器
	void initalvector();
	//检测重复标志位   1.检测学号、职工号  参数2 检测类型
	bool checkrepeat(int id, int type);
	//初始化电脑容器
	void initial_computer();
	//创建学生容器
	vector<student>student_vec;
	vector<teacher>teacher_vec;
	vector<computer>com_vec;
	//shared_ptr<vector<computer>>com_vec;
	~manager();
};