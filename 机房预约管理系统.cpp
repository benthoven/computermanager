#include<iostream>
using namespace std;
#include<fstream>
#include"globalfile.h"
#include"manager.h"
#include"student.h"
#include"teacher.h"
#include<memory>

//管理员功能接口
void managerfunction(shared_ptr<identity>& person)//identity* &person//指针的引用  identity*也是一种变量，指针传递时也是值传递，想要在函数中保留修改后的指针地址就要指针的引用或指针传递，类似于普通变量传递
{
	
	//要调用子类非共同函数必须转回子类
	
	manager* man = (manager*)&person;
	//man->showcomputer();
	int select = 0;
	cout << "请输入你的选择" << endl;
	
	//选择分支
	while (1)
	{
		person->showmenu();
		cin >> select;
		switch (select)
		{
		case 1://添加账号

			man->addperson();
			//man->initalvector();
			system("pause");
			system("cls");

			break;
		case 2://查看账号
			man->showperson();
			system("pause");
			system("cls");
			break;
		case 3://查看机房
			man->showcomputer();
			system("pause");
			system("cls");
			break;
		case 4://删除预约记录
			man->clearfile();
			system("pause");
			system("cls");
			break;
		case 5://注销登录
			//销毁堆区对象
			//delete person;
			//person = NULL;
			cout << "销毁成功" << endl;
			system("pause");
			system("cls");
			return;
			break;
		default://注销
			return;
			break;
		}
	}
		
}
//学生端接口
void studentfunction(shared_ptr<identity>& person)//identity* &person//指针的引用  identity*也是一种变量，指针传递时也是值传递，想要在函数中保留修改后的指针地址就要指针的引用或指针传递，类似于普通变量传递
{

	//要调用子类非共同函数必须转回子类
	
	student*stu = (student*)person.get();//get智能指针转为普通指针
	
	int select = 0;
	cout << "请输入你的选择" << endl;

	//选择分支
	while (1)
	{
		person->showmenu();
		cin >> select;
		switch (select)
		{
		case 1://申请预约

			stu->applyorder();
			system("pause");
 			system("cls");

			break;
		case 2://查看预约
			stu->showorder();
			system("pause");
			system("cls");
			break;
		case 3://查看所有预约
			stu->showallorder();
			system("pause");
			system("cls");
			break;
		case 4://取消预约
			stu->cancelorder();
			system("pause");
			system("cls");
			break;
		case 5://注销登录
			//销毁堆区对象
			//delete person;
			//person = NULL;智能指针会自动销毁
			cout << "销毁成功" << endl;
			system("pause");
			system("cls");
			return;
			break;
		default://注销
			return;
			break;
		}
	}

}
//登录函数
void personlogin(string filename, int type)
{
	//创建父类指针或引用用来指向子类实现多态
	//identity* person = NULL;
//读文件，确认是否存在
	ifstream ifst;
	ifst.open(filename, ios::in);
	if (!ifst.is_open())//判断是否打开  打开返回1或者直接!ifst
	{
		cout << "没有找到文件，打开失败" << endl;
		ifst.close();//直接关闭
		return;
	}
	//准备接收用户信息
	int id = 0;
	string name;
	string pas;
	//判断身份
	if (type == 1)//学生
	{
		cout << "请输入您的学号" << endl;
		cin >> id;
	}
	if (type == 2)//教师
	{
		cout << "请输入你的职工号" << endl;
		cin >> id;
	}
	cout << "请输入用户名" << endl;
	cin >> name;
	cout << "请输入密码" << endl;
	cin >> pas;
	//验证身份
	if (type == 1)
	{//学生身份验证
		int fid;//文件读取的ID
		string fname;//文件读取的姓名
		string fpas;//文件获取的密码
		while (ifst >> fid && ifst >> fname && ifst >> fpas)//逐行逐次读取以下内容，遇到空格就会结束
		{
			
			if (fid == id && fname == name && fpas == pas)
			{
				cout << "登录成功" << endl;
				system("pause");
				system("cls");
				system("pause");
				shared_ptr<identity> person = make_shared<student>(id, name, pas);
				//person = new student(id,name,pas);//指向子类对象,调用子菜单界面，并将输入信息赋给对象
				studentfunction(person);
				return;
			}
			else
			{
				cout << "登录失败" << endl;
				system("pause");
				system("cls");
				return;
			}
		}
	}
	else if (type == 2)
	{//教师身份验证
		int tid;//文件读取的ID
		string tname;//文件读取的姓名
		string tpas;//文件获取的密码
		while (ifst >> tid && ifst >> tname && ifst >>tpas)//逐行逐次读取以下内容，遇到空格就会结束
		{
			/*cout << tid << endl;
			cout << tname << endl;
			cout << tpas << endl;
			cout << endl;*/
			if (tid == id && tname == name && tpas == pas)
			{
				cout << "登录成功" << endl;
				system("pause");
				system("cls");
				system("pause");
				shared_ptr<identity> person = make_shared<manager>(name, pas);//指向子类对象,调用子菜单界面，并将输入信息赋给对象
				return;
			}
			else
			{
				cout << "登录失败" << endl;
				system("pause");
				system("cls");
				return;
			}
		}
	}
	else if (type == 3)
	{//验证管理员身份 只有一个管理员，不用添加管理员功能
		string mname;//文件读取的姓名
		string mpas;//文件获取的密码
		while ( ifst >> mname && ifst >> mpas)//逐行逐次读取以下内容，遇到空格就会结束
		{
			/*cout << mname << endl;
			cout << mpas << endl;
			cout << endl;*/
			if ( mname == name && mpas == pas)
			{
				cout << "登录成功" << endl;
				system("pause");
				system("cls");
				shared_ptr<identity> person = make_shared<manager>(name, pas);//指向子类对象,调用子菜单界面，并将输入信息赋给对象
				//功能接口
				managerfunction(person);
				system("pause");
				return;
			}
			else
			{
				cout << "登录失败" << endl;
				system("pause");
				system("cls");
				return;
			}
		}

	}
	else
	{
		cout << "验证失败" << endl;
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
		cout << "==========欢迎使用机房预约管理系统==========" << endl;
		cout << "请选择您的身份" << endl;
		cout << "-------------------------" << endl;
		cout << "|      1.学生代表       |" << endl;
		cout << "|                       |" << endl;
		cout << "|      2.老师           |" << endl;
		cout << "|                       |" << endl;
		cout << "|      3.管理员         |" << endl;
		cout << "|                       |" << endl;
		cout << "|      0.返回上一级     |" << endl;
		cout << "-------------------------" << endl;
		cout << "请选择" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1://学生身份
			personlogin(STUDENT_FILE, 1);
			break;
		case 2://老师身份
			personlogin(TEACHER_FILE, 2);
			break;
		case 3://管理员身份
			personlogin(ADMIN_FILE, 3);
			break;
		case 0://退出
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "请重新输入" << endl;
			system("pause");
			system("cls");
			break;

		}
	}
	


	system("pause");
	return 0;
}