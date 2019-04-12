#pragma once
#include<iostream>
#include<string>

using namespace std;

class stackOperate
{
public:
	stackOperate() { topc = -1; topd = -1; };
	~stackOperate(){};

	//bool isNumber(char s);//判断当前字符是否是数字

	void pushd(int x);//操作数进栈
	void pushc(char x);//操作符进栈

	int popd();//操作数出栈
	char popc();//操作符出栈

	void empty();//操作数和操作符栈同时清空
	int isEmpty();//栈空返回0，否则返回1

	int icp(char cc);//操作符栈外优先级
	int isp(char cs);//操作符栈内优先级

	void postfix();//中缀表达式转换为后缀表达式,并存放在char post[50]
	void calculate();//后缀表达式求值并输出结果
private:
	char optr[50];//操作符栈
	int opnd[50];//操作数及运算结果栈
	char post[50];//存放后缀表达式
	int topc;//操作符栈栈顶
	int topd;//操作数栈栈顶
};

/**
 * 判断当前字符是否是数字
 */
//bool stackOperate::isNumber(char s)
//{
//	string operates = "+-*/()";
//	for (int i = 0; i < operates.length(); i++) {
//		if(s == oper)
//	}
//}
//操作数、操作符进栈
void stackOperate::pushd(int x)
{
	topd++;
	opnd[topd] = x;
}
void stackOperate::pushc(char c)
{
	topc++;
	optr[topc] = c;
}

//操作数、操作符出栈
int stackOperate::popd()
{
	int d;
	d = opnd[topd];
	topd--;
	return d;
}
char stackOperate::popc()
{
	char c;
	c = optr[topc];
	topc--;
	return c;
}

void stackOperate::empty()
{
	topc = -1;
	topd = -1;
}

int stackOperate::isEmpty()
{
	if (topc == -1)
		return 0;
	else
		return 1;
}
//操作符栈外、栈内优先级
int stackOperate::icp(char cc)
{
	int level;
	switch (cc)
	{
	case '#':level = 0; break;
	case'(':level = 8; break;
	case'*':
	case'/':level = 4; break;
	case'+':
	case'-':level = 2; break;
	case')':level = 1; break;
	}
	return level;
}
int stackOperate::isp(char cs)
{
	int level;
	switch (cs)
	{
	case '#':level = 0; break;
	case'(':level = 1; break;
	case'*':
	case'/':level = 5; break;
	case'+':
	case'-':level = 3; break;
	case')':level = 8; break;
	}
	return level;
}

//中缀表达式转换为后缀表达式,并存放在char post[50]
void stackOperate::postfix()
{
	char ch, y;
	int i = 0;
	pushc('#');//栈底放#
	cout << "输入表达式,并以#结尾: ";
	while ((ch = getchar()) && ch!='#')
	{
		if(ch >= '0' && ch <= '9'){//判定为操作数,入栈
			post[i] = ch;
			i++;
		}
		else
		{
			if (ch == ' ') {//遇到空格
				continue;
			}
			if (ch == ')') {//遇到右括号，元素出栈直至左括号
				for (y = popc(); y != '('; y = popc()) {
					post[i] = y;
					i++;
				}
			}
			else//判定为操作符，与栈顶操作符判断优先级
			{
				for (y = popc();isp(y) > icp(ch); y = popc()){
					post[i] = y;
					i++;
				}
				pushc(y);//刚出栈的y再进栈
				pushc(ch);
			}
		}
	}
	while (isEmpty() != 0)
	{  //栈中剩余元素输出到post字符数组
		y = popc(); post[i] = y; i++;
	}
}

//后缀表达式求值，最后字符为#
void stackOperate::calculate()
{
	int i = 0;
	int l, r, n;
	while (post[i] != '#')
	{
		if (post[i] >= '0' && post[i] <= '9')//操作数
		{
			pushd((int)(post[i] - '0'));
			i++;
		}
		else
		{
			r = popd();
			l = popd();

			switch (post[i])
			{
			case'+':n = l + r; break;
			case'-':n = l - r; break;
			case'*':n = l*r; break;
			case'/':n = l / r; break;
			}

			pushd(n);
			i++;
		}
	}

	n = popd();//最终的计算结果
	cout << "表达式的结果为: " << n << endl;
}