#include"iWatch.h"
#include<stdlib.h>
#include<time.h>
#include  <windows.h> 
#include  <iostream> 
#include "mmsystem.h"//导入声音头文件
#pragma comment(lib,"winmm.lib")//导入声音头文件库

int iWatch::flag = 0;
iWatch::iWatch()  { }
void iWatch::lockScreen()
{
	//获取系统日期、时间
	SYSTEMTIME systemTime;
	GetLocalTime(&systemTime);
  
	//随时拨进电话
	srand((unsigned)time(NULL));//初始化随机种子
	int a = rand() % (5 - 1);
	if (a == 2)
		answerScreen();

	string lockKey;//锁屏开屏键
	cout << "\t\t※******************************************************************※" << endl;
	cout << "\t\t※     "<< systemTime.wHour<<":"<< systemTime.wMinute
		 <<"                                             沈阳 >      ※" << endl;
	cout << "\t\t※   "<< systemTime.wYear<<"/"<< systemTime.wMonth<<"/"<< systemTime.wDay
		 <<"                                                      ※" << endl
		<< "\t\t※                                                                  ※" << endl
		<< "\t\t※                            iWatch                                ※ " << endl
		<< "\t\t※                                                                  ※ " << endl
		<< "\t\t※                                                                  ※" << endl
		<< "\t\t※                     Input the following word                     ※" << endl                      
		<< "\t\t※                                                                  ※" << endl
		<< "\t\t※                                                                  ※" << endl
		<< "\t\t※                         >>Unlock(解锁)                           ※" << endl
		<< "\t\t※                                                                  ※" << endl
		<< "\t\t※                                                                  ※" << endl
		<< "\t\t※                         >>Over(退出程序)                         ※" << endl
		<< "\t\t※                                                                  ※" << endl
		<< "\t\t※                                                    2017/12/24    ※" << endl
		<< "\t\t※******************************************************************※" << endl;
	cout << "\t\t>>>"; cin >> lockKey; 
	PlaySound(TEXT("E:\\WAV\\Ringout4.wav"), NULL, SND_FILENAME | SND_ASYNC);
	if (lockKey == "Unlock")
	{
		system("cls"); mainScreen();
	}
	else
		if (lockKey == "Over")
		{
			system("cls"); cout << "谢谢使用"; exit(0);
		}
		else
		{
			cout << "输入错误,error~~~\a" << endl; Sleep(1000);
			system("cls");
			lockScreen();
		}
}

void iWatch::mainScreen()
{
	srand((unsigned)time(NULL));//初始化随机种子
	int a = rand() % (5 - 1);
	if (a == 2)
		answerScreen();


	int AppKey;//功能选择键
	cout << "\t\t※******************************************************************※" << endl;
	cout << "\t\t※                                                                  ※" << endl;
	cout << "\t\t※               【1】此手表                【2】电话               ※" << endl
		<< "\t\t※                                                                  ※" << endl
		<< "\t\t※                                                                  ※ " << endl
		<< "\t\t※               【3】计步器                【0】锁屏               ※ " << endl
		<< "\t\t※                                                                  ※" << endl
		<< "\t\t※                                                                  ※" << endl
		<< "\t\t※                    Input the number(0,1,2,3)                     ※" << endl
		<< "\t\t※                                                                  ※" << endl
		<< "\t\t※                                                                  ※" << endl
		<< "\t\t※                         to choose function                       ※" << endl
		<< "\t\t※                                                                  ※" << endl
		<< "\t\t※                              >>>>>                               ※" << endl
		<< "\t\t※                                                                  ※" << endl
		<< "\t\t※                                                    2017/12/24    ※" << endl
		<< "\t\t※******************************************************************※" << endl;
	cout << "\t\t>>>"; cin >> AppKey;
	PlaySound(TEXT("E:\\WAV\\Ringout3.wav"), NULL, SND_FILENAME | SND_ASYNC);
	switch (AppKey)
	{
	case 0:system("cls"); lockScreen(); break;
	case 1:system("cls"); iwaScreen(); break;
	case 2:system("cls"); phoneScreen(); break;
	case 3:system("cls"); goScreen(); break;
	default: cout << "此功能尚未开通" << endl;
		mainScreen();
		break;
	}
}

//iWatch功能模块
string iWatch::setName()
{
	string n;
	cout << "\t\tname: "; cin >> n;
	return  n;
}
string iWatch::setWorkplace()
{
	string w;
	cout << "\t\twork place: "; cin >> w;
	return  w;
}
string iWatch::setNumber()
{
	string m;
	cout << "\t\ttelephone number: "; cin >> m;
	return  m;
}
string iWatch::setEmail()
{
	string e;
	cout << "\t\te-mail: "; cin >> e;
	return e;
}
void iWatch::iwaScreen()
{
	string Key1;
	if (flag == 0)
	{
		name = "Jack"; workPlace = " SUT ";
		number = "18996620875";  email = "2410481664@qq.com";
	}
	cout << "\t\t  The information of personal iwatch\n" << endl;
	cout << "\t\t-------------------------------------- " << endl;
	cout << "\t\tName: " << name << endl;
	cout << "\t\tWorkPlace: " << workPlace << endl;
	cout << "\t\tNumber: " << number << endl;
	cout << "\t\tE-mail: " << email << endl;
	cout << "\t\t-------------------------------------- " << endl;
	cout << "\t\t修改个人信息---rewrite,返回主界面---main" << endl<<endl;
	cout << "\t\t>>>"; cin >> Key1; 
	PlaySound(TEXT("E:\\WAV\\Ringout3.wav"), NULL, SND_FILENAME | SND_ASYNC);
	cout << endl;
	if (Key1 == "rewrite")
	{
		name = setName();
		workPlace = setWorkplace();
		number = setNumber();
		email = setEmail();
		cout << "\t\t修改完成" << endl;
		Sleep(3000);//stop 3 s
		flag = 1;
		system("cls"); mainScreen();
	}
	else
		if (Key1 == "main")
		{
			system("cls"); mainScreen();
		}
		else
		{
			cout << "\t\t输入错误,error~~~\a" << endl; Sleep(2000);
			system("cls");
			mainScreen();
		}
}



//phone功能模块
void iWatch::phoneScreen()
{
	srand((unsigned)time(NULL));//初始化随机种子
	int a = rand() % (5 - 1);
	if (a == 2)
		answerScreen();

	int Key2;
	cout << "\t\t※******************************************************************※" << endl;
	cout << "\t\t※                                                                  ※" << endl;
	cout << "\t\t※               【1】打电话                  【2】通讯录           ※" << endl
		<< "\t\t※                                                                  ※" << endl
		<< "\t\t※                                                                  ※ " << endl
		<< "\t\t※               【3】主屏                    【0】锁屏             ※ " << endl
		<< "\t\t※                                                                  ※" << endl
		<< "\t\t※                                                                  ※" << endl
		<< "\t\t※                    Input the number(0,1,2,3)                     ※" << endl
		<< "\t\t※                                                                  ※" << endl
		<< "\t\t※                                                                  ※" << endl
		<< "\t\t※                         to choose function                       ※" << endl
		<< "\t\t※                                                                  ※" << endl
		<< "\t\t※                              >>>>>                               ※" << endl
		<< "\t\t※                                                                  ※" << endl
		<< "\t\t※                                                    2017/12/24    ※" << endl
		<< "\t\t※******************************************************************※" << endl;
	cout << "\t\t>>>"; cin >> Key2; 
	PlaySound(TEXT("E:\\WAV\\Ringout3.wav"), NULL, SND_FILENAME | SND_ASYNC);
	switch (Key2)
	{
	case 0:system("cls"); lockScreen(); break;
	case 1:system("cls"); conObj.call(); phoneScreen(); break;
	case 2:system("cls"); contanct(); phoneScreen(); break;
	case 3:
		system("cls"); mainScreen(); break;
	default:cout << "\t\t输入错误,error~~~\a" << endl;
		system("cls"); phoneScreen();
		break;
	}
}

void iWatch::contanct()
{
	conObj.zhuyemian();
}

void iWatch::goScreen()
{
	srand((unsigned)time(NULL));//初始化随机种子
	string chos;
	int p;
	//显示个人信息
	person.display();
	cout << "\t\t\t修改个人信息请输入1,否则请输入任意键: "; cin >> p;
	if (p == 1)
	{
		person.set();
		cout << "\t\t\t修改成功！！"; Sleep(2000); system("cls"); mainScreen();
	}
	else 
	{
		cout << "\t\t\t\t即将进入iWatch计步..."; Sleep(3000);
		system("cls");
		//计步
		cout << "\t\t\t------------------------------------" << endl;
		cout << "\t\t\tiWatch计步" << endl;
		cout << "\t\t\t------------------------------------" << endl;
		cout << "\t\t\t\t   *********   " << endl;
		cout << "\t\t\t\t *           * " << endl;
		cout << "\t\t\t\t*             *" << endl;
		cout << "\t\t\t\t*    Start    *    好友排名" << endl;
		cout << "\t\t\t\t*             *       " << rand() % (100 - 1) << endl;//排名在1~100
		cout << "\t\t\t\t *           * " << endl;
		cout << "\t\t\t\t   *********   " << endl;
		cout << "\t\t\t\t  满5000步打卡" << endl;
		cout << endl << endl;
		cout << "\t\t\t按s开始，退出按b:_\b"; cin >> chos;
		cout << endl;
		if (chos == "S" || chos == "s")
		{
			person.setHeartRate();
			cout << "\t\t\t                          @CopyRight" << endl;
			cout << "\t\t\t------------------------------------" << endl;
			cout << "\t\t\t------------------------------------" << endl;
			cout << "\t\t\t退出按b:>>>_\b"; cin >> chos;
			system("cls");
			mainScreen();
		}
		else
			if (chos == "B" || chos == "b")
			{
				system("cls");
				mainScreen();
			}
			else
			{
				cout << "输入错误~~~\a" << endl; Sleep(1000);
				system("cls");
				goScreen();
			}
	}
}


void iWatch::answerScreen()
{
	string ch;
	cout << "\t\t\t来电提醒"; Sleep(1000); cout << endl;
	cout << "\t\t\t※***************************※" << endl;
	cout << "\t\t\t※                           ※" << endl;
	cout << "\t\t\t※                           ※" << endl;
	cout << "\t\t\t※         未知联系人        ※" << endl;
	cout << "\t\t\t※                           ※" << endl;
	cout << "\t\t\t※                           ※" << endl;
	cout << "\t\t\t※        18540233309        ※" << endl;
	cout << "\t\t\t※                           ※" << endl;
	cout << "\t\t\t※                           ※" << endl;
	cout << "\t\t\t※                           ※" << endl;
	cout << "\t\t\t※           北京            ※" << endl;
	cout << "\t\t\t※                           ※" << endl;
	cout << "\t\t\t※                           ※" << endl;
	cout << "\t\t\t※            >>>>>          ※" << endl;
	cout << "\t\t\t※***************************※" << endl;
	PlaySound(TEXT("E:\\WAV\\Alarm01.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	cout << "接听请按a,挂断请按r:"; cin >> ch;
	if (ch == "A" || ch == "a")
	{
		PlaySound(NULL, NULL, SND_PURGE);
		cout << "通话中..." ; Sleep(5000);
		system("cls");
	}
	else
	{
		PlaySound(NULL, NULL, SND_PURGE);
		cout << "已挂断"; Sleep(1000);
		system("cls");
	}
}