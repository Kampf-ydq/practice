#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
using namespace std;
class Person {
protected:
	string Name;
	string workPlace;
	string number;
	string email;
};
class Personal_Health : public Person {
private:
	int age;
	double weight;
	double height;
	double BMI;
	double heart_rate;
	double blood_pressure;
	string category;
public:
	void display();
	void set();
	void setHeartRate();
};

