#include"Boss.h"

	Boss::Boss(int num, string name, int bumen)
	{
		this->m_num = num;
		this->m_name = name;
		this->m_bumen = bumen;
	}
	void Boss:: GeRenxinxi()//��ʾ������Ϣ
	{
		cout << "Ա�����Ϊ��" << this->m_num
			<< "\tԱ������Ϊ��" << this->m_name
			<< "\tԱ����λΪ��" << this->Gangwei()
			<< "\t��λְ��Ϊ����������������" << endl;
	}

	string Boss::Gangwei()//��λ��Ϣ
	{
		return string("�ϰ�");
	}
