#pragma once
#include<iostream>
using namespace std;
#include<string>
class Worker
{
public:

	virtual void GeRenxinxi() = 0;//��ʾ������Ϣ
	virtual string Gangwei() = 0;//��λ��Ϣ


	int m_num;
	string  m_name;
	int m_bumen;
};
