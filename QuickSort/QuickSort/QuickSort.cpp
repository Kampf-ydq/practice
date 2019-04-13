#include<iostream>
#include<math.h>
using namespace std;

#define N 5000


//************************����������л��֡�***********************
// ����: �㷨�ĺ��ģ������±�i��j,�ֱ�������������׼Ԫ��a[p]�Ƚ�
//       ���������򽻻�,����ʵ�ֲο����㷨��������ơ�
//
//***************************************************************
int Partition(int a[], int p, int r)
{
	int i = p, j = r + 1;//i��j��ֵ�������++i��--j������
	int temp = a[p];
	int t;

	while (true)
	{
		while (a[++i] < temp && i < r);//���i����,����������ʱStop,�õ�ֵi
		while (a[--j] > temp);//�ұ�j�Լ�,����������ʱStop,�õ�ֵj

		if (i >= j)//�˳�ѭ������
			break;

		//��i,j��ֹͣ����ʱ����a[i]��a[j]
		t = a[i];
		a[i] = a[j];
		a[j] = t;
	}

	//����a[j]��tempֵ
	a[p] = a[j];
	a[j] = temp;

	return j;
}

//***********************���ݹ���⡿*******************************
// ����: ���õݹ鷽ʽ�ֱ������������������������
//
//*****************************************************************
void Quick_Sort(int array[], int p, int r)
{
	if (p < r)//�Ϸ�����ʼ�����ֹ���±�
	{
		int q = Partition(array, p, r);//Ѱ�ҷָ��

		Quick_Sort(array, p, q);//����������
		Quick_Sort(array, q + 1, r);//���Ұ������
	}

}

int main()
{
	int Array[N];
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
			cin >> Array[i];

		//���ÿ��������㷨
		Quick_Sort(Array, 0, n - 1);

		for (int i = 0; i < n; i++)
			cout << Array[i] << " ";

		cout << endl;
	}
	return 0;
}


