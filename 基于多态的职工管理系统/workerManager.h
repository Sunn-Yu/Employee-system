#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
#include"YuanGong.h"
#include"JingLi.h"
#include"Boss.h"
#include<fstream>
#define FILENAME "YuanGong.txt"
class WorkerManager
{
public:
	WorkerManager();
	~WorkerManager();
	void Show_Menu();//显示菜单函数
	void Exit();//退出系统
	void AddWorker();//增加员工
	void Save();//；保存员工信息
	int m_Wnum;//记录文件中的人数个数
	Worker ** m_WArry;//员工数组的指针
	bool WenKong;//记录文件是否为空
	int WenNum;//记录文件中人数
	int GetWenNum();//获取文件中人数
	void DuWen();//获取文件中信息
	void ShowXin();//展示文件信息
	int Is_Cunzai(int id);//是否存在
	void dele();//删除员工
	void XiuGai();//修改员工信息
	void Find();//查找员工
	void PaiXu();//给员工排序
	void clean();//清空文件
};

