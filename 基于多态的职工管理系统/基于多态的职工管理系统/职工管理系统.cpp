#include"workerManager.h"
#include<iostream>
using namespace std;
//#include"YuanGong.h"
//#include"JingLi.h"
//#include"Boss.h"
int main()
{
	WorkerManager wm;
	while (true)
	{
    wm.Show_Menu();
	int xuan;
	cout << "����������ѡ��" << endl;
	cin >> xuan;
	switch (xuan)
	{
	case 0://�˳�ϵͳ
		wm.Exit();   
		break;
	case 1://���ְ��
		wm.AddWorker();
		break;
	case 2://��ʾְ��
		wm.ShowXin();
		break;
	case 3://ɾ��ְ��
		wm.dele();
		break;
	case 4://�޸�ְ��
		wm.XiuGai();
		break;
	case 5://����ְ��
		wm.Find();
		break;
	case 6://����ְ��
		wm.PaiXu();
		break;
	case 7://���ְ��
		wm.clean();
		break;
	default:
		system("cls");
		break;
	}
	}
	//���Դ���
	/*Worker* worker = NULL;
	worker = new YuanGong(1, "����",1);
	worker->GeRenxinxi();
	delete worker;
	worker = new JingLi(2, "����", 2);
	worker->GeRenxinxi();
	delete worker;
	worker = new Boss(3, "����", 3);
	worker->GeRenxinxi();
	delete worker;*/
	system("pause");
	return 0;
}