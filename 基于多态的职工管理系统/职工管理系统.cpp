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
	cout << "请输入您的选择" << endl;
	cin >> xuan;
	switch (xuan)
	{
	case 0://退出系统
		wm.Exit();   
		break;
	case 1://添加职工
		wm.AddWorker();
		break;
	case 2://显示职工
		wm.ShowXin();
		break;
	case 3://删除职工
		wm.dele();
		break;
	case 4://修改职工
		wm.XiuGai();
		break;
	case 5://查找职工
		wm.Find();
		break;
	case 6://排序职工
		wm.PaiXu();
		break;
	case 7://清空职工
		wm.clean();
		break;
	default:
		system("cls");
		break;
	}
	}
	//测试代码
	/*Worker* worker = NULL;
	worker = new YuanGong(1, "赵四",1);
	worker->GeRenxinxi();
	delete worker;
	worker = new JingLi(2, "王五", 2);
	worker->GeRenxinxi();
	delete worker;
	worker = new Boss(3, "李三", 3);
	worker->GeRenxinxi();
	delete worker;*/
	system("pause");
	return 0;
}