#include<iostream>

using namespace std;

void bubbleSort(int a[], int len)//ð������
{
	int tmp;
	for (int i = 1; i < len; i++)
		for (int j = 0; j < len - 1; j++) {
			if (a[j + 1] < a[j])
			{
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}

	cout << "\nBubble Sort����" << endl;
	for (int k = 0; k < len; k++) {
		cout << a[k] << " ";
	}
}

void InsertSort(int a[], int len)//��������
{
	int i, j;
	for (i = 2; i <= len; i++)
	{
		a[0] = a[i];//������Ԫ�ط����ڱ�λ��
		for (j = i - 1; a[0] < a[j]; j--)
		{
			a[j + 1] = a[j];
		}
		a[j + 1] = a[0];
	}
	
	cout << "Insertion Sort����" << endl;
	for (int k = 1; k <= len; k++) {
		cout << a[k] << " ";
	}
}

void SelectSort(int a[], int len)
{
	int index,tmp;
	int i, j;
	for (i = 0; i < len - 1; i++)
	{
		index = i;
		for (j = i + 1; j < len; j++)
			if (a[j] < a[index]) index = j;
		if (index != i)
		{
			tmp = a[i];
			a[i] = a[index];
			a[index] = tmp;
		}
	}

	cout << "\nSelect Sort����" << endl;
	for (int k = 0; k < len; k++) {
		cout << a[k] << " ";
	}
}


int main()
{
	system("color 2f");

	int a1[5] = { 4,6,9,2,1 };

	cout << "a1��ʼ˳��: ";
	for (int i = 0; i < 5; i++)
		cout << a1[i] << " ";
	bubbleSort(a1, 5);
	cout << endl << endl;

	int a2[5 + 1];
	a2[0] = 0;//�ڱ�λ��
	cout << "�����������������ݣ�5����: ";
	for (int k = 1; k <= 5; k++)
		cin >> a2[k];
	InsertSort(a2, 5);
	cout << endl << endl;

	int a3[5] = { 7,5,10,3,6 };
	cout << "a3��ʼ˳��: ";
	for (int i = 0; i < 5; i++)
		cout << a3[i] << " ";
	SelectSort(a3, 5);
	cout << endl << endl;

	return 0;
}