#pragma once
#include"identity����.h"


class teacher: public identity
{
public:

	//Ĭ�Ϲ���
	teacher();

	teacher(int tempid, string tname, string tpas);
	//��ʾҳ��
	virtual void showmenu();
//�鿴ԤԼ
	void showallorder();
	//���ԤԼ
	void validorder();
	~teacher();

	int empid;//��ʦ���

};