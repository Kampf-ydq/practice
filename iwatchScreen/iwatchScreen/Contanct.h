#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<windows.h>
using namespace std;

class iWatch;
//�ṹ�����Ķ���
struct information
{
	char no[5];
	char name[20];
	char address[100];
	char tel_no[12];
	char work_place[30];
	char e_mail[40];
	char type[10];
};

//class iWatch;
class Contancts
{
public:
	int i;////��ʹ��find��������������½Ǳ�
	information st[37];
	void add(char no[13], char name[20], char address[100], char tel_no[12], char work_place[30], char e_mail[40], char type[10]);
	void del(char name[20], Contancts&);
	int find1(char tel_no[13],int);
	int find2(char name[20]);
	void list(Contancts&);
	int correct(char name[20],Contancts&);
	void reda(int);
	void write();
	void format();//��ʼ������
	void format(Contancts&);//��ʽ������
	void liulan(char);//�ص�
	void print(int );
	int back();
	void  zhuyemian();

	void callScreen(Contancts&);
	void call();
};

