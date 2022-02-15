#include"workerManager.h"


	WorkerManager::WorkerManager()
	{
		
		ifstream ifs;
		ifs.open(FILENAME,ios::in);//读文件
        //1.文件不存在
		if (!ifs.is_open())
		{
			cout << "文件不存在" << endl;
			this->m_Wnum = 0;//初始化人数
			this->m_WArry = NULL;//初始化员工数组指针
			this->WenKong = true;//初始化文件为空
			ifs.close();
			return;
		}

		//2.文件存在 但为空
		char ch;
		ifs >> ch;
		if (ifs.eof())
		{

			cout << "文件存在但为空" << endl;
			//初始化员工数组为空
			this->m_WArry = NULL;
			//初始化员工人数为空
			this->m_Wnum = 0;
			//初始化文件为空
			this->WenKong = true;
			ifs.close();
			return;
		}
		//3.文件不为空 
		this->m_Wnum= this->GetWenNum();
		cout << "文件内职工数量为" <<this->m_Wnum<< endl;
		
		//开辟空间保存数组
		this->m_WArry = new Worker * [this->WenNum];
		//保存数据
		DuWen();

		for (int i = 0; i < this->m_Wnum; i++)
		{
			cout<<"职工编号" << this->m_WArry[i]->m_num 
				<<"职工姓名" << this->m_WArry[i]->m_name 
				<<"部门" << this->m_WArry[i]->m_bumen << endl;
		}
	}

	WorkerManager::~WorkerManager()
	{
		if (this->m_WArry != NULL)
		{
			for (int i = 0; i < this->m_Wnum; i++)
			{
				if (this->m_WArry[i] != NULL)
				{
					delete this->m_WArry[i];
				}
			}
			delete [] *this->m_WArry;
			this->m_WArry = NULL;
		}
	}

	void WorkerManager::Show_Menu()
	{
		cout << "*********************************************" << endl;
		cout << "***************欢迎使用职工管理系统**********" << endl;
		cout << "***************0.退出管理程序****************" << endl;
		cout << "***************1.增加职工信息****************" << endl;
		cout << "***************2.显示职工信息****************" << endl;
		cout << "***************3.删除离职职工****************" << endl;
		cout << "***************4.修改职工信息****************" << endl;
		cout << "***************5.查找职工信息****************" << endl;
		cout << "***************6.按照编号排序****************" << endl;
		cout << "***************7.清空所有文档****************" << endl;
		cout << "*********************************************" << endl;
		cout << endl;
	}
	void WorkerManager::Exit()
	{
		cout << "您即将退出该系统" << endl;
		system("pause");
		exit(0);
	}
	void WorkerManager::AddWorker()
	{
		cout << "请输入要增加员工数量" << endl;

		int adnum=0;
		cin >> adnum;

		if (adnum>0)
		{
			//计算新空间大小
			int newSize = this->m_Wnum + adnum;
			//开辟新的空间
			Worker ** newSpace = new Worker*[newSize];
			//将原空间内容放到新空间下
			if (this->m_WArry != NULL)
			{
				for (int i = 0; i < this->m_Wnum; i++)
				{
					newSpace[i] = this->m_WArry[i];
				}
			}
				//增加新员工
			for (int i = 0; i < adnum; i++)
			{
				int num;
				string name;
				int gang;
				cout << "请输入第" << i + 1 << "个职工编号" << endl;
				cin >> num;
				cout << "请输入第" << i + 1 << "个职工姓名" << endl;
				cin >> name;
				cout << "请输入第" << i + 1 << "个职工职位" << endl;
				cout << "1.员工" << endl;
				cout << "2.经理" << endl;
				cout << "3.老板" << endl;
				cin >> gang;

				Worker* worker = NULL;
				switch (gang)
				{
				case 1:
					worker = new YuanGong(num, name, 1);
					break;
				case 2:
					worker = new JingLi(num, name, 2);
					break;
				case 3:
					worker = new Boss(num, name, 3);
					break;
				default:
					break;
				}

				newSpace[this->m_Wnum + i] =  worker;



			}
				//释放原有空间
				delete []this->m_WArry;

				//更改新空间
				this->m_WArry = newSpace;

				//更新员工数量
				this->m_Wnum = newSize;

				//更新文件为非空
				this->WenKong = false;

				cout << "添加成功" << endl;
				this->Save();
        }
		else
		{
			cout << "您输入数量有误，请重新输入" << endl;
		}

		system("pause");
		system("cls");
	}

	void WorkerManager::Save()//保存员工信息
	{
		ofstream ofs;
		ofs.open(FILENAME,ios::out);

		for (int i = 0; i < this->m_Wnum; i++)
		{
			ofs << this->m_WArry[i]->m_num << " "
				<< this->m_WArry[i]->m_name << " "
				<< this->m_WArry[i]->m_bumen << endl;
		}
		ofs.close();
	}
	int WorkerManager::GetWenNum()//获取文件中人数
	{
		int num ;
		string name;
		int bumen;

		ifstream ifs;
		ifs.open(FILENAME, ios::in);

		int sum=0;
		while (ifs >> num && ifs >> name && ifs >> bumen)
		{
			sum++;
		}
		ifs.close();
		return sum;
	}
	void WorkerManager::DuWen()//获取文件中信息
	{
		ifstream ifs;
		ifs.open(FILENAME, ios::in);//读文件

		//读取文件中信息
		int num;
		string name;
		int bumen;


		int i = 0;
		while (ifs >> num && ifs >> name && ifs >> bumen)
		{
			Worker* worker=NULL;
			if (bumen == 1)
			{
				worker = new YuanGong(num, name, bumen);
			}
			else if (bumen == 2)
			{
				
				worker = new JingLi(num, name, bumen);
				
			}
			else
			{
				worker = new Boss(num, name, bumen);
			}
          this->m_WArry[i] = worker;
		  i++;
		}
	}
	void WorkerManager:: ShowXin()//展示文件信息
	{
		if (this->WenKong)

		{
			cout << "文件为空或者不存在" << endl;
		}
		else
		{
			for (int i = 0; i < this->GetWenNum(); i++)
			{
				this->m_WArry[i]->GeRenxinxi();
			}
		}
		system("pause");
		system("cls");
	}
	int WorkerManager::Is_Cunzai(int id)//是否存在
	{
		int Is_Cunzai = -1;
		for (int i = 0; i < this->m_Wnum; i++)
		{
			if (this->m_WArry[i]->m_num == id)
			{
				Is_Cunzai = i;
				break;
			}

		}
		return Is_Cunzai;
	}
	void WorkerManager::dele()//删除员工
	{
		
		if (this->WenKong)
		{
			cout << "文件不存在" << endl;
		}
		else
		{
			this->m_Wnum = this->GetWenNum();
			cout << "请输入您要删除的职工编号" << endl;
			int shan=0;
			cin >> shan;
			int zhao = this->Is_Cunzai(shan);
			if (zhao!= -1)
			{
			  for (int i = zhao; i < this->m_Wnum-1; i++)
			  {
                    this->m_WArry[i] = this->m_WArry[i + 1];
				  
			  }	
				this->m_Wnum--;
				this->Save(); 
				cout << "删除成功" << endl;
			}
			else
			{
				cout << "不存在此人" << endl;
			}
		}
		system("pause");
		system("cls");
	}
	void WorkerManager::XiuGai()//修改员工信息
	{
		if (this->WenKong)
		{
			cout << "文件不存在或者为空，无法查找" << endl;
		}
		else
		{
			cout << "请输入要修改员工编号" << endl;
			int find;
			cin >> find;
			int zhao;
			zhao = this->Is_Cunzai(find);
			if (zhao != -1)
			{
				cout << "找到要修改职工" << endl;
				delete this->m_WArry[zhao];
				cout << "请输入修改职工编号" << endl;
				int NewNum;
				cin >> NewNum;
				cout << "请输入修改职工姓名" << endl;
				string NewName;
				cin >> NewName;
				cout << "请输入修改职工职位" << endl;
				cout << "1.员工" << endl;
				cout << "2.经理" << endl;
				cout << "3.老板" << endl;
				int choose;
				cin >> choose;
				Worker* worker = NULL;
				switch (choose)
				{
				case 1:
					worker =new YuanGong(NewNum, NewName, 1);
					break;
				case 2:
					worker = new JingLi(NewNum, NewName, 1);
					break;
				case 3:
					worker = new Boss(NewNum, NewName, 1);
					break;
				default:
					break;
				}
				this->m_WArry[zhao] = worker;
				cout << "修改成功" <<this->m_WArry[zhao]->m_num<< endl;
				this->Save();
			}
			else
			{
				cout << "查无此人" << endl;
			}
		}
		system("pause");
		system("cls");
	}
	void WorkerManager::Find()//查找员工
	{
		if (this->WenKong)
		{
			cout << "系统中无员工" << endl;
		}
		else
		{
			cout << "请输入查找员工方式" << endl;
			cout << "1.按编号查找员工" << endl;
			cout << "2.按姓名查找员工" << endl;
			int chose;
			cin >> chose;
			int flag = 0;
			if (chose == 1)
			{
				cout << "请输入要查找的职工编号" << endl;
				int want;
				cin >> want;
				int get = this->Is_Cunzai(want);
				if (get != -1)
				{
					int flag = 1;
					cout << "您查找的员工信息如下：" << endl;
					this->m_WArry[get]->GeRenxinxi();
				}
			}
			if (chose == 2)
			{
				cout << "请输入您要查找的员工姓名" << endl;
				string want;
				cin >> want;
				for (int i = 0; i < this->m_Wnum; i++)
				{
					if (this->m_WArry[i]->m_name == want)
					{
						flag = 1;
						cout << "您查找到的员工信息如下：" << endl;
						this->m_WArry[i]->GeRenxinxi();
					}
				}
			}
			if (flag == 0)
			{
				cout << "文件中无此员工" << endl;
			}
		}
		system("pause");
		system("cls");
	}
	void WorkerManager::PaiXu()//给员工排序
	{
		if (this->WenKong)
		{
			cout << "无文件" << endl;
			system("pause");
			system("cls");
		}
		else
		{
			cout << "您希望升序排列还是降序排列" << endl;
			cout << "1--升序" << endl;
			cout << "2--降序" << endl;
			int chose;
			cin >> chose;
			for (int i = 0; i < this->m_Wnum; i++)
			{
				int biao=i;
				for (int j = 0; j < this->m_Wnum; j++)
				{
					if (chose == 1)//升序
					{
						if (this->m_WArry[i]->m_num < this->m_WArry[j]->m_num)
						{
							biao = j;
						}
					}
					if (chose == 2)//降序
					{
						if (this->m_WArry[i]->m_num > this->m_WArry[j]->m_num)
						{
							biao = j;
						}
					}
				}
				if (i != biao)
				{
					Worker* temp = this->m_WArry[i];
					this->m_WArry[i] = this->m_WArry[biao];
					this->m_WArry[biao] = temp;
				}
			}
			cout << "排序成功，排序结果为：" << endl;
			this->Save();
			this->ShowXin();
		}
	}
	void WorkerManager::clean()//清空文件
	{
		cout << "确定要删除所有文件？" << endl;
		cout << "1.确认" << endl;
		cout << "2.取消" << endl;
		int chose;
		cin >> chose;
		if (chose == 1)
		{
			ifstream ifs;
			ifs.open(FILENAME, ios::trunc);
			if (this->m_WArry != NULL)
			{
				for (int i = 0; i < this->m_Wnum; i++)
				{
					if (this->m_WArry[i] != NULL)
					{
						delete this->m_WArry[i];
					}
				}
				this->m_Wnum = 0;
				delete[] &(this->m_WArry);
				this->m_WArry = NULL;
				this->WenKong = true;
			}
			cout << "清空成功！" << endl;
		}
		system("pause");
		system("cls");
	}