#pragma once
#include<iostream>
using namespace std;
#include<string>
class Worker
{
public:

	virtual void GeRenxinxi() = 0;//显示个人信息
	virtual string Gangwei() = 0;//岗位信息


	int m_num;
	string  m_name;
	int m_bumen;
};
