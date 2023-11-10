#include"orderfile.h"

//���캯��
orderfile::orderfile()
{
	m_size = 0;
	string data;//����
	string interval;//ʱ���
	string room;//������
	string status;//״̬
	//��ȡ�����ļ���Ϣ
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	//��ȡ��Ϣ
	while (ifs >> data && ifs >> interval && ifs >> room && ifs >> status)//��ȡδ�ָ�ļ�ֵ�� ����ֵ��value�ã�����  ���Ի���Ҫ�Զ�ȡ�����ݽ��в��
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
		//��ȡ�ַ���
		//��ȡdata
		int pos = data.find(":");//���Ҹ������ţ�����λ�� δ�ҵ�����-1
		if (pos != -1)
		{
			key = data.substr(0, pos);//��0��ʼ��ȡ����ȡpos���ַ� ��ȡ��֮ǰ��
			value = data.substr(pos + 1, data.size() - pos - 1);//��ȡ��֮����ַ�
			m.insert(make_pair(key, value));
			/*cout << "key="<<key << endl;
			cout << "value="<<value << endl;*/
		}
		//��ȡinterval
		int pos1 = interval.find(":");//���Ҹ������ţ�����λ�� δ�ҵ�����-1
		if (pos1 != -1)
		{
			key = interval.substr(0, pos1);//��0��ʼ��ȡ����ȡpos���ַ� ��ȡ��֮ǰ��
			value = interval.substr(pos1 + 1, interval.size() - pos1 - 1);//��ȡ��֮����ַ�
			m.insert(make_pair(key, value));
		}
		//��ȡroom
		int pos2 = room.find(":");//���Ҹ������ţ�����λ�� δ�ҵ�����-1
		if (pos2 != -1)
		{
			key = room.substr(0, pos2);//��0��ʼ��ȡ����ȡpos���ַ� ��ȡ��֮ǰ��
			value = room.substr(pos2 + 1, room.size() - pos2 - 1);//��ȡ��֮����ַ�
			m.insert(make_pair(key, value));

		}
		//��ȡ״̬
		int pos3 = status.find(":");//���Ҹ������ţ�����λ�� δ�ҵ�����-1
		if (pos3 != -1)
		{
			key = status.substr(0, pos3);//��0��ʼ��ȡ����ȡpos���ַ� ��ȡ��֮ǰ��
			value = status.substr(pos3 + 1, status.size() - pos3 - 1);//��ȡ��֮����ַ�
			m.insert(make_pair(key, value));

		}
		//��С���������������
		order_data.insert(make_pair(++m_size, m));//��1��ʼ��������++����0��ʼ
		
		
	}
		ifs.close();
		////�����������
		//for (auto it = order_data.begin(); it != order_data.end(); it++)
		//{
		//	cout << "����Ϊ " << it->first << " value= " << endl;
		//	for (auto mit = (*it).second.begin(); mit != (*it).second.end(); mit++)
		//	{
		//		cout << "key=" << mit->first << " value=" << mit->second << " ";
		//	}
		//	cout << endl;
		//}

	
}
//����ԤԼ��¼
void orderfile::updateorder()//��պ���д��
{
	if (m_size == 0)
	{
		return;
	}
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out||ios::trunc);
	for (int i = 1; i <= m_size; i++)
	{
		ofs << "��������" << order_data[i]["��������"] << " ";
		ofs << "ʱ��:" << order_data[i]["ʱ��:"] << " ";
		ofs << "������:" << order_data[i]["������:"] << " ";
		ofs << "״̬:" << order_data[i]["״̬:"] << endl;
	}
	ofs.close();

}