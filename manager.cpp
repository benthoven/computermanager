#include"manager.h"

manager::manager()
{

}
void manager::initalvector()
{
	//清空容器
	/*teacher_vec.clear();
	student_vec.clear();*/
	//读取学生信息
	ifstream ifs;
	ifs.open("student.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "打开失败" << endl;
		return;
	}
	student s;
	while (ifs >> s.m_id && ifs >> s.m_name && ifs >> s.m_pas)//读取后存入对象属性
	{
		student_vec.push_back(s);
	}
	cout << "学生当前人数为" << student_vec.size() << endl;
	ifs.close();

	//读取教师信息

	ifs.open("teacher.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	teacher tec;
	while (ifs >> tec.empid && ifs >> tec.m_name && ifs >> tec.m_pas)//读取后存入对象属性
	{
		teacher_vec.push_back(tec);
	}
	cout << "教师当前人数为" << teacher_vec.size() << endl;
	ifs.close();
}
//初始化机房容器
void manager::initial_computer()
{
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "打开机房文件失败" << endl;
	}
	computer com;
	//读取文件
	while (ifs >> com.c_id && ifs >> com.c_size)
	{
		com_vec.push_back(com);
	}
	cout << "当前空闲机房数量为" << com_vec.size() << endl;
	ifs.close();
}
manager::manager(string name, string pas)
{
	m_name = name;
	m_pas = pas;
	//初始化容器 读取信息
	initalvector();
	/*for (vector<teacher>::iterator it = teacher_vec.begin(); it != teacher_vec.end(); it++)
	{
		cout << (*it).m_name << " " << (*it).m_pas << " " << (*it).empid << endl;
	}
	for (vector<student>::iterator it1 = student_vec.begin(); it1 != student_vec.end(); it1++)
	{
		cout << (*it1).m_name << " " << (*it1).m_pas << " " << (*it1).m_id<< endl;
	}*/
	//初始化机房容器
	initial_computer();
}
//检测重复标志位
bool manager::checkrepeat(int id, int type)//汇报问题
{
	if (type == 1)//老师
	{
		
		for (vector<teacher>::iterator it = teacher_vec.begin(); it != teacher_vec.end(); it++)
		{
			if (id == (*it).empid)
			{
				return true;
			}		
		}
		
	}
	if (type == 2)//学生
	{
		
		for (vector<student>::iterator it1 = student_vec.begin(); it1 != student_vec.end(); it1++)
		{
			if (id == (*it1).m_id)//有重复返回真
			{
				return true;
			}	
		}
		
	}
	return false;
}
//菜单界面
void manager::showmenu()
{
	cout << "欢迎管理员登录" << endl;
	cout << "请选择功能" << endl;
	cout << "-----------------------" << endl;
	cout << "|      1.添加账号      |" << endl;
	cout << "|                      |" << endl;
	cout << "|      2.查看账号      |" << endl;
	cout << "|                      |" << endl;
	cout << "|      3.查看机房      |" << endl;//显示机房编号和最大容量
	cout << "|                      |" << endl;
	cout << "|      4.清空预约      |" << endl;//清空预约文件
	cout << "|                      |" << endl;
	cout << "|      5.注销登录      |" << endl;//退出管理员登录
	cout << "-----------------------" << endl;
}
//添加账号
void manager::addperson()
{
	int type = 0; 
	string filename;
	int id;
	string errortip;//错误提示
	cout << "请选择要添加的用户类别" << endl;
	cout << "1.教师" << endl;
	cout << "2.学生" << endl;
	cin >> type;
	if (type == 1)//教师
	{
		filename = TEACHER_FILE;
		cout << "请输入职工编号" << endl;
		errortip = "教师编号输入错误，请重新输入";
	}
	if (type == 2)
	{
		filename = STUDENT_FILE;
		cout << "请输入学号" << endl;
		errortip = "学号输入错误，请重新输入";
	}
	
	cin >> id;
	//while (1)
	//{
	//	cin >> id;//方便重新输入
	//	bool flag = checkrepeat(id, type);//去重
	//		if (flag == true)
	//		{
	//			cout << errortip << endl;
	//		}
	//		else
	//		{
	//			break;
	//		}
	//}
	//打开文件
	ofstream ofs; 
	ofs.open(filename, ios::app);
	string name;
	string pas;
	cout << "请输入用户名" << endl;
	cin >> name;
	cout << "请输入密码" << endl;
123	cin >> pas;
	//向磁盘输入
	ofs << id << " " << name << " " << pas << " ";
	//关闭磁盘
	ofs.close();
	//initalvector();//调用初始化接口重新地获取容器文件
	cout << "添加完成" << endl;
	system("pause");
	system("cls");
}
//查看账号

void printtea(teacher &tea)//教师
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
	cout << "请选择要查看的类型" << endl;
	cout << "1.老师" << endl;
	cout << "2.学生" << endl;
	cin >> select;
	if (select == 1)
	{
		cout << "老师信息如下" << endl;
		for_each(teacher_vec.begin(), teacher_vec.end(), printtea);//最后一个参数为仿函数或者普通函数
	}
	if (select == 2)
	{
		cout << "学生信息如下" << endl;
		for_each(student_vec.begin(), student_vec.end(), printstu);
	}
	system("pause");
	system("cls");

}
//查看机房信息
void manager::showcomputer()//改
{
	for (auto it= com_vec.begin(); it != com_vec.end(); it++)
	{
		cout << "机房信息如下" << endl;
		cout << "机房号  " << (*it).c_id << " " << "机房容量为 " << (*it).c_size << endl;
	}
}
//清空预约记录
void manager::clearfile()
{
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);//以清空文件的方式打开文件
	ofs.close();
	cout << "清空成功" << endl;

	system("pause");
	system("cls");
}
//初始化


manager::~manager()
{
	
}