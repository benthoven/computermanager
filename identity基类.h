#pragma once
#include<iostream>
using namespace std;

class identity
{
public:
//操作菜单，属于共性，但是显示内容不同，属于个性
	virtual void showmenu() = 0;//父类纯虚，子类重写，否则无法创建对象

	string m_name;//用户名
	string m_pas;//密码

};