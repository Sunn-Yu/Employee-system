#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

class JingLi:public Worker
{
public:
	JingLi(int num, string name, int bumen);
	 void GeRenxinxi();//��ʾ������Ϣ
	 string Gangwei() ;//��λ��Ϣ

};