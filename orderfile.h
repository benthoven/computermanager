#pragma once
#include<iostream>
using namespace std;
#include<map>
#include<fstream>
#include"globalfile.h"

class orderfile
{
public:
	//���캯��
	orderfile();
	//����ԤԼ��¼
	void updateorder();
	//��¼ԤԼ����
	int m_size;
	//��¼����ԤԼ��Ϣ������ key��¼����(ÿһ��) value �����¼��ֵ����Ϣ
	map<int, map<string, string>>order_data;//Ƕ������
};
