#include"student.h"
#include"manager.h"
student::student()
{

}
//有参构造
student::student(int id, string name, string pas)
{
	m_id = id;
	m_name = name;
	m_pas = pas;
}
//菜单界面
 void student::showmenu()
{
	 cout << "欢迎学生代表" << " :"<<m_name << "登录" << endl;
	 cout << "请选择功能" << endl;
	 cout << "-----------------------" << endl;
	 cout << "|      1.申请预约      |" << endl;
	 cout << "|                      |" << endl;
	 cout << "|      2.查看我的预约  |" << endl;
	 cout << "|                      |" << endl;
	 cout << "|      3.查看所有预约  |" << endl;//显示机房编号和最大容量
	 cout << "|                      |" << endl;
	 cout << "|      4.取消预约      |" << endl;//清空预约文件
	 cout << "|                      |" << endl;
	 cout << "|      5.注销登录      |" << endl;//退出管理员登录
	 cout << "-----------------------" << endl;
}
//申请预约
void student::applyorder()
{
	cout << "请选择预约时间" << endl;
	cout << "1.周一" << endl;
	cout << "2.周二" << endl;
	cout << "3.周三" << endl;
	cout << "4.周四" << endl;
	cout << "5.周五" << endl;
	int data = 0;
	int interdata = 0;//时间段
	int room = 0;//教室
	int status=1;//审核状态  1审核中

	while (1)//输入对了才可以退出
	{
		cin >> data;
		if (data < 0 || data>5)
		{
			cout << "请重新输入" << endl;
		}
		else
		{
			break;
		}
	}
	cout << "请选择预约时间段" << endl;
	cout << "1.上午" << endl;
	cout << "2.下午" << endl;
	while (1)
	{
		cin >> interdata;
		if (interdata < 1 || interdata>2)
		{
			cout << "请重新输入" << endl;
		}
		else
		{
			break;
		}
	}
	cout << "请选择机房号" << endl;
	//在堆区创建一个manager对象访问成员函数
	shared_ptr<manager>man = make_shared<manager>();
	man->showcomputer();
	while (1)
	{
		cin >> room;
		if (room < 1 || room>3)
		{
			cout << "输入错误,重新输入" << endl;
		}
		else
		{
			break;
		}
	}
	cout << "申请成功，请等待审批" << endl;
	//写入文件
	ofstream ofs;
	ofs.open(ORDER_FILE,ios::app);
	if (!ofs.is_open())
	{
		cout << "预约文件打开失败" << endl;
	}
	ofs << "申请日期:" << data <<" " << "时间:" << interdata << " " << "机房号:" << room << " " << "状态:" << status << " " << endl;
	ofs.close();
	system("pause");
	system("cls");
}
//查看自身预约(加上学号姓名后实现)
void student::showorder()
{
	orderfile of;
	if (of.m_size == 0)
	{
		cout << "无预约记录" << endl;
		//******
	}
}
//查看所有预约
void student::showallorder()
{
	orderfile ord;//创建对象同时初始化容器 打印即可
	if (ord.m_size == 0)
	{
		cout << "没有预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 1; i <= ord.m_size;i++)
	{
		cout << i << ", ";
		cout << "预约时间：周" << ord.order_data[i]["申请日期"];
		cout << " 时间:" << ord.order_data[i]["时间"];
		cout << " 机房号:" << ord.order_data[i]["机房号"];
		//状态需要拼接  //1审核中  2已预约 -1预约失败 0取消预约
		string status = "状态：";
		if (ord.order_data[i]["状态"] == "1")//存入的时候用的是string所以要大""
		{
			status += "审核中";
		}
		else if (ord.order_data[i]["状态"] == "2")
		{
			status += "已预约";
		}
		else if (ord.order_data[i]["状态"] == "0")
		{
			status += "已取消";
		}
		else if (ord.order_data[i]["状态"] == "-1")
		{
			status += "预约失败,审核未通过";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
	return;
	
}
//取消预约
void student::cancelorder()
{

}
student::~student()
{

}