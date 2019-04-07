#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<windows.h>
using namespace std;

class iWatch;
//结构体和类的定义
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
	int i;////在使用find函数后，用来存放下角标
	information st[37];
	void add(char no[13], char name[20], char address[100], char tel_no[12], char work_place[30], char e_mail[40], char type[10]);
	void del(char name[20], Contancts&);
	int find1(char tel_no[13],int);
	int find2(char name[20]);
	void list(Contancts&);
	int correct(char name[20],Contancts&);
	void reda(int);
	void write();
	void format();//初始化函数
	void format(Contancts&);//格式化函数
	void liulan(char);//重点
	void print(int );
	int back();
	void  zhuyemian();

	void callScreen(Contancts&);
	void call();
};

