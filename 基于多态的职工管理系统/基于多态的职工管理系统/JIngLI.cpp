#include"JingLi.h"

	JingLi::JingLi(int num, string name, int bumen)
	{
		this->m_num = num;
		this->m_name = name;
		this->m_bumen = bumen;
	}
	void JingLi ::GeRenxinxi()//��ʾ������Ϣ:
	{
		cout << "Ա�����Ϊ��" << this->m_num
			<< "\tԱ������Ϊ��" << this->m_name
			<< "\tԱ����λΪ��" << this->Gangwei()
			<< "\t��λְ��Ϊ������ϰ彻�������񣬲��·������Ա��" << endl;
	}

	string JingLi::Gangwei()//��λ��Ϣ
	{
		return string("����");
	}
