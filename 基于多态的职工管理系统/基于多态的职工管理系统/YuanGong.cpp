#include"YuanGong.h"


YuanGong::YuanGong(int num, string name, int bumen)//���캯��
{
	this->m_num = num;
	this->m_name = name;
	this->m_bumen = bumen;
}
void YuanGong::GeRenxinxi()//��ʾ������Ϣ
{
	cout << "Ա�����Ϊ��" << this->m_num
		<< "\tԱ������Ϊ��" << this->m_name
		<< "\tԱ����λΪ��" << this->Gangwei()
		<< "\t��λְ��Ϊ����ɾ�����������" << endl;
}
string YuanGong::Gangwei()//��ȡ��λ����
{
	return string("Ա��");
}