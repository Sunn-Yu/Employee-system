#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

class JingLi:public Worker
{
public:
	JingLi(int num, string name, int bumen);
	 void GeRenxinxi();//显示个人信息
	 string Gangwei() ;//岗位信息

};