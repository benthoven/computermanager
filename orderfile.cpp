#include"orderfile.h"

//构造函数
orderfile::orderfile()
{
	m_size = 0;
	string data;//日期
	string interval;//时间段
	string room;//机房号
	string status;//状态
	//获取所有文件信息
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	//读取信息
	while (ifs >> data && ifs >> interval && ifs >> room && ifs >> status)//读取未分割的键值对 将键值和value用：隔开  所以还需要对读取的数据进行拆分
	{
			/*cout << data << " " << endl;
			cout << interval << " " << endl;
			cout << room << " " << endl;
			cout << status << " " << endl;
			cout << endl;*/
	//		//data:111
		string key;
		string value;
		map<string, string>m;
		//截取字符串
		//截取data
		int pos = data.find(":");//查找给定符号，返回位置 未找到返回-1
		if (pos != -1)
		{
			key = data.substr(0, pos);//从0开始截取，截取pos个字符 截取：之前的
			value = data.substr(pos + 1, data.size() - pos - 1);//截取：之后的字符
			m.insert(make_pair(key, value));
			/*cout << "key="<<key << endl;
			cout << "value="<<value << endl;*/
		}
		//截取interval
		int pos1 = interval.find(":");//查找给定符号，返回位置 未找到返回-1
		if (pos1 != -1)
		{
			key = interval.substr(0, pos1);//从0开始截取，截取pos个字符 截取：之前的
			value = interval.substr(pos1 + 1, interval.size() - pos1 - 1);//截取：之后的字符
			m.insert(make_pair(key, value));
		}
		//截取room
		int pos2 = room.find(":");//查找给定符号，返回位置 未找到返回-1
		if (pos2 != -1)
		{
			key = room.substr(0, pos2);//从0开始截取，截取pos个字符 截取：之前的
			value = room.substr(pos2 + 1, room.size() - pos2 - 1);//截取：之后的字符
			m.insert(make_pair(key, value));

		}
		//截取状态
		int pos3 = status.find(":");//查找给定符号，返回位置 未找到返回-1
		if (pos3 != -1)
		{
			key = status.substr(0, pos3);//从0开始截取，截取pos个字符 截取：之前的
			value = status.substr(pos3 + 1, status.size() - pos3 - 1);//截取：之后的字符
			m.insert(make_pair(key, value));

		}
		//将小容器放入大容器中
		order_data.insert(make_pair(++m_size, m));//从1开始计数，不++将从0开始
		
		
	}
		ifs.close();
		////测试最大容器
		//for (auto it = order_data.begin(); it != order_data.end(); it++)
		//{
		//	cout << "条数为 " << it->first << " value= " << endl;
		//	for (auto mit = (*it).second.begin(); mit != (*it).second.end(); mit++)
		//	{
		//		cout << "key=" << mit->first << " value=" << mit->second << " ";
		//	}
		//	cout << endl;
		//}

	
}
//更新预约记录
void orderfile::updateorder()//清空后再写入
{
	if (m_size == 0)
	{
		return;
	}
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out||ios::trunc);
	for (int i = 1; i <= m_size; i++)
	{
		ofs << "申请日期" << order_data[i]["申请日期"] << " ";
		ofs << "时间:" << order_data[i]["时间:"] << " ";
		ofs << "机房号:" << order_data[i]["机房号:"] << " ";
		ofs << "状态:" << order_data[i]["状态:"] << endl;
	}
	ofs.close();

}