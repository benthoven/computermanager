#pragma once
#include"identity����.h"
#include<string>
#include"globalfile.h"
#include<fstream>
#include"orderfile.h"

class student : public identity
{
public:
	
	student();
	//�вι���
	student(int id, string name, string pas);
	//�˵�����
	virtual void showmenu();
	//����ԤԼ
	void applyorder();
	//�鿴����ԤԼ
	void showorder();
//�鿴����ԤԼ
	void showallorder();
	//ȡ��ԤԼ
	void cancelorder();
	~student();
	int m_id;
};