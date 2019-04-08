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
	Contancts conObj;//Contancts的一个对象
	Personal_Health person;
public:
	static int flag;//标记是否改过个人信息
	string name;
	string workPlace;
	string number;
	string email;
	iWatch();
	void lockScreen();
	void mainScreen();
	// 个人信息+修改
	void iwaScreen();
	//打电话功能块
	void phoneScreen();
	void contanct();//通讯录
	void answerScreen();
	//计步
	void goScreen();
};


