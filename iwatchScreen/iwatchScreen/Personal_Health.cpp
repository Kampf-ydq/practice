#include"Personal_Health.h"
#include<windows.h>
void Personal_Health::set()//¼�������Ϣ
{
	cout << "�绰�ţ�";
	cin >> number;
	cout << "����: ";
	cin >> age;
	cout << "��ߣ�m��:";
	cin >> height;
	cout << "���أ�kg��:";
	cin >> weight;
}

void Personal_Health::display()         //��ʾ������Ϣ
{
	//��ʼ��������Ϣ
	Name = "Jack";
	workPlace = "SUT";
	number = "18996620875";
	email = "2410481664@qq.com";
	age = 20;
	height = 1.75;
	weight = 69;
	heart_rate = 75;
	blood_pressure = 110;
	BMI = (weight) / (height*height);      //BMI=����/��ߵ�ƽ��
	
	cout << "\t\t\t----------------------------------" << endl;
	cout << "\t\t\t���˻�����Ϣ" << endl;
	cout << "\t\t\t----------------------------------" << endl;
	cout << "\t\t\t������" << Name << endl;
	cout << "\t\t\t�����ص�:" << workPlace << endl;
	cout << "\t\t\t�绰��:" << number << endl;
	cout << "\t\t\temail:" << email << endl;
	cout << "\t\t\t����:" << age << endl;
	cout << "\t\t\t���:" << height << endl;
	cout << "\t\t\t����:" << weight << endl;
	cout << "\t\t\t����:" << heart_rate << endl;
	cout << "\t\t\tѪѹ:" << blood_pressure << endl;
	cout << "\t\t\tBMI:" << BMI << endl;
	cout << "\t\t\tYou are considered to be:" << category;
	if (BMI<18.5) {                           //�ж�bmi����
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
void Personal_Health::setHeartRate()    //������
{
	string S,ch;
	time_t t_start, t_end;
	cout << "\t\t\t�ܲ���r,ɢ����w:_\b"; cin >> ch;
	cout << endl;
	if (ch == "r")
	{
		t_start = time(NULL);
		cout << "\t\t\t�������ģ���ܲ����س���������" << endl;
		cout << "\t\t\t...";
		cin >> S;
		cout << endl;
		t_end = time(NULL);
		double time = difftime(t_end, t_start);
		double coun = S.length();
		cout << "\t\t\t-------------------" << endl;
		cout << "\t\t\t������" << coun << endl;
		cout << "\t\t\t��ʱ��" << time << "��" << endl;
		heart_rate = (220 - age) + coun / (time / 60) * 0.25 - 100; //���ʹ�ʽ
		blood_pressure = blood_pressure + blood_pressure*0.15;
		cout << "\t\t\t����Ϊ��" << heart_rate << "��/min" << endl;
		cout << "\t\t\tѪѹ��" << (int)blood_pressure << "mmHg" << endl;
		cout << "\t\t\t-------------------" << endl;
	}
	else
		if (ch == "w")
		{
			t_start = time(NULL);
			cout << "\t\t\t�������ģ��ɢ�����س���������" << endl;
			cout << "\t\t\t...";
			cin >> S;
			cout << endl;
			t_end = time(NULL);
			double time = difftime(t_end, t_start);
			double coun = S.length();
			cout << "\t\t\t-------------------" << endl;
			cout << "\t\t\t������" << coun << endl;
			cout << "\t\t\t��ʱ��" << time << "��" << endl;
			heart_rate = 1.25 * coun / (time / 60);
			blood_pressure = blood_pressure + blood_pressure*0.05;
			cout << "\t\t\t����Ϊ��" << heart_rate << "��/min" << endl;
			cout << "\t\t\tѪѹ��" << (int)blood_pressure << "mmHg" << endl;
			cout << "\t\t\t-------------------" << endl;
		}
		else
		{
			cout << "�������~~~\a" << endl; Sleep(1000);
			setHeartRate();
		}
	
}
