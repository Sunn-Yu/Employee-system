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
	void Show_Menu();//��ʾ�˵�����
	void Exit();//�˳�ϵͳ
	void AddWorker();//����Ա��
	void Save();//������Ա����Ϣ
	int m_Wnum;//��¼�ļ��е���������
	Worker ** m_WArry;//Ա�������ָ��
	bool WenKong;//��¼�ļ��Ƿ�Ϊ��
	int WenNum;//��¼�ļ�������
	int GetWenNum();//��ȡ�ļ�������
	void DuWen();//��ȡ�ļ�����Ϣ
	void ShowXin();//չʾ�ļ���Ϣ
	int Is_Cunzai(int id);//�Ƿ����
	void dele();//ɾ��Ա��
	void XiuGai();//�޸�Ա����Ϣ
	void Find();//����Ա��
	void PaiXu();//��Ա������
	void clean();//����ļ�
};

