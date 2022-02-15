#include"YuanGong.h"


YuanGong::YuanGong(int num, string name, int bumen)//构造函数
{
	this->m_num = num;
	this->m_name = name;
	this->m_bumen = bumen;
}
void YuanGong::GeRenxinxi()//显示个人信息
{
	cout << "员工编号为：" << this->m_num
		<< "\t员工姓名为：" << this->m_name
		<< "\t员工岗位为：" << this->Gangwei()
		<< "\t岗位职责为：完成经理交给的任务" << endl;
}
string YuanGong::Gangwei()//获取岗位名称
{
	return string("员工");
}