#include"student.h"
#include"manager.h"
student::student()
{

}
//�вι���
student::student(int id, string name, string pas)
{
	m_id = id;
	m_name = name;
	m_pas = pas;
}
//�˵�����
 void student::showmenu()
{
	 cout << "��ӭѧ������" << " :"<<m_name << "��¼" << endl;
	 cout << "��ѡ����" << endl;
	 cout << "-----------------------" << endl;
	 cout << "|      1.����ԤԼ      |" << endl;
	 cout << "|                      |" << endl;
	 cout << "|      2.�鿴�ҵ�ԤԼ  |" << endl;
	 cout << "|                      |" << endl;
	 cout << "|      3.�鿴����ԤԼ  |" << endl;//��ʾ������ź��������
	 cout << "|                      |" << endl;
	 cout << "|      4.ȡ��ԤԼ      |" << endl;//���ԤԼ�ļ�
	 cout << "|                      |" << endl;
	 cout << "|      5.ע����¼      |" << endl;//�˳�����Ա��¼
	 cout << "-----------------------" << endl;
}
//����ԤԼ
void student::applyorder()
{
	cout << "��ѡ��ԤԼʱ��" << endl;
	cout << "1.��һ" << endl;
	cout << "2.�ܶ�" << endl;
	cout << "3.����" << endl;
	cout << "4.����" << endl;
	cout << "5.����" << endl;
	int data = 0;
	int interdata = 0;//ʱ���
	int room = 0;//����
	int status=1;//���״̬  1�����

	while (1)//������˲ſ����˳�
	{
		cin >> data;
		if (data < 0 || data>5)
		{
			cout << "����������" << endl;
		}
		else
		{
			break;
		}
	}
	cout << "��ѡ��ԤԼʱ���" << endl;
	cout << "1.����" << endl;
	cout << "2.����" << endl;
	while (1)
	{
		cin >> interdata;
		if (interdata < 1 || interdata>2)
		{
			cout << "����������" << endl;
		}
		else
		{
			break;
		}
	}
	cout << "��ѡ�������" << endl;
	//�ڶ�������һ��manager������ʳ�Ա����
	shared_ptr<manager>man = make_shared<manager>();
	man->showcomputer();
	while (1)
	{
		cin >> room;
		if (room < 1 || room>3)
		{
			cout << "�������,��������" << endl;
		}
		else
		{
			break;
		}
	}
	cout << "����ɹ�����ȴ�����" << endl;
	//д���ļ�
	ofstream ofs;
	ofs.open(ORDER_FILE,ios::app);
	if (!ofs.is_open())
	{
		cout << "ԤԼ�ļ���ʧ��" << endl;
	}
	ofs << "��������:" << data <<" " << "ʱ��:" << interdata << " " << "������:" << room << " " << "״̬:" << status << " " << endl;
	ofs.close();
	system("pause");
	system("cls");
}
//�鿴����ԤԼ(����ѧ��������ʵ��)
void student::showorder()
{
	orderfile of;
	if (of.m_size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		//******
	}
}
//�鿴����ԤԼ
void student::showallorder()
{
	orderfile ord;//��������ͬʱ��ʼ������ ��ӡ����
	if (ord.m_size == 0)
	{
		cout << "û��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 1; i <= ord.m_size;i++)
	{
		cout << i << ", ";
		cout << "ԤԼʱ�䣺��" << ord.order_data[i]["��������"];
		cout << " ʱ��:" << ord.order_data[i]["ʱ��"];
		cout << " ������:" << ord.order_data[i]["������"];
		//״̬��Ҫƴ��  //1�����  2��ԤԼ -1ԤԼʧ�� 0ȡ��ԤԼ
		string status = "״̬��";
		if (ord.order_data[i]["״̬"] == "1")//�����ʱ���õ���string����Ҫ��""
		{
			status += "�����";
		}
		else if (ord.order_data[i]["״̬"] == "2")
		{
			status += "��ԤԼ";
		}
		else if (ord.order_data[i]["״̬"] == "0")
		{
			status += "��ȡ��";
		}
		else if (ord.order_data[i]["״̬"] == "-1")
		{
			status += "ԤԼʧ��,���δͨ��";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
	return;
	
}
//ȡ��ԤԼ
void student::cancelorder()
{

}
student::~student()
{

}