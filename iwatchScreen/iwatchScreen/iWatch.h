#pragma once
#include"Contanct.h"
#include"Personal_Health.h"
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<windows.h>
using namespace std;


class iWatch {
private:
	string setName();
	string setWorkplace();
	string setNumber();
	string setEmail();
	Contancts conObj;//Contancts��һ������
	Personal_Health person;
public:
	static int flag;//����Ƿ�Ĺ�������Ϣ
	string name;
	string workPlace;
	string number;
	string email;
	iWatch();
	void lockScreen();
	void mainScreen();
	// ������Ϣ+�޸�
	void iwaScreen();
	//��绰���ܿ�
	void phoneScreen();
	void contanct();//ͨѶ¼
	void answerScreen();
	//�Ʋ�
	void goScreen();
};


