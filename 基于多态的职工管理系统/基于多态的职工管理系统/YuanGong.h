#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
#include<string>

class YuanGong:public Worker
{
public:
	YuanGong(int num,string name,int bumen);
	 void GeRenxinxi() ;
	 string Gangwei() ;



};
