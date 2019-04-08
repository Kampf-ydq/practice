#include"Contanct.h"
#include  <windows.h> 
#include  <iostream> 
#include "mmsystem.h"//导入声音头文件
#pragma comment(lib,"winmm.lib")//导入声音头文件库

void playSound();

void playSound(int choose)//1表示拨电话,2(接电话),3(挂电话)
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
	cout << " T为返回，R为回到主菜单，不计大小写:_\b";
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
	cout << "\t\t**                       火线三兄弟                               **               " << endl;
	cout << "\t\t******************************************************************** " << endl
		<< "\t\t※                        通讯录                                  ※" << endl
		<< "\t\t※                                                                ※ " << endl
		<< "\t\t※    1.通讯录编辑                3. 排序                         ※ " << endl
		<< "\t\t※                                                                ※" << endl
		<< "\t\t※                                                                ※" << endl
		<< "\t\t※    2.查找联系人              4.浏览通讯录                      ※" << endl
		<< "\t\t※                                                                ※" << endl
		<< "\t\t※                  5 .格式化！（慎用）                           ※" << endl
		<< "\t\t※                                                                ※" << endl
		<< "\t\t※                   6.退出                                       ※" << endl
		<< "\t\t※                                                                ※" << endl
		<< "\t\t※                                                                ※" << endl
		<< "\t\t※                                                                ※" << endl
		<< "\t\t※****************************************************************※" << endl
		<< "\t\t                                                                                                          "
		<< "\t\t\t:    选择:";

	cin >> select1;
	switch (select1)
	{
	case'1':cout << "(1)   添加" << endl;
		cout << "(2)   删除" << endl;
		cout << "(3)   修改" << endl;
		cout << "请选择 " << endl;
		char select2;
		cin >> select2;
		switch (select2)
		{
		case'1':cout << "      请添加您的联系人的信息:   " << endl; 
			char no[13];
			char name[20];
			char address[100];
			char tel_no[12];
			char work_place[30];
			char e_mail[40];
			char type[10];

			cout << "        请输入编号: " << endl;
			cin >> no;
			cout << "        请输入名字：" << endl;
			cin >> name;
			cout << "      地址：" << endl;
			cin >> address;
			cout << "      电话号码:" << endl;
			cin >> tel_no;
			cout << "           单位：" << endl;
			cin >> work_place;
			cout << "   电子邮箱：" << endl;
			cin >> e_mail;
			cout << "分类：" << endl;
			cin >> type;
			a.add(no, name, address, tel_no, work_place, e_mail, type);
			cout << "添加成功!" << endl;
			a.write();
			cout << "返回还是回到主菜单（T为退出，R为回到主菜单，不计大小写）:" << endl;
			char back_add;
			cin >> back_add;
			if (back_add == 'R' || back_add == 'r')
			{
				system("cls"); cout << endl; goto top;
			}
			else
			{
				cout << "****输入有误!*****" << endl;	system("cls"); goto  bottom;
			}
			break;
		case '2':cout << " 输入要删除人的姓名:" << endl;
			char name2[20];
			cin >> name2;
			a.del(name2,a);
			cout << "返回还是回到主菜单（T为退出，R为回到主菜单，不计大小写）:" << endl;
			char back_del;
			cin >> back_del;
			if (back_del == 'R' || back_del == 'r')
			{
				system("cls"); cout << endl; goto top;
			}
			else
			{
				cout << "****删除有误!*****" << endl;	system("cls"); goto bottom;
			}
			break;
		case '3':cout << " 输入需要修改人的姓名:" << endl;
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
		cout << "请选择查找联系人方式：" << endl;
		cout << "*********************" << endl;
		cout << "(1)     电话查找：" << endl;
		cout << "(2)     姓名查找：" << endl;
		cout << "(3)     返回" << endl;
		cout << "*********************" << endl;
		cout << "***请选择:***" << endl;
		char select3;
		cin >> select3;
		switch (select3)
		{
		case'1':
			char tel_no2[12];
			cout << "输入号码:" << endl;
			cin >> tel_no2; system("cls");
			cout << setw(4) << "编号" << "       " << setw(6) << "姓名" << "  " << setw(6) << "地址" <<
				"     " << setw(12) << "电话号码" << "    " << setw(7) << "单位" << "  " << setw(15) << "e_mail" << "   " << setw(7) <<
				"分类" << endl;
			i = a.find1(tel_no2,1);//用来存放下角标
			if (i != -1)
			{
				char choice;
				cout << "是否拨打:是---y,否---n >>>"; cin >> choice;
				if (choice == 'Y' || choice == 'y')
					callScreen(a);
				if (choice == 'N' || choice == 'n')
				{
					system("cls");
					cout << "***退出请按T，回到主菜单请按R（不计大小写）:" << endl;
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
			cout << "**输入姓名**"<<endl;
			cin >> name4; system("cls");
			cout << setw(4) << "编号" << "       " << setw(6) << "姓名" << "  " << setw(6) << "地址" <<
				"     " << setw(12) << "电话号码" << "    " << setw(7) << "单位" << "  " << setw(15) << "e_mail" << "   " << setw(7) <<
				"分类" << endl;
		    i = a.find2(name4);//用来存放下角标
			if (i != -1)
			{
				char choice1;
				cout << "\n是否拨打:是---y,否---n: >>>"; cin >> choice1;
				if (choice1 == 'Y' || choice1 == 'y')
					callScreen(a);
				if (choice1 == 'N' || choice1 == 'n')
				{
					system("cls");
					cout << "***退出请按T，回到主菜单请按R（不计大小写）:" << endl;
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
	top2:case'3':system("cls"); cout << "      确认排序按1,退出按2：" << endl;
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
				cout << "输入错误~~~\a" << endl; goto top2;
			}
		break;
	case'4':system("cls"); cout << endl;
		cout << setw(4) << "编号" << "       " << setw(6) << "姓名" << "  " << setw(6) << "地址" <<
			"     " << setw(12) << "电话号码" << "    " << setw(7) << "单位" << "  " << setw(15) << "e_mail" << "   " << setw(7) <<
			"分类" << endl;
		a.reda(1); 
		cout << "退出请按T,回到主菜单请按R(不计大小写):*** " << endl;
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
		cout << "请确认删除所有资料!(Y/N)";
		char select5;
		cin >> select5;
		if (select5 == 'Y' || select5 == 'y')
			a.format(a);
		cout << " 返回还是回到主菜单（T为退出，R为回到主菜单，不计大小写: ";
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
		cout << "\t\t按6退出: ";
		cin >> off;
		if (off == '6')
		{
			system("cls"); goto bottom;
		}
	bottom:cout<<"";
	}
	
}

//添加联系人************************************************************************
void Contancts::add(char no[13], char name[20], char address[100], char tel_no[12], char work_place[30], char e_mail[40], char type[10])
{
	int x = 1;//定义一个整型变量用于判断
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
//删除联系人
void Contancts::del(char name[20], Contancts& con)
{
	bool temp = 0;//定义一个布尔变量用于判断
	for (int i = 0; i<35; i++)
	{
		con.reda(0);
		if (!strcmp(st[i].name, name))//如果姓名相同
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
			cout << "*****删除成功!*******" << endl;
		}
	}
	if (!temp)
	{
		cout << "*****查无此人!*******" << endl;
	}
}
//修改联系人
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
			cout << "*********************************************************" << endl; cout << "(1)       请修改姓名" << endl;
			cout << "(2)       请修改地址" << endl;
			cout << "(3)       请修改电话号码 " << endl;
			cout << "(4)       请修改电子邮箱" << endl;
			cout << "(5)       返回" << endl;
			cout << "*********************************************************" << endl;
			cin >> select;
			switch (select)
			{
			case'1':
				cout << "         输入要修改的姓名:";
				char name1[30];
				cin >> name1;
				strcpy_s(st[x].name, 30, name1);
				con.write();
				cout << "        修改成功！" << endl; 
				Sleep(1000);
				system("cls");
				goto top1;
				break;
			case '2':
				cout << "         输入要修改的地址:";
				char address1[100];
				cin >> address1;
				strcpy_s(st[x].address, 100, address1);
				con.write();
				cout << "        修改成功！" << endl;
				Sleep(1000);
				system("cls");
				goto top1;
				break;
			case '3':
				cout << "         输入要修改的电话号码:";
				char tel_no1[12];
				cin >> tel_no1;
				strcpy_s(st[x].tel_no, 12, tel_no1);
				con.write();
				cout << "        修改成功！" << endl;
				Sleep(1000);
				system("cls");
				goto top1;
				break;
			case'4':
				cout << "         输入要修改的邮编:";
				char e_mail2[40];
				cin >> e_mail2;
				strcpy_s(st[x].e_mail, 40, e_mail2);
				con.write();
				cout << "        修改成功！" << endl;
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
	cout << "通讯录不存在该联系人\a" << endl;
	return back();
}
//号码查找联系人
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
		cout << "        输入的号码查找不到！！！" << endl; Sleep(2000); system("cls"); return -1;
	}
	return -1;
}
//按 姓名查找
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
		cout << "        输入的姓名查找不到！！！" << endl; Sleep(2000); system("cls"); return -1;
	}
	return -1;
}
//通讯录排序
void  Contancts::list(Contancts& con)
{
	con.reda(0);
	for (int i = 0; i < 37; i++)//冒泡法排序
	{
		for (int j = 0; j < 37 - i; j++)
		{
			if (strcmp(st[j].no, st[j + 1].no) > 0)//比较字符串的大小
			{
				char no[12];
				char name[30];
				char address[100];
				char tel_no[12];
				char work_place[30];
				char e_mail[40];
				char type[10];
				strcpy_s(no, st[j].no);//将编号信息交换
				strcpy_s(st[j].no, st[j + 1].no);
				strcpy_s(st[j + 1].no, no);
				strcpy_s(name, st[j].name);//将姓名信息交换
				strcpy_s(st[j].name, st[j + 1].name);
				strcpy_s(st[j + 1].name, name);
				strcpy_s(address, st[j].address);//将地址信息交换
				strcpy_s(st[j].address, st[j + 1].address);
				strcpy_s(st[j + 1].address, address);
				strcpy_s(tel_no, st[j].tel_no);//将号码交换
				strcpy_s(st[j].tel_no, st[j + 1].tel_no);
				strcpy_s(st[j + 1].tel_no, tel_no);
				strcpy_s(work_place, st[j].work_place);//
				strcpy_s(st[j].work_place, st[j + 1].work_place);
				strcpy_s(st[j + 1].work_place, work_place);
				strcpy_s(e_mail, st[j].e_mail);//交换电子邮箱
				strcpy_s(st[j].e_mail, st[j + 1].e_mail);
				strcpy_s(st[j + 1].e_mail, e_mail);
				strcpy_s(type, st[j].type);//交换类别
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
//导入文件
void  Contancts::write()
{
	int i;
	ofstream outfile("通讯录.txt", ios::out);//打开文件
	if (!outfile)//打开文件
	{
		cerr << "open 通讯录.txt error!" << endl;
		exit(1);
	}
	for (i = 0; i < 37; i++)//导入文件
	{
		outfile << setiosflags(ios::left) << setw(4) << st[i].no << "       " << setw(6) << st[i].name << "  " << setw(6) << st[i].address <<
			"     " << setw(12) << st[i].tel_no << "    " << setw(7) << st[i].work_place << "  " << setw(15) << st[i].e_mail << "   " << setw(7) <<
			st[i].type << endl;

	}
	outfile.close();//关闭文件
	cout << endl;
	cout << "资料已保存" << endl;


}
//读取文件
void Contancts::reda(int flag)
{
	ifstream infile("通讯录.txt", ios::out);//打开文件
	if (!infile)//打开文件
	{
		cerr << "open 通讯录.txt error!" << endl; Sleep(2000);
		system("cls");
		zhuyemian();
	}
	else
	{
		for (int i = 0; i < 37; i++)//读取文件
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
//输出联系人
void Contancts::print(int i)
{
	if (strcmp(st[i].no, "0"))
	{
		cout << setw(4) << st[i].no << "       " << setw(6) << st[i].name << "  " << setw(6) << st[i].address <<
			"     " << setw(12) << st[i].tel_no << "    " << setw(7) << st[i].work_place << "  " << setw(15) << st[i].e_mail << "   " << setw(7) <<
			st[i].type << endl;
	}
}
//初始化文件
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
//格式化
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
	cout << "输入您要拨打的电话号码: ___________\b\b\b\b\b\b\b\b\b\b\b"; cin >> tel_no; system("cls");
	if (tel_no == c.st[i].tel_no)
	{
		cout << "正在拨号中...\n"; cout << endl;
		playSound(1);
	cout << "\t\t\t※***************************※" << endl;
	cout << "\t\t\t※                           ※" << endl;
	cout << "\t\t\t※"<<setw(15)<< c.st[i].name   <<"            ※" << endl;
	cout << "\t\t\t※                           ※" << endl;
	cout << "\t\t\t※                           ※" << endl;
	cout << "\t\t\t※                           ※" << endl;
	cout << "\t\t\t※"<<setw(19)<< c.st[i].tel_no <<"        ※" << endl;
	cout << "\t\t\t※                           ※" << endl;
	cout << "\t\t\t※                           ※" << endl;
	cout << "\t\t\t※                           ※" << endl;
	cout << "\t\t\t※"<<setw(18)<< c.st[i].address<<"         ※" << endl;
	cout << "\t\t\t※                           ※" << endl;
	cout << "\t\t\t※                           ※" << endl;
	cout << "\t\t\t※            >>>>>          ※" << endl;
	cout << "\t\t\t※***************************※" << endl;
	cout << endl << endl;
	playSound(2);
	cout << "通话中..."; Sleep(8000);
	playSound(3);
	cout << "\n\n通话结束"; Sleep(2000);
	system("cls");
	//PlaySound(TEXT("E:\\WAV\\Ringout.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	}
	else
	{
		cout << "号码错误\a" << endl; Sleep(2000); system("cls");
	}
}


void Contancts::call()
{
	Contancts Obj;
	string Tel;
	char teleNum[12];
	int n;
	Obj.reda(0);
	cout << "\t\t\t※***************************※" << endl;
	cout << "\t\t\t※ 9:34 am             ~联通~※" << endl;
	cout << "\t\t\t※                           ※" << endl;
	cout << "\t\t\t※                           ※" << endl;
	cout << "\t\t\t※    【1】   【2】   【3】  ※" << endl;
	cout << "\t\t\t※                           ※" << endl;
	cout << "\t\t\t※    【4】   【5】   【6】  ※" << endl;
	cout << "\t\t\t※                           ※" << endl;
	cout << "\t\t\t※    【7】   【8】   【9】  ※" << endl;
	cout << "\t\t\t※                           ※" << endl;
	cout << "\t\t\t※    【*】   【0】   【#】  ※" << endl;
	cout << "\t\t\t※                           ※" << endl;
	cout << "\t\t\t※                           ※" << endl;
	cout << "\t\t\t※           >>>>>           ※" << endl;
	cout << "\t\t\t※***************************※" << endl;
	cout << "输入您要拨打的电话号码: ___________\b\b\b\b\b\b\b\b\b\b\b"; cin >> teleNum; system("cls");
	n = Obj.find1(teleNum, 0);
	if (!strcmp(teleNum,Obj.st[n].tel_no))
	{
		cout << "正在拨号中...\n"; cout << endl;
		playSound(1);
		cout << "\t\t\t※***************************※" << endl;
		cout << "\t\t\t※                           ※" << endl;
		cout << "\t\t\t※" << setw(15) << Obj.st[n].name << "            ※" << endl;
		cout << "\t\t\t※                           ※" << endl;
		cout << "\t\t\t※                           ※" << endl;
		cout << "\t\t\t※                           ※" << endl;
		cout << "\t\t\t※" << setw(19) << Obj.st[n].tel_no << "        ※" << endl;
		cout << "\t\t\t※                           ※" << endl;
		cout << "\t\t\t※                           ※" << endl;
		cout << "\t\t\t※                           ※" << endl;
		cout << "\t\t\t※" << setw(16) << Obj.st[n].address << "           ※" << endl;
		cout << "\t\t\t※                           ※" << endl;
		cout << "\t\t\t※                           ※" << endl;
		cout << "\t\t\t※            >>>>>          ※" << endl;
		cout << "\t\t\t※***************************※" << endl;
		cout << endl << endl;
		playSound(2);
		cout << "通话中..."; Sleep(8000);
		playSound(3);
		cout << "\n\n通话结束"; Sleep(2000);
		system("cls");
	}
	else
	{
		if (teleNum[11] == '\0')//判断输入的号码是否有11位
		{
			cout << "正在拨号中...\n"; cout << endl;
			playSound(1);
			cout << "\t\t\t※***************************※" << endl;
			cout << "\t\t\t※                           ※" << endl;
			cout << "\t\t\t※                           ※" << endl;
			cout << "\t\t\t※         未知联系人        ※" << endl;
			cout << "\t\t\t※                           ※" << endl;
			cout << "\t\t\t※                           ※" << endl;
			cout << "\t\t\t※         " << teleNum << "       ※" << endl;
			cout << "\t\t\t※                           ※" << endl;
			cout << "\t\t\t※                           ※" << endl;
			cout << "\t\t\t※                           ※" << endl;
			cout << "\t\t\t※          未知地点         ※" << endl;
			cout << "\t\t\t※                           ※" << endl;
			cout << "\t\t\t※                           ※" << endl;
			cout << "\t\t\t※            >>>>>          ※" << endl;
			cout << "\t\t\t※***************************※" << endl;
			cout << endl << endl;
			playSound(2);
			cout << "通话中..."; Sleep(8000);
			playSound(3);
			cout << "\n\n通话结束"; Sleep(2000);
			system("cls");
		}
		else
		{
			cout << "输入的号码位数不够~~~"; Sleep(2000); system("cls");
		}
	}
}

