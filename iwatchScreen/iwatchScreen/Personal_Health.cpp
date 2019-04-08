#include"Personal_Health.h"
#include<windows.h>
void Personal_Health::set()//录入个人信息
{
	cout << "电话号：";
	cin >> number;
	cout << "年龄: ";
	cin >> age;
	cout << "身高（m）:";
	cin >> height;
	cout << "体重（kg）:";
	cin >> weight;
}

void Personal_Health::display()         //显示个人信息
{
	//初始化个人信息
	Name = "Jack";
	workPlace = "SUT";
	number = "18996620875";
	email = "2410481664@qq.com";
	age = 20;
	height = 1.75;
	weight = 69;
	heart_rate = 75;
	blood_pressure = 110;
	BMI = (weight) / (height*height);      //BMI=体重/身高的平方
	
	cout << "\t\t\t----------------------------------" << endl;
	cout << "\t\t\t个人基本信息" << endl;
	cout << "\t\t\t----------------------------------" << endl;
	cout << "\t\t\t姓名：" << Name << endl;
	cout << "\t\t\t工作地点:" << workPlace << endl;
	cout << "\t\t\t电话号:" << number << endl;
	cout << "\t\t\temail:" << email << endl;
	cout << "\t\t\t年龄:" << age << endl;
	cout << "\t\t\t身高:" << height << endl;
	cout << "\t\t\t体重:" << weight << endl;
	cout << "\t\t\t心率:" << heart_rate << endl;
	cout << "\t\t\t血压:" << blood_pressure << endl;
	cout << "\t\t\tBMI:" << BMI << endl;
	cout << "\t\t\tYou are considered to be:" << category;
	if (BMI<18.5) {                           //判断bmi类型
		cout << "Underweight" << endl;
	}
	else if (BMI<23.9) {
		cout << "Normal" << category << endl;
	}
	else if (BMI<27.0) {
		cout << "Overweight" << category << endl;
	}
	else if (BMI<32.0) {
		cout << "Fat" << category << endl;
	}
	else {
		cout << "Obese" << category << endl;
	}
}
void Personal_Health::setHeartRate()    //求心率
{
	string S,ch;
	time_t t_start, t_end;
	cout << "\t\t\t跑步按r,散步按w:_\b"; cin >> ch;
	cout << endl;
	if (ch == "r")
	{
		t_start = time(NULL);
		cout << "\t\t\t按任意键模拟跑步，回车键结束：" << endl;
		cout << "\t\t\t...";
		cin >> S;
		cout << endl;
		t_end = time(NULL);
		double time = difftime(t_end, t_start);
		double coun = S.length();
		cout << "\t\t\t-------------------" << endl;
		cout << "\t\t\t步数：" << coun << endl;
		cout << "\t\t\t用时：" << time << "秒" << endl;
		heart_rate = (220 - age) + coun / (time / 60) * 0.25 - 100; //心率公式
		blood_pressure = blood_pressure + blood_pressure*0.15;
		cout << "\t\t\t心率为：" << heart_rate << "次/min" << endl;
		cout << "\t\t\t血压：" << (int)blood_pressure << "mmHg" << endl;
		cout << "\t\t\t-------------------" << endl;
	}
	else
		if (ch == "w")
		{
			t_start = time(NULL);
			cout << "\t\t\t按任意键模拟散步，回车键结束：" << endl;
			cout << "\t\t\t...";
			cin >> S;
			cout << endl;
			t_end = time(NULL);
			double time = difftime(t_end, t_start);
			double coun = S.length();
			cout << "\t\t\t-------------------" << endl;
			cout << "\t\t\t步数：" << coun << endl;
			cout << "\t\t\t用时：" << time << "秒" << endl;
			heart_rate = 1.25 * coun / (time / 60);
			blood_pressure = blood_pressure + blood_pressure*0.05;
			cout << "\t\t\t心率为：" << heart_rate << "次/min" << endl;
			cout << "\t\t\t血压：" << (int)blood_pressure << "mmHg" << endl;
			cout << "\t\t\t-------------------" << endl;
		}
		else
		{
			cout << "输入错误~~~\a" << endl; Sleep(1000);
			setHeartRate();
		}
	
}
