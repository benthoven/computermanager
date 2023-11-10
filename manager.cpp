#include"manager.h"

manager::manager()
{

}
void manager::initalvector()
{
	//�������
	/*teacher_vec.clear();
	student_vec.clear();*/
	//��ȡѧ����Ϣ
	ifstream ifs;
	ifs.open("student.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "��ʧ��" << endl;
		return;
	}
	student s;
	while (ifs >> s.m_id && ifs >> s.m_name && ifs >> s.m_pas)//��ȡ������������
	{
		student_vec.push_back(s);
	}
	cout << "ѧ����ǰ����Ϊ" << student_vec.size() << endl;
	ifs.close();

	//��ȡ��ʦ��Ϣ

	ifs.open("teacher.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	teacher tec;
	while (ifs >> tec.empid && ifs >> tec.m_name && ifs >> tec.m_pas)//��ȡ������������
	{
		teacher_vec.push_back(tec);
	}
	cout << "��ʦ��ǰ����Ϊ" << teacher_vec.size() << endl;
	ifs.close();
}
//��ʼ����������
void manager::initial_computer()
{
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�򿪻����ļ�ʧ��" << endl;
	}
	computer com;
	//��ȡ�ļ�
	while (ifs >> com.c_id && ifs >> com.c_size)
	{
		com_vec.push_back(com);
	}
	cout << "��ǰ���л�������Ϊ" << com_vec.size() << endl;
	ifs.close();
}
manager::manager(string name, string pas)
{
	m_name = name;
	m_pas = pas;
	//��ʼ������ ��ȡ��Ϣ
	initalvector();
	/*for (vector<teacher>::iterator it = teacher_vec.begin(); it != teacher_vec.end(); it++)
	{
		cout << (*it).m_name << " " << (*it).m_pas << " " << (*it).empid << endl;
	}
	for (vector<student>::iterator it1 = student_vec.begin(); it1 != student_vec.end(); it1++)
	{
		cout << (*it1).m_name << " " << (*it1).m_pas << " " << (*it1).m_id<< endl;
	}*/
	//��ʼ����������
	initial_computer();
}
//����ظ���־λ
bool manager::checkrepeat(int id, int type)//�㱨����
{
	if (type == 1)//��ʦ
	{
		
		for (vector<teacher>::iterator it = teacher_vec.begin(); it != teacher_vec.end(); it++)
		{
			if (id == (*it).empid)
			{
				return true;
			}		
		}
		
	}
	if (type == 2)//ѧ��
	{
		
		for (vector<student>::iterator it1 = student_vec.begin(); it1 != student_vec.end(); it1++)
		{
			if (id == (*it1).m_id)//���ظ�������
			{
				return true;
			}	
		}
		
	}
	return false;
}
//�˵�����
void manager::showmenu()
{
	cout << "��ӭ����Ա��¼" << endl;
	cout << "��ѡ����" << endl;
	cout << "-----------------------" << endl;
	cout << "|      1.����˺�      |" << endl;
	cout << "|                      |" << endl;
	cout << "|      2.�鿴�˺�      |" << endl;
	cout << "|                      |" << endl;
	cout << "|      3.�鿴����      |" << endl;//��ʾ������ź��������
	cout << "|                      |" << endl;
	cout << "|      4.���ԤԼ      |" << endl;//���ԤԼ�ļ�
	cout << "|                      |" << endl;
	cout << "|      5.ע����¼      |" << endl;//�˳�����Ա��¼
	cout << "-----------------------" << endl;
}
//����˺�
void manager::addperson()
{
	int type = 0; 
	string filename;
	int id;
	string errortip;//������ʾ
	cout << "��ѡ��Ҫ��ӵ��û����" << endl;
	cout << "1.��ʦ" << endl;
	cout << "2.ѧ��" << endl;
	cin >> type;
	if (type == 1)//��ʦ
	{
		filename = TEACHER_FILE;
		cout << "������ְ�����" << endl;
		errortip = "��ʦ��������������������";
	}
	if (type == 2)
	{
		filename = STUDENT_FILE;
		cout << "������ѧ��" << endl;
		errortip = "ѧ�������������������";
	}
	
	cin >> id;
	//while (1)
	//{
	//	cin >> id;//������������
	//	bool flag = checkrepeat(id, type);//ȥ��
	//		if (flag == true)
	//		{
	//			cout << errortip << endl;
	//		}
	//		else
	//		{
	//			break;
	//		}
	//}
	//���ļ�
	ofstream ofs; 
	ofs.open(filename, ios::app);
	string name;
	string pas;
	cout << "�������û���" << endl;
	cin >> name;
	cout << "����������" << endl;
123	cin >> pas;
	//���������
	ofs << id << " " << name << " " << pas << " ";
	//�رմ���
	ofs.close();
	//initalvector();//���ó�ʼ���ӿ����µػ�ȡ�����ļ�
	cout << "������" << endl;
	system("pause");
	system("cls");
}
//�鿴�˺�

void printtea(teacher &tea)//��ʦ
{
	cout << tea.empid << " " << tea.m_name << " " <<tea.m_pas << endl;
}
void printstu(student& st)
{
	cout << st.m_id << " " << st.m_name << " " << st.m_pas << endl;
}
void manager::showperson()
{
	int select = 0;
	cout << "��ѡ��Ҫ�鿴������" << endl;
	cout << "1.��ʦ" << endl;
	cout << "2.ѧ��" << endl;
	cin >> select;
	if (select == 1)
	{
		cout << "��ʦ��Ϣ����" << endl;
		for_each(teacher_vec.begin(), teacher_vec.end(), printtea);//���һ������Ϊ�º���������ͨ����
	}
	if (select == 2)
	{
		cout << "ѧ����Ϣ����" << endl;
		for_each(student_vec.begin(), student_vec.end(), printstu);
	}
	system("pause");
	system("cls");

}
//�鿴������Ϣ
void manager::showcomputer()//��
{
	for (auto it= com_vec.begin(); it != com_vec.end(); it++)
	{
		cout << "������Ϣ����" << endl;
		cout << "������  " << (*it).c_id << " " << "��������Ϊ " << (*it).c_size << endl;
	}
}
//���ԤԼ��¼
void manager::clearfile()
{
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);//������ļ��ķ�ʽ���ļ�
	ofs.close();
	cout << "��ճɹ�" << endl;

	system("pause");
	system("cls");
}
//��ʼ��


manager::~manager()
{
	
}