#include"Boss.h"

	Boss::Boss(int num, string name, int bumen)
	{
		this->m_num = num;
		this->m_name = name;
		this->m_bumen = bumen;
	}
	void Boss:: GeRenxinxi()//显示个人信息
	{
		cout << "员工编号为：" << this->m_num
			<< "\t员工姓名为：" << this->m_name
			<< "\t员工岗位为：" << this->Gangwei()
			<< "\t岗位职责为：给下属布置任务" << endl;
	}

	string Boss::Gangwei()//岗位信息
	{
		return string("老板");
	}
