#pragma once
#include"identity����.h"
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

	//�˵�����
	void showmenu();
	//t����˺�
	void addperson();
	//�鿴�˺�
	void showperson();
	//�鿴������Ϣ
	void showcomputer();
	//���ԤԼ��¼
	void clearfile();
	//��ʼ������
	void initalvector();
	//����ظ���־λ   1.���ѧ�š�ְ����  ����2 �������
	bool checkrepeat(int id, int type);
	//��ʼ����������
	void initial_computer();
	//����ѧ������
	vector<student>student_vec;
	vector<teacher>teacher_vec;
	vector<computer>com_vec;
	//shared_ptr<vector<computer>>com_vec;
	~manager();
};