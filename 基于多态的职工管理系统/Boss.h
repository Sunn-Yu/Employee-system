#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
class Boss:public Worker
{
public:
	Boss(int num, string name, int bumen);
	void GeRenxinxi();//��ʾ������Ϣ
	string Gangwei();//��λ��Ϣ

};
