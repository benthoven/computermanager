#include<iostream>
using namespace std;
#include<fstream>
#include"globalfile.h"
#include"manager.h"
#include"student.h"
#include"teacher.h"
#include<memory>

//����Ա���ܽӿ�
void managerfunction(shared_ptr<identity>& person)//identity* &person//ָ�������  identity*Ҳ��һ�ֱ�����ָ�봫��ʱҲ��ֵ���ݣ���Ҫ�ں����б����޸ĺ��ָ���ַ��Ҫָ������û�ָ�봫�ݣ���������ͨ��������
{
	
	//Ҫ��������ǹ�ͬ��������ת������
	
	manager* man = (manager*)&person;
	//man->showcomputer();
	int select = 0;
	cout << "���������ѡ��" << endl;
	
	//ѡ���֧
	while (1)
	{
		person->showmenu();
		cin >> select;
		switch (select)
		{
		case 1://����˺�

			man->addperson();
			//man->initalvector();
			system("pause");
			system("cls");

			break;
		case 2://�鿴�˺�
			man->showperson();
			system("pause");
			system("cls");
			break;
		case 3://�鿴����
			man->showcomputer();
			system("pause");
			system("cls");
			break;
		case 4://ɾ��ԤԼ��¼
			man->clearfile();
			system("pause");
			system("cls");
			break;
		case 5://ע����¼
			//���ٶ�������
			//delete person;
			//person = NULL;
			cout << "���ٳɹ�" << endl;
			system("pause");
			system("cls");
			return;
			break;
		default://ע��
			return;
			break;
		}
	}
		
}
//ѧ���˽ӿ�
void studentfunction(shared_ptr<identity>& person)//identity* &person//ָ�������  identity*Ҳ��һ�ֱ�����ָ�봫��ʱҲ��ֵ���ݣ���Ҫ�ں����б����޸ĺ��ָ���ַ��Ҫָ������û�ָ�봫�ݣ���������ͨ��������
{

	//Ҫ��������ǹ�ͬ��������ת������
	
	student*stu = (student*)person.get();//get����ָ��תΪ��ָͨ��
	
	int select = 0;
	cout << "���������ѡ��" << endl;

	//ѡ���֧
	while (1)
	{
		person->showmenu();
		cin >> select;
		switch (select)
		{
		case 1://����ԤԼ

			stu->applyorder();
			system("pause");
 			system("cls");

			break;
		case 2://�鿴ԤԼ
			stu->showorder();
			system("pause");
			system("cls");
			break;
		case 3://�鿴����ԤԼ
			stu->showallorder();
			system("pause");
			system("cls");
			break;
		case 4://ȡ��ԤԼ
			stu->cancelorder();
			system("pause");
			system("cls");
			break;
		case 5://ע����¼
			//���ٶ�������
			//delete person;
			//person = NULL;����ָ����Զ�����
			cout << "���ٳɹ�" << endl;
			system("pause");
			system("cls");
			return;
			break;
		default://ע��
			return;
			break;
		}
	}

}
//��¼����
void personlogin(string filename, int type)
{
	//��������ָ�����������ָ������ʵ�ֶ�̬
	//identity* person = NULL;
//���ļ���ȷ���Ƿ����
	ifstream ifst;
	ifst.open(filename, ios::in);
	if (!ifst.is_open())//�ж��Ƿ��  �򿪷���1����ֱ��!ifst
	{
		cout << "û���ҵ��ļ�����ʧ��" << endl;
		ifst.close();//ֱ�ӹر�
		return;
	}
	//׼�������û���Ϣ
	int id = 0;
	string name;
	string pas;
	//�ж����
	if (type == 1)//ѧ��
	{
		cout << "����������ѧ��" << endl;
		cin >> id;
	}
	if (type == 2)//��ʦ
	{
		cout << "���������ְ����" << endl;
		cin >> id;
	}
	cout << "�������û���" << endl;
	cin >> name;
	cout << "����������" << endl;
	cin >> pas;
	//��֤���
	if (type == 1)
	{//ѧ�������֤
		int fid;//�ļ���ȡ��ID
		string fname;//�ļ���ȡ������
		string fpas;//�ļ���ȡ������
		while (ifst >> fid && ifst >> fname && ifst >> fpas)//������ζ�ȡ�������ݣ������ո�ͻ����
		{
			
			if (fid == id && fname == name && fpas == pas)
			{
				cout << "��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				system("pause");
				shared_ptr<identity> person = make_shared<student>(id, name, pas);
				//person = new student(id,name,pas);//ָ���������,�����Ӳ˵����棬����������Ϣ��������
				studentfunction(person);
				return;
			}
			else
			{
				cout << "��¼ʧ��" << endl;
				system("pause");
				system("cls");
				return;
			}
		}
	}
	else if (type == 2)
	{//��ʦ�����֤
		int tid;//�ļ���ȡ��ID
		string tname;//�ļ���ȡ������
		string tpas;//�ļ���ȡ������
		while (ifst >> tid && ifst >> tname && ifst >>tpas)//������ζ�ȡ�������ݣ������ո�ͻ����
		{
			/*cout << tid << endl;
			cout << tname << endl;
			cout << tpas << endl;
			cout << endl;*/
			if (tid == id && tname == name && tpas == pas)
			{
				cout << "��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				system("pause");
				shared_ptr<identity> person = make_shared<manager>(name, pas);//ָ���������,�����Ӳ˵����棬����������Ϣ��������
				return;
			}
			else
			{
				cout << "��¼ʧ��" << endl;
				system("pause");
				system("cls");
				return;
			}
		}
	}
	else if (type == 3)
	{//��֤����Ա��� ֻ��һ������Ա��������ӹ���Ա����
		string mname;//�ļ���ȡ������
		string mpas;//�ļ���ȡ������
		while ( ifst >> mname && ifst >> mpas)//������ζ�ȡ�������ݣ������ո�ͻ����
		{
			/*cout << mname << endl;
			cout << mpas << endl;
			cout << endl;*/
			if ( mname == name && mpas == pas)
			{
				cout << "��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				shared_ptr<identity> person = make_shared<manager>(name, pas);//ָ���������,�����Ӳ˵����棬����������Ϣ��������
				//���ܽӿ�
				managerfunction(person);
				system("pause");
				return;
			}
			else
			{
				cout << "��¼ʧ��" << endl;
				system("pause");
				system("cls");
				return;
			}
		}

	}
	else
	{
		cout << "��֤ʧ��" << endl;
		system("pause");
		system("cls");
	}
	ifst.close();
}

int main()
{
	int choice = 0;
	while (1)
	{
		cout << "==========��ӭʹ�û���ԤԼ����ϵͳ==========" << endl;
		cout << "��ѡ���������" << endl;
		cout << "-------------------------" << endl;
		cout << "|      1.ѧ������       |" << endl;
		cout << "|                       |" << endl;
		cout << "|      2.��ʦ           |" << endl;
		cout << "|                       |" << endl;
		cout << "|      3.����Ա         |" << endl;
		cout << "|                       |" << endl;
		cout << "|      0.������һ��     |" << endl;
		cout << "-------------------------" << endl;
		cout << "��ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1://ѧ�����
			personlogin(STUDENT_FILE, 1);
			break;
		case 2://��ʦ���
			personlogin(TEACHER_FILE, 2);
			break;
		case 3://����Ա���
			personlogin(ADMIN_FILE, 3);
			break;
		case 0://�˳�
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "����������" << endl;
			system("pause");
			system("cls");
			break;

		}
	}
	


	system("pause");
	return 0;
}