#include"workerManager.h"


	WorkerManager::WorkerManager()
	{
		
		ifstream ifs;
		ifs.open(FILENAME,ios::in);//���ļ�
        //1.�ļ�������
		if (!ifs.is_open())
		{
			cout << "�ļ�������" << endl;
			this->m_Wnum = 0;//��ʼ������
			this->m_WArry = NULL;//��ʼ��Ա������ָ��
			this->WenKong = true;//��ʼ���ļ�Ϊ��
			ifs.close();
			return;
		}

		//2.�ļ����� ��Ϊ��
		char ch;
		ifs >> ch;
		if (ifs.eof())
		{

			cout << "�ļ����ڵ�Ϊ��" << endl;
			//��ʼ��Ա������Ϊ��
			this->m_WArry = NULL;
			//��ʼ��Ա������Ϊ��
			this->m_Wnum = 0;
			//��ʼ���ļ�Ϊ��
			this->WenKong = true;
			ifs.close();
			return;
		}
		//3.�ļ���Ϊ�� 
		this->m_Wnum= this->GetWenNum();
		cout << "�ļ���ְ������Ϊ" <<this->m_Wnum<< endl;
		
		//���ٿռ䱣������
		this->m_WArry = new Worker * [this->WenNum];
		//��������
		DuWen();

		for (int i = 0; i < this->m_Wnum; i++)
		{
			cout<<"ְ�����" << this->m_WArry[i]->m_num 
				<<"ְ������" << this->m_WArry[i]->m_name 
				<<"����" << this->m_WArry[i]->m_bumen << endl;
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
		cout << "***************��ӭʹ��ְ������ϵͳ**********" << endl;
		cout << "***************0.�˳��������****************" << endl;
		cout << "***************1.����ְ����Ϣ****************" << endl;
		cout << "***************2.��ʾְ����Ϣ****************" << endl;
		cout << "***************3.ɾ����ְְ��****************" << endl;
		cout << "***************4.�޸�ְ����Ϣ****************" << endl;
		cout << "***************5.����ְ����Ϣ****************" << endl;
		cout << "***************6.���ձ������****************" << endl;
		cout << "***************7.��������ĵ�****************" << endl;
		cout << "*********************************************" << endl;
		cout << endl;
	}
	void WorkerManager::Exit()
	{
		cout << "�������˳���ϵͳ" << endl;
		system("pause");
		exit(0);
	}
	void WorkerManager::AddWorker()
	{
		cout << "������Ҫ����Ա������" << endl;

		int adnum=0;
		cin >> adnum;

		if (adnum>0)
		{
			//�����¿ռ��С
			int newSize = this->m_Wnum + adnum;
			//�����µĿռ�
			Worker ** newSpace = new Worker*[newSize];
			//��ԭ�ռ����ݷŵ��¿ռ���
			if (this->m_WArry != NULL)
			{
				for (int i = 0; i < this->m_Wnum; i++)
				{
					newSpace[i] = this->m_WArry[i];
				}
			}
				//������Ա��
			for (int i = 0; i < adnum; i++)
			{
				int num;
				string name;
				int gang;
				cout << "�������" << i + 1 << "��ְ�����" << endl;
				cin >> num;
				cout << "�������" << i + 1 << "��ְ������" << endl;
				cin >> name;
				cout << "�������" << i + 1 << "��ְ��ְλ" << endl;
				cout << "1.Ա��" << endl;
				cout << "2.����" << endl;
				cout << "3.�ϰ�" << endl;
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
				//�ͷ�ԭ�пռ�
				delete []this->m_WArry;

				//�����¿ռ�
				this->m_WArry = newSpace;

				//����Ա������
				this->m_Wnum = newSize;

				//�����ļ�Ϊ�ǿ�
				this->WenKong = false;

				cout << "��ӳɹ�" << endl;
				this->Save();
        }
		else
		{
			cout << "������������������������" << endl;
		}

		system("pause");
		system("cls");
	}

	void WorkerManager::Save()//����Ա����Ϣ
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
	int WorkerManager::GetWenNum()//��ȡ�ļ�������
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
	void WorkerManager::DuWen()//��ȡ�ļ�����Ϣ
	{
		ifstream ifs;
		ifs.open(FILENAME, ios::in);//���ļ�

		//��ȡ�ļ�����Ϣ
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
	void WorkerManager:: ShowXin()//չʾ�ļ���Ϣ
	{
		if (this->WenKong)

		{
			cout << "�ļ�Ϊ�ջ��߲�����" << endl;
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
	int WorkerManager::Is_Cunzai(int id)//�Ƿ����
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
	void WorkerManager::dele()//ɾ��Ա��
	{
		
		if (this->WenKong)
		{
			cout << "�ļ�������" << endl;
		}
		else
		{
			this->m_Wnum = this->GetWenNum();
			cout << "��������Ҫɾ����ְ�����" << endl;
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
				cout << "ɾ���ɹ�" << endl;
			}
			else
			{
				cout << "�����ڴ���" << endl;
			}
		}
		system("pause");
		system("cls");
	}
	void WorkerManager::XiuGai()//�޸�Ա����Ϣ
	{
		if (this->WenKong)
		{
			cout << "�ļ������ڻ���Ϊ�գ��޷�����" << endl;
		}
		else
		{
			cout << "������Ҫ�޸�Ա�����" << endl;
			int find;
			cin >> find;
			int zhao;
			zhao = this->Is_Cunzai(find);
			if (zhao != -1)
			{
				cout << "�ҵ�Ҫ�޸�ְ��" << endl;
				delete this->m_WArry[zhao];
				cout << "�������޸�ְ�����" << endl;
				int NewNum;
				cin >> NewNum;
				cout << "�������޸�ְ������" << endl;
				string NewName;
				cin >> NewName;
				cout << "�������޸�ְ��ְλ" << endl;
				cout << "1.Ա��" << endl;
				cout << "2.����" << endl;
				cout << "3.�ϰ�" << endl;
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
				cout << "�޸ĳɹ�" <<this->m_WArry[zhao]->m_num<< endl;
				this->Save();
			}
			else
			{
				cout << "���޴���" << endl;
			}
		}
		system("pause");
		system("cls");
	}
	void WorkerManager::Find()//����Ա��
	{
		if (this->WenKong)
		{
			cout << "ϵͳ����Ա��" << endl;
		}
		else
		{
			cout << "���������Ա����ʽ" << endl;
			cout << "1.����Ų���Ա��" << endl;
			cout << "2.����������Ա��" << endl;
			int chose;
			cin >> chose;
			int flag = 0;
			if (chose == 1)
			{
				cout << "������Ҫ���ҵ�ְ�����" << endl;
				int want;
				cin >> want;
				int get = this->Is_Cunzai(want);
				if (get != -1)
				{
					int flag = 1;
					cout << "�����ҵ�Ա����Ϣ���£�" << endl;
					this->m_WArry[get]->GeRenxinxi();
				}
			}
			if (chose == 2)
			{
				cout << "��������Ҫ���ҵ�Ա������" << endl;
				string want;
				cin >> want;
				for (int i = 0; i < this->m_Wnum; i++)
				{
					if (this->m_WArry[i]->m_name == want)
					{
						flag = 1;
						cout << "�����ҵ���Ա����Ϣ���£�" << endl;
						this->m_WArry[i]->GeRenxinxi();
					}
				}
			}
			if (flag == 0)
			{
				cout << "�ļ����޴�Ա��" << endl;
			}
		}
		system("pause");
		system("cls");
	}
	void WorkerManager::PaiXu()//��Ա������
	{
		if (this->WenKong)
		{
			cout << "���ļ�" << endl;
			system("pause");
			system("cls");
		}
		else
		{
			cout << "��ϣ���������л��ǽ�������" << endl;
			cout << "1--����" << endl;
			cout << "2--����" << endl;
			int chose;
			cin >> chose;
			for (int i = 0; i < this->m_Wnum; i++)
			{
				int biao=i;
				for (int j = 0; j < this->m_Wnum; j++)
				{
					if (chose == 1)//����
					{
						if (this->m_WArry[i]->m_num < this->m_WArry[j]->m_num)
						{
							biao = j;
						}
					}
					if (chose == 2)//����
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
			cout << "����ɹ���������Ϊ��" << endl;
			this->Save();
			this->ShowXin();
		}
	}
	void WorkerManager::clean()//����ļ�
	{
		cout << "ȷ��Ҫɾ�������ļ���" << endl;
		cout << "1.ȷ��" << endl;
		cout << "2.ȡ��" << endl;
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
			cout << "��ճɹ���" << endl;
		}
		system("pause");
		system("cls");
	}