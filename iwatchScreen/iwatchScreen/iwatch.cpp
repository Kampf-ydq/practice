#include"iWatch.h"
#include<stdlib.h>
#include<time.h>
#include  <windows.h> 
#include  <iostream> 
#include "mmsystem.h"//��������ͷ�ļ�
#pragma comment(lib,"winmm.lib")//��������ͷ�ļ���

int iWatch::flag = 0;
iWatch::iWatch()  { }
void iWatch::lockScreen()
{
	//��ȡϵͳ���ڡ�ʱ��
	SYSTEMTIME systemTime;
	GetLocalTime(&systemTime);
  
	//��ʱ�����绰
	srand((unsigned)time(NULL));//��ʼ���������
	int a = rand() % (5 - 1);
	if (a == 2)
		answerScreen();

	string lockKey;//����������
	cout << "\t\t��******************************************************************��" << endl;
	cout << "\t\t��     "<< systemTime.wHour<<":"<< systemTime.wMinute
		 <<"                                             ���� >      ��" << endl;
	cout << "\t\t��   "<< systemTime.wYear<<"/"<< systemTime.wMonth<<"/"<< systemTime.wDay
		 <<"                                                      ��" << endl
		<< "\t\t��                                                                  ��" << endl
		<< "\t\t��                            iWatch                                �� " << endl
		<< "\t\t��                                                                  �� " << endl
		<< "\t\t��                                                                  ��" << endl
		<< "\t\t��                     Input the following word                     ��" << endl                      
		<< "\t\t��                                                                  ��" << endl
		<< "\t\t��                                                                  ��" << endl
		<< "\t\t��                         >>Unlock(����)                           ��" << endl
		<< "\t\t��                                                                  ��" << endl
		<< "\t\t��                                                                  ��" << endl
		<< "\t\t��                         >>Over(�˳�����)                         ��" << endl
		<< "\t\t��                                                                  ��" << endl
		<< "\t\t��                                                    2017/12/24    ��" << endl
		<< "\t\t��******************************************************************��" << endl;
	cout << "\t\t>>>"; cin >> lockKey; 
	PlaySound(TEXT("E:\\WAV\\Ringout4.wav"), NULL, SND_FILENAME | SND_ASYNC);
	if (lockKey == "Unlock")
	{
		system("cls"); mainScreen();
	}
	else
		if (lockKey == "Over")
		{
			system("cls"); cout << "ллʹ��"; exit(0);
		}
		else
		{
			cout << "�������,error~~~\a" << endl; Sleep(1000);
			system("cls");
			lockScreen();
		}
}

void iWatch::mainScreen()
{
	srand((unsigned)time(NULL));//��ʼ���������
	int a = rand() % (5 - 1);
	if (a == 2)
		answerScreen();


	int AppKey;//����ѡ���
	cout << "\t\t��******************************************************************��" << endl;
	cout << "\t\t��                                                                  ��" << endl;
	cout << "\t\t��               ��1�����ֱ�                ��2���绰               ��" << endl
		<< "\t\t��                                                                  ��" << endl
		<< "\t\t��                                                                  �� " << endl
		<< "\t\t��               ��3���Ʋ���                ��0������               �� " << endl
		<< "\t\t��                                                                  ��" << endl
		<< "\t\t��                                                                  ��" << endl
		<< "\t\t��                    Input the number(0,1,2,3)                     ��" << endl
		<< "\t\t��                                                                  ��" << endl
		<< "\t\t��                                                                  ��" << endl
		<< "\t\t��                         to choose function                       ��" << endl
		<< "\t\t��                                                                  ��" << endl
		<< "\t\t��                              >>>>>                               ��" << endl
		<< "\t\t��                                                                  ��" << endl
		<< "\t\t��                                                    2017/12/24    ��" << endl
		<< "\t\t��******************************************************************��" << endl;
	cout << "\t\t>>>"; cin >> AppKey;
	PlaySound(TEXT("E:\\WAV\\Ringout3.wav"), NULL, SND_FILENAME | SND_ASYNC);
	switch (AppKey)
	{
	case 0:system("cls"); lockScreen(); break;
	case 1:system("cls"); iwaScreen(); break;
	case 2:system("cls"); phoneScreen(); break;
	case 3:system("cls"); goScreen(); break;
	default: cout << "�˹�����δ��ͨ" << endl;
		mainScreen();
		break;
	}
}

//iWatch����ģ��
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
	cout << "\t\t�޸ĸ�����Ϣ---rewrite,����������---main" << endl<<endl;
	cout << "\t\t>>>"; cin >> Key1; 
	PlaySound(TEXT("E:\\WAV\\Ringout3.wav"), NULL, SND_FILENAME | SND_ASYNC);
	cout << endl;
	if (Key1 == "rewrite")
	{
		name = setName();
		workPlace = setWorkplace();
		number = setNumber();
		email = setEmail();
		cout << "\t\t�޸����" << endl;
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
			cout << "\t\t�������,error~~~\a" << endl; Sleep(2000);
			system("cls");
			mainScreen();
		}
}



//phone����ģ��
void iWatch::phoneScreen()
{
	srand((unsigned)time(NULL));//��ʼ���������
	int a = rand() % (5 - 1);
	if (a == 2)
		answerScreen();

	int Key2;
	cout << "\t\t��******************************************************************��" << endl;
	cout << "\t\t��                                                                  ��" << endl;
	cout << "\t\t��               ��1����绰                  ��2��ͨѶ¼           ��" << endl
		<< "\t\t��                                                                  ��" << endl
		<< "\t\t��                                                                  �� " << endl
		<< "\t\t��               ��3������                    ��0������             �� " << endl
		<< "\t\t��                                                                  ��" << endl
		<< "\t\t��                                                                  ��" << endl
		<< "\t\t��                    Input the number(0,1,2,3)                     ��" << endl
		<< "\t\t��                                                                  ��" << endl
		<< "\t\t��                                                                  ��" << endl
		<< "\t\t��                         to choose function                       ��" << endl
		<< "\t\t��                                                                  ��" << endl
		<< "\t\t��                              >>>>>                               ��" << endl
		<< "\t\t��                                                                  ��" << endl
		<< "\t\t��                                                    2017/12/24    ��" << endl
		<< "\t\t��******************************************************************��" << endl;
	cout << "\t\t>>>"; cin >> Key2; 
	PlaySound(TEXT("E:\\WAV\\Ringout3.wav"), NULL, SND_FILENAME | SND_ASYNC);
	switch (Key2)
	{
	case 0:system("cls"); lockScreen(); break;
	case 1:system("cls"); conObj.call(); phoneScreen(); break;
	case 2:system("cls"); contanct(); phoneScreen(); break;
	case 3:
		system("cls"); mainScreen(); break;
	default:cout << "\t\t�������,error~~~\a" << endl;
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
	srand((unsigned)time(NULL));//��ʼ���������
	string chos;
	int p;
	//��ʾ������Ϣ
	person.display();
	cout << "\t\t\t�޸ĸ�����Ϣ������1,���������������: "; cin >> p;
	if (p == 1)
	{
		person.set();
		cout << "\t\t\t�޸ĳɹ�����"; Sleep(2000); system("cls"); mainScreen();
	}
	else 
	{
		cout << "\t\t\t\t��������iWatch�Ʋ�..."; Sleep(3000);
		system("cls");
		//�Ʋ�
		cout << "\t\t\t------------------------------------" << endl;
		cout << "\t\t\tiWatch�Ʋ�" << endl;
		cout << "\t\t\t------------------------------------" << endl;
		cout << "\t\t\t\t   *********   " << endl;
		cout << "\t\t\t\t *           * " << endl;
		cout << "\t\t\t\t*             *" << endl;
		cout << "\t\t\t\t*    Start    *    ��������" << endl;
		cout << "\t\t\t\t*             *       " << rand() % (100 - 1) << endl;//������1~100
		cout << "\t\t\t\t *           * " << endl;
		cout << "\t\t\t\t   *********   " << endl;
		cout << "\t\t\t\t  ��5000����" << endl;
		cout << endl << endl;
		cout << "\t\t\t��s��ʼ���˳���b:_\b"; cin >> chos;
		cout << endl;
		if (chos == "S" || chos == "s")
		{
			person.setHeartRate();
			cout << "\t\t\t                          @CopyRight" << endl;
			cout << "\t\t\t------------------------------------" << endl;
			cout << "\t\t\t------------------------------------" << endl;
			cout << "\t\t\t�˳���b:>>>_\b"; cin >> chos;
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
				cout << "�������~~~\a" << endl; Sleep(1000);
				system("cls");
				goScreen();
			}
	}
}


void iWatch::answerScreen()
{
	string ch;
	cout << "\t\t\t��������"; Sleep(1000); cout << endl;
	cout << "\t\t\t��***************************��" << endl;
	cout << "\t\t\t��                           ��" << endl;
	cout << "\t\t\t��                           ��" << endl;
	cout << "\t\t\t��         δ֪��ϵ��        ��" << endl;
	cout << "\t\t\t��                           ��" << endl;
	cout << "\t\t\t��                           ��" << endl;
	cout << "\t\t\t��        18540233309        ��" << endl;
	cout << "\t\t\t��                           ��" << endl;
	cout << "\t\t\t��                           ��" << endl;
	cout << "\t\t\t��                           ��" << endl;
	cout << "\t\t\t��           ����            ��" << endl;
	cout << "\t\t\t��                           ��" << endl;
	cout << "\t\t\t��                           ��" << endl;
	cout << "\t\t\t��            >>>>>          ��" << endl;
	cout << "\t\t\t��***************************��" << endl;
	PlaySound(TEXT("E:\\WAV\\Alarm01.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	cout << "�����밴a,�Ҷ��밴r:"; cin >> ch;
	if (ch == "A" || ch == "a")
	{
		PlaySound(NULL, NULL, SND_PURGE);
		cout << "ͨ����..." ; Sleep(5000);
		system("cls");
	}
	else
	{
		PlaySound(NULL, NULL, SND_PURGE);
		cout << "�ѹҶ�"; Sleep(1000);
		system("cls");
	}
}