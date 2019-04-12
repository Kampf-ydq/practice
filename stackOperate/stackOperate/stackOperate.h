#pragma once
#include<iostream>
#include<string>

using namespace std;

class stackOperate
{
public:
	stackOperate() { topc = -1; topd = -1; };
	~stackOperate(){};

	//bool isNumber(char s);//�жϵ�ǰ�ַ��Ƿ�������

	void pushd(int x);//��������ջ
	void pushc(char x);//��������ջ

	int popd();//��������ջ
	char popc();//��������ջ

	void empty();//�������Ͳ�����ջͬʱ���
	int isEmpty();//ջ�շ���0�����򷵻�1

	int icp(char cc);//������ջ�����ȼ�
	int isp(char cs);//������ջ�����ȼ�

	void postfix();//��׺���ʽת��Ϊ��׺���ʽ,�������char post[50]
	void calculate();//��׺���ʽ��ֵ��������
private:
	char optr[50];//������ջ
	int opnd[50];//��������������ջ
	char post[50];//��ź�׺���ʽ
	int topc;//������ջջ��
	int topd;//������ջջ��
};

/**
 * �жϵ�ǰ�ַ��Ƿ�������
 */
//bool stackOperate::isNumber(char s)
//{
//	string operates = "+-*/()";
//	for (int i = 0; i < operates.length(); i++) {
//		if(s == oper)
//	}
//}
//����������������ջ
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

//����������������ջ
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
//������ջ�⡢ջ�����ȼ�
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

//��׺���ʽת��Ϊ��׺���ʽ,�������char post[50]
void stackOperate::postfix()
{
	char ch, y;
	int i = 0;
	pushc('#');//ջ�׷�#
	cout << "������ʽ,����#��β: ";
	while ((ch = getchar()) && ch!='#')
	{
		if(ch >= '0' && ch <= '9'){//�ж�Ϊ������,��ջ
			post[i] = ch;
			i++;
		}
		else
		{
			if (ch == ' ') {//�����ո�
				continue;
			}
			if (ch == ')') {//���������ţ�Ԫ�س�ջֱ��������
				for (y = popc(); y != '('; y = popc()) {
					post[i] = y;
					i++;
				}
			}
			else//�ж�Ϊ����������ջ���������ж����ȼ�
			{
				for (y = popc();isp(y) > icp(ch); y = popc()){
					post[i] = y;
					i++;
				}
				pushc(y);//�ճ�ջ��y�ٽ�ջ
				pushc(ch);
			}
		}
	}
	while (isEmpty() != 0)
	{  //ջ��ʣ��Ԫ�������post�ַ�����
		y = popc(); post[i] = y; i++;
	}
}

//��׺���ʽ��ֵ������ַ�Ϊ#
void stackOperate::calculate()
{
	int i = 0;
	int l, r, n;
	while (post[i] != '#')
	{
		if (post[i] >= '0' && post[i] <= '9')//������
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

	n = popd();//���յļ�����
	cout << "���ʽ�Ľ��Ϊ: " << n << endl;
}