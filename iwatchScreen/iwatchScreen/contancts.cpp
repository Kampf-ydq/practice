#include"Contanct.h"
#include  <windows.h> 
#include  <iostream> 
#include "mmsystem.h"//��������ͷ�ļ�
#pragma comment(lib,"winmm.lib")//��������ͷ�ļ���

void playSound();

void playSound(int choose)//1��ʾ���绰,2(�ӵ绰),3(�ҵ绰)
{
	if (choose == 1)
	{
		for (int i = 0; i < 5; i++)
		{
			PlaySound(TEXT("E:\\WAV\\Ringout1.wav"), NULL, SND_FILENAME | SND_ASYNC);
			Sleep(2000);
		}
	}
	if (choose == 2)
		PlaySound(TEXT("E:\\WAV\\Ringout2.wav"), NULL, SND_FILENAME | SND_ASYNC);
	if (choose == 3)
			PlaySound(TEXT("E:\\WAV\\Ringout3.wav"), NULL, SND_FILENAME | SND_ASYNC);
}




int Contancts::back()

{
	cout << " TΪ���أ�RΪ�ص����˵������ƴ�Сд:_\b";
	char back;
	cin >> back;
	if (back == 'R' || back == 'r')
	{
		system("cls");
		return 1;
	}
	else
	{
		system("cls");
		return 0;
	}
}
void Contancts::zhuyemian()
{
	Contancts a;
	a.format();
	char select1;
top:cout << "\t\t******************************************************************** " << endl;
	cout << "\t\t**                       �������ֵ�                               **               " << endl;
	cout << "\t\t******************************************************************** " << endl
		<< "\t\t��                        ͨѶ¼                                  ��" << endl
		<< "\t\t��                                                                �� " << endl
		<< "\t\t��    1.ͨѶ¼�༭                3. ����                         �� " << endl
		<< "\t\t��                                                                ��" << endl
		<< "\t\t��                                                                ��" << endl
		<< "\t\t��    2.������ϵ��              4.���ͨѶ¼                      ��" << endl
		<< "\t\t��                                                                ��" << endl
		<< "\t\t��                  5 .��ʽ���������ã�                           ��" << endl
		<< "\t\t��                                                                ��" << endl
		<< "\t\t��                   6.�˳�                                       ��" << endl
		<< "\t\t��                                                                ��" << endl
		<< "\t\t��                                                                ��" << endl
		<< "\t\t��                                                                ��" << endl
		<< "\t\t��****************************************************************��" << endl
		<< "\t\t                                                                                                          "
		<< "\t\t\t:    ѡ��:";

	cin >> select1;
	switch (select1)
	{
	case'1':cout << "(1)   ���" << endl;
		cout << "(2)   ɾ��" << endl;
		cout << "(3)   �޸�" << endl;
		cout << "��ѡ�� " << endl;
		char select2;
		cin >> select2;
		switch (select2)
		{
		case'1':cout << "      �����������ϵ�˵���Ϣ:   " << endl; 
			char no[13];
			char name[20];
			char address[100];
			char tel_no[12];
			char work_place[30];
			char e_mail[40];
			char type[10];

			cout << "        ��������: " << endl;
			cin >> no;
			cout << "        ���������֣�" << endl;
			cin >> name;
			cout << "      ��ַ��" << endl;
			cin >> address;
			cout << "      �绰����:" << endl;
			cin >> tel_no;
			cout << "           ��λ��" << endl;
			cin >> work_place;
			cout << "   �������䣺" << endl;
			cin >> e_mail;
			cout << "���ࣺ" << endl;
			cin >> type;
			a.add(no, name, address, tel_no, work_place, e_mail, type);
			cout << "��ӳɹ�!" << endl;
			a.write();
			cout << "���ػ��ǻص����˵���TΪ�˳���RΪ�ص����˵������ƴ�Сд��:" << endl;
			char back_add;
			cin >> back_add;
			if (back_add == 'R' || back_add == 'r')
			{
				system("cls"); cout << endl; goto top;
			}
			else
			{
				cout << "****��������!*****" << endl;	system("cls"); goto  bottom;
			}
			break;
		case '2':cout << " ����Ҫɾ���˵�����:" << endl;
			char name2[20];
			cin >> name2;
			a.del(name2,a);
			cout << "���ػ��ǻص����˵���TΪ�˳���RΪ�ص����˵������ƴ�Сд��:" << endl;
			char back_del;
			cin >> back_del;
			if (back_del == 'R' || back_del == 'r')
			{
				system("cls"); cout << endl; goto top;
			}
			else
			{
				cout << "****ɾ������!*****" << endl;	system("cls"); goto bottom;
			}
			break;
		case '3':cout << " ������Ҫ�޸��˵�����:" << endl;
			char name3[20];
			cin >> name3;
			if (a.correct(name3,a))
			{
				system("cls"); cout << endl; goto top;
			}
			break;
		}
		break;
	case'2':system("cls"); a.reda(0);
		cout << "��ѡ�������ϵ�˷�ʽ��" << endl;
		cout << "*********************" << endl;
		cout << "(1)     �绰���ң�" << endl;
		cout << "(2)     �������ң�" << endl;
		cout << "(3)     ����" << endl;
		cout << "*********************" << endl;
		cout << "***��ѡ��:***" << endl;
		char select3;
		cin >> select3;
		switch (select3)
		{
		case'1':
			char tel_no2[12];
			cout << "�������:" << endl;
			cin >> tel_no2; system("cls");
			cout << setw(4) << "���" << "       " << setw(6) << "����" << "  " << setw(6) << "��ַ" <<
				"     " << setw(12) << "�绰����" << "    " << setw(7) << "��λ" << "  " << setw(15) << "e_mail" << "   " << setw(7) <<
				"����" << endl;
			i = a.find1(tel_no2,1);//��������½Ǳ�
			if (i != -1)
			{
				char choice;
				cout << "�Ƿ񲦴�:��---y,��---n >>>"; cin >> choice;
				if (choice == 'Y' || choice == 'y')
					callScreen(a);
				if (choice == 'N' || choice == 'n')
				{
					system("cls");
					cout << "***�˳��밴T���ص����˵��밴R�����ƴ�Сд��:" << endl;
					char back_f1;
					cin >> back_f1;
					if (back_f1 == 'R' || back_f1 == 'r')
					{
						system("cls"); cout << endl; goto top;
					}
					else
					{
						system("cls"); goto bottom;
					}
				}
			}
			break;
		case'2':
			char name4[20];
			cout << "**��������**"<<endl;
			cin >> name4; system("cls");
			cout << setw(4) << "���" << "       " << setw(6) << "����" << "  " << setw(6) << "��ַ" <<
				"     " << setw(12) << "�绰����" << "    " << setw(7) << "��λ" << "  " << setw(15) << "e_mail" << "   " << setw(7) <<
				"����" << endl;
		    i = a.find2(name4);//��������½Ǳ�
			if (i != -1)
			{
				char choice1;
				cout << "\n�Ƿ񲦴�:��---y,��---n: >>>"; cin >> choice1;
				if (choice1 == 'Y' || choice1 == 'y')
					callScreen(a);
				if (choice1 == 'N' || choice1 == 'n')
				{
					system("cls");
					cout << "***�˳��밴T���ص����˵��밴R�����ƴ�Сд��:" << endl;
					char  back_f2;
					cin >> back_f2;
					if (back_f2 == 'R' || back_f2 == 'r')
					{
						system("cls"); cout << endl; goto top;
					}
					else
					{
						system("cls"); goto bottom;
					}
				}
			}
			break;
		case'3':
	        back();
			break;
		}
		break;
	top2:case'3':system("cls"); cout << "      ȷ������1,�˳���2��" << endl;
		int back2;
		cin >> back2;
		if (back2 == 1)
		{
			system("cls"); a.list(a);
		}
		else
			if (back2 == 2)
			{
				back();
			}
			else
			{
				cout << "�������~~~\a" << endl; goto top2;
			}
		break;
	case'4':system("cls"); cout << endl;
		cout << setw(4) << "���" << "       " << setw(6) << "����" << "  " << setw(6) << "��ַ" <<
			"     " << setw(12) << "�绰����" << "    " << setw(7) << "��λ" << "  " << setw(15) << "e_mail" << "   " << setw(7) <<
			"����" << endl;
		a.reda(1); 
		cout << "�˳��밴T,�ص����˵��밴R(���ƴ�Сд):*** " << endl;
		char back_s;
		cin >> back_s;
		if (back_s == 'R' || back_s == 'r')
		{
			system("cls"); cout << endl; goto top;
		}
		else
		{
			system("cls"); goto bottom;
		}
		break;
	case'5':system("cls");
		cout << "��ȷ��ɾ����������!(Y/N)";
		char select5;
		cin >> select5;
		if (select5 == 'Y' || select5 == 'y')
			a.format(a);
		cout << " ���ػ��ǻص����˵���TΪ�˳���RΪ�ص����˵������ƴ�Сд: ";
		char back_f3;
		cin >> back_f3;
		if (back_f3 == 'R' || back_f3 == 'r')
		{
			system("cls"); cout << endl; goto top;
		}
		else
		{
			system("cls"); goto bottom;
		}
		break;
	case'6':system("cls");
		char off;
		cout << "\t\t��6�˳�: ";
		cin >> off;
		if (off == '6')
		{
			system("cls"); goto bottom;
		}
	bottom:cout<<"";
	}
	
}

//�����ϵ��************************************************************************
void Contancts::add(char no[13], char name[20], char address[100], char tel_no[12], char work_place[30], char e_mail[40], char type[10])
{
	int x = 1;//����һ�����ͱ��������ж�
	for (int i = 0; i < 37; i++)
	{
		if (!strcmp(st[i].no, "0"))
		{
			strcpy_s(st[i].no, 5, no);
			strcpy_s(st[i].name, 20, name);
			strcpy_s(st[i].address, 100, address);
			strcpy_s(st[i].tel_no, 12, tel_no);
			strcpy_s(st[i].work_place, 30, work_place);
			strcpy_s(st[i].e_mail, 40, e_mail);
			strcpy_s(st[i].type, 10, type);
			x = 0;
		}
		if (x == 0)
			break;
	}
}
//ɾ����ϵ��
void Contancts::del(char name[20], Contancts& con)
{
	bool temp = 0;//����һ���������������ж�
	for (int i = 0; i<35; i++)
	{
		con.reda(0);
		if (!strcmp(st[i].name, name))//���������ͬ
		{
			temp = 1;
			strcpy_s(st[i].no, 5, " ");
			strcpy_s(st[i].name, 20, " ");
			strcpy_s(st[i].address, 100, " ");
			strcpy_s(st[i].tel_no, 12, " ");
			strcpy_s(st[i].work_place, 30, " ");
			strcpy_s(st[i].e_mail, 40, " ");
			strcpy_s(st[i].type, 10, " ");
			con.write();
			cout << "*****ɾ���ɹ�!*******" << endl;
		}
	}
	if (!temp)
	{
		cout << "*****���޴���!*******" << endl;
	}
}
//�޸���ϵ��
int  Contancts::correct(char name[30],Contancts& con)
{
	int x;
	for (int i = 0; i<37; i++)
	{
		con.reda(0);
		if (!strcmp(st[i].name, name))
		{
			x = i;
			char select;
		top1:
			cout << "*********************************************************" << endl; cout << "(1)       ���޸�����" << endl;
			cout << "(2)       ���޸ĵ�ַ" << endl;
			cout << "(3)       ���޸ĵ绰���� " << endl;
			cout << "(4)       ���޸ĵ�������" << endl;
			cout << "(5)       ����" << endl;
			cout << "*********************************************************" << endl;
			cin >> select;
			switch (select)
			{
			case'1':
				cout << "         ����Ҫ�޸ĵ�����:";
				char name1[30];
				cin >> name1;
				strcpy_s(st[x].name, 30, name1);
				con.write();
				cout << "        �޸ĳɹ���" << endl; 
				Sleep(1000);
				system("cls");
				goto top1;
				break;
			case '2':
				cout << "         ����Ҫ�޸ĵĵ�ַ:";
				char address1[100];
				cin >> address1;
				strcpy_s(st[x].address, 100, address1);
				con.write();
				cout << "        �޸ĳɹ���" << endl;
				Sleep(1000);
				system("cls");
				goto top1;
				break;
			case '3':
				cout << "         ����Ҫ�޸ĵĵ绰����:";
				char tel_no1[12];
				cin >> tel_no1;
				strcpy_s(st[x].tel_no, 12, tel_no1);
				con.write();
				cout << "        �޸ĳɹ���" << endl;
				Sleep(1000);
				system("cls");
				goto top1;
				break;
			case'4':
				cout << "         ����Ҫ�޸ĵ��ʱ�:";
				char e_mail2[40];
				cin >> e_mail2;
				strcpy_s(st[x].e_mail, 40, e_mail2);
				con.write();
				cout << "        �޸ĳɹ���" << endl;
				Sleep(1000);
				system("cls");
				goto top1;
				break;
			case'5':
				return back();
				break;
			}
		}
	}
	cout << "ͨѶ¼�����ڸ���ϵ��\a" << endl;
	return back();
}
//���������ϵ��
int  Contancts::find1(char tel_no[13],int flag1)
{
	int x, y = 1, z = 1;
	for (int i = 0; i < 35; i++)
	{
		if (!strcmp(st[i].tel_no, tel_no))
		{
			x = i;
			z = 0;
			if(flag1 == 1)
			   print(x);
			return x;
		}
		else
			y = 0;
		if (z == 0)
			break;

	}
	if (y == 0)
	{
		cout << "        ����ĺ�����Ҳ���������" << endl; Sleep(2000); system("cls"); return -1;
	}
	return -1;
}
//�� ��������
int  Contancts::find2(char name[20])
{
	int x, y = 1, z = 1;
	for (int i = 0; i < 37; i++)
	{
		if (!strcmp(st[i].name, name))
		{
			x = i;
			z = 0;
			print(x);
			return x;
		}
		else
			y = 0;
		if (z == 0)
			break;
	}
	if (y == 0)
	{
		cout << "        ������������Ҳ���������" << endl; Sleep(2000); system("cls"); return -1;
	}
	return -1;
}
//ͨѶ¼����
void  Contancts::list(Contancts& con)
{
	con.reda(0);
	for (int i = 0; i < 37; i++)//ð�ݷ�����
	{
		for (int j = 0; j < 37 - i; j++)
		{
			if (strcmp(st[j].no, st[j + 1].no) > 0)//�Ƚ��ַ����Ĵ�С
			{
				char no[12];
				char name[30];
				char address[100];
				char tel_no[12];
				char work_place[30];
				char e_mail[40];
				char type[10];
				strcpy_s(no, st[j].no);//�������Ϣ����
				strcpy_s(st[j].no, st[j + 1].no);
				strcpy_s(st[j + 1].no, no);
				strcpy_s(name, st[j].name);//��������Ϣ����
				strcpy_s(st[j].name, st[j + 1].name);
				strcpy_s(st[j + 1].name, name);
				strcpy_s(address, st[j].address);//����ַ��Ϣ����
				strcpy_s(st[j].address, st[j + 1].address);
				strcpy_s(st[j + 1].address, address);
				strcpy_s(tel_no, st[j].tel_no);//�����뽻��
				strcpy_s(st[j].tel_no, st[j + 1].tel_no);
				strcpy_s(st[j + 1].tel_no, tel_no);
				strcpy_s(work_place, st[j].work_place);//
				strcpy_s(st[j].work_place, st[j + 1].work_place);
				strcpy_s(st[j + 1].work_place, work_place);
				strcpy_s(e_mail, st[j].e_mail);//������������
				strcpy_s(st[j].e_mail, st[j + 1].e_mail);
				strcpy_s(st[j + 1].e_mail, e_mail);
				strcpy_s(type, st[j].type);//�������
				strcpy_s(st[j].type, st[j + 1].type);
				strcpy_s(st[j + 1].type, type);
			}
		}
	}
	con.write();
	for (int k = 0; k<37; k++)
		print(k);
	Sleep(2000);
	system("cls");
}
//�����ļ�
void  Contancts::write()
{
	int i;
	ofstream outfile("ͨѶ¼.txt", ios::out);//���ļ�
	if (!outfile)//���ļ�
	{
		cerr << "open ͨѶ¼.txt error!" << endl;
		exit(1);
	}
	for (i = 0; i < 37; i++)//�����ļ�
	{
		outfile << setiosflags(ios::left) << setw(4) << st[i].no << "       " << setw(6) << st[i].name << "  " << setw(6) << st[i].address <<
			"     " << setw(12) << st[i].tel_no << "    " << setw(7) << st[i].work_place << "  " << setw(15) << st[i].e_mail << "   " << setw(7) <<
			st[i].type << endl;

	}
	outfile.close();//�ر��ļ�
	cout << endl;
	cout << "�����ѱ���" << endl;


}
//��ȡ�ļ�
void Contancts::reda(int flag)
{
	ifstream infile("ͨѶ¼.txt", ios::out);//���ļ�
	if (!infile)//���ļ�
	{
		cerr << "open ͨѶ¼.txt error!" << endl; Sleep(2000);
		system("cls");
		zhuyemian();
	}
	else
	{
		for (int i = 0; i < 37; i++)//��ȡ�ļ�
		{
			infile >> st[i].no;
			infile >> st[i].name;
			infile >> st[i].address;
			infile >> st[i].tel_no;
			infile >> st[i].work_place;
			infile >> st[i].e_mail;
			infile >> st[i].type;
			if(flag == 1)
			    print(i);
		}
	}
}
//�����ϵ��
void Contancts::print(int i)
{
	if (strcmp(st[i].no, "0"))
	{
		cout << setw(4) << st[i].no << "       " << setw(6) << st[i].name << "  " << setw(6) << st[i].address <<
			"     " << setw(12) << st[i].tel_no << "    " << setw(7) << st[i].work_place << "  " << setw(15) << st[i].e_mail << "   " << setw(7) <<
			st[i].type << endl;
	}
}
//��ʼ���ļ�
void  Contancts::format()
{
	for (int i = 0; i < 37; i++)
	{
		strcpy_s(st[i].no, "0");
		strcpy_s(st[i].name, "0");
		strcpy_s(st[i].address, "0");
		strcpy_s(st[i].tel_no, "0");
		strcpy_s(st[i].work_place, "0");
		strcpy_s(st[i].e_mail, "0");
		strcpy_s(st[i].type, "0");
	}
}
//��ʽ��
void Contancts::format(Contancts& con)
{
	con.reda(0);
	for (int i = 0; i < 37; i++)
	{
		strcpy_s(st[i].no, "0");
		strcpy_s(st[i].name, "0");
		strcpy_s(st[i].address, "0");
		strcpy_s(st[i].tel_no, "0");
		strcpy_s(st[i].work_place, "0");
		strcpy_s(st[i].e_mail, "0");
		strcpy_s(st[i].type, "0");
	}
	con.write();
}

//**********************************************************************
void Contancts::callScreen(Contancts& c)
{
	string tel_no;
	cout << "������Ҫ����ĵ绰����: ___________\b\b\b\b\b\b\b\b\b\b\b"; cin >> tel_no; system("cls");
	if (tel_no == c.st[i].tel_no)
	{
		cout << "���ڲ�����...\n"; cout << endl;
		playSound(1);
	cout << "\t\t\t��***************************��" << endl;
	cout << "\t\t\t��                           ��" << endl;
	cout << "\t\t\t��"<<setw(15)<< c.st[i].name   <<"            ��" << endl;
	cout << "\t\t\t��                           ��" << endl;
	cout << "\t\t\t��                           ��" << endl;
	cout << "\t\t\t��                           ��" << endl;
	cout << "\t\t\t��"<<setw(19)<< c.st[i].tel_no <<"        ��" << endl;
	cout << "\t\t\t��                           ��" << endl;
	cout << "\t\t\t��                           ��" << endl;
	cout << "\t\t\t��                           ��" << endl;
	cout << "\t\t\t��"<<setw(18)<< c.st[i].address<<"         ��" << endl;
	cout << "\t\t\t��                           ��" << endl;
	cout << "\t\t\t��                           ��" << endl;
	cout << "\t\t\t��            >>>>>          ��" << endl;
	cout << "\t\t\t��***************************��" << endl;
	cout << endl << endl;
	playSound(2);
	cout << "ͨ����..."; Sleep(8000);
	playSound(3);
	cout << "\n\nͨ������"; Sleep(2000);
	system("cls");
	//PlaySound(TEXT("E:\\WAV\\Ringout.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	}
	else
	{
		cout << "�������\a" << endl; Sleep(2000); system("cls");
	}
}


void Contancts::call()
{
	Contancts Obj;
	string Tel;
	char teleNum[12];
	int n;
	Obj.reda(0);
	cout << "\t\t\t��***************************��" << endl;
	cout << "\t\t\t�� 9:34 am             ~��ͨ~��" << endl;
	cout << "\t\t\t��                           ��" << endl;
	cout << "\t\t\t��                           ��" << endl;
	cout << "\t\t\t��    ��1��   ��2��   ��3��  ��" << endl;
	cout << "\t\t\t��                           ��" << endl;
	cout << "\t\t\t��    ��4��   ��5��   ��6��  ��" << endl;
	cout << "\t\t\t��                           ��" << endl;
	cout << "\t\t\t��    ��7��   ��8��   ��9��  ��" << endl;
	cout << "\t\t\t��                           ��" << endl;
	cout << "\t\t\t��    ��*��   ��0��   ��#��  ��" << endl;
	cout << "\t\t\t��                           ��" << endl;
	cout << "\t\t\t��                           ��" << endl;
	cout << "\t\t\t��           >>>>>           ��" << endl;
	cout << "\t\t\t��***************************��" << endl;
	cout << "������Ҫ����ĵ绰����: ___________\b\b\b\b\b\b\b\b\b\b\b"; cin >> teleNum; system("cls");
	n = Obj.find1(teleNum, 0);
	if (!strcmp(teleNum,Obj.st[n].tel_no))
	{
		cout << "���ڲ�����...\n"; cout << endl;
		playSound(1);
		cout << "\t\t\t��***************************��" << endl;
		cout << "\t\t\t��                           ��" << endl;
		cout << "\t\t\t��" << setw(15) << Obj.st[n].name << "            ��" << endl;
		cout << "\t\t\t��                           ��" << endl;
		cout << "\t\t\t��                           ��" << endl;
		cout << "\t\t\t��                           ��" << endl;
		cout << "\t\t\t��" << setw(19) << Obj.st[n].tel_no << "        ��" << endl;
		cout << "\t\t\t��                           ��" << endl;
		cout << "\t\t\t��                           ��" << endl;
		cout << "\t\t\t��                           ��" << endl;
		cout << "\t\t\t��" << setw(16) << Obj.st[n].address << "           ��" << endl;
		cout << "\t\t\t��                           ��" << endl;
		cout << "\t\t\t��                           ��" << endl;
		cout << "\t\t\t��            >>>>>          ��" << endl;
		cout << "\t\t\t��***************************��" << endl;
		cout << endl << endl;
		playSound(2);
		cout << "ͨ����..."; Sleep(8000);
		playSound(3);
		cout << "\n\nͨ������"; Sleep(2000);
		system("cls");
	}
	else
	{
		if (teleNum[11] == '\0')//�ж�����ĺ����Ƿ���11λ
		{
			cout << "���ڲ�����...\n"; cout << endl;
			playSound(1);
			cout << "\t\t\t��***************************��" << endl;
			cout << "\t\t\t��                           ��" << endl;
			cout << "\t\t\t��                           ��" << endl;
			cout << "\t\t\t��         δ֪��ϵ��        ��" << endl;
			cout << "\t\t\t��                           ��" << endl;
			cout << "\t\t\t��                           ��" << endl;
			cout << "\t\t\t��         " << teleNum << "       ��" << endl;
			cout << "\t\t\t��                           ��" << endl;
			cout << "\t\t\t��                           ��" << endl;
			cout << "\t\t\t��                           ��" << endl;
			cout << "\t\t\t��          δ֪�ص�         ��" << endl;
			cout << "\t\t\t��                           ��" << endl;
			cout << "\t\t\t��                           ��" << endl;
			cout << "\t\t\t��            >>>>>          ��" << endl;
			cout << "\t\t\t��***************************��" << endl;
			cout << endl << endl;
			playSound(2);
			cout << "ͨ����..."; Sleep(8000);
			playSound(3);
			cout << "\n\nͨ������"; Sleep(2000);
			system("cls");
		}
		else
		{
			cout << "����ĺ���λ������~~~"; Sleep(2000); system("cls");
		}
	}
}

