#include<iostream>
#include"orderList.h"//����˳���ͷ�ļ�

using namespace std;

//������
void SeqList::buildList()
{
	cout << "(1)--Please input " << MaxSize << " elements (int): ";
	for (int i = 0; i < MaxSize; i++)
		cin >> array[i];
}

//��������
void SeqList::printList()
{
	cout << "(2)--the elements of array is: ";
	for (int i = 0; i < MaxSize; i++)
		cout << array[i] << " ";
	cout << endl;
}

//����Ԫ��
int SeqList::getElement(int i)
{
	for (int j = 0; j < MaxSize; j++)
	{
		if (array[i - 1] == array[j])
			return 1;
	}
	return 0;
}

//�ж��Ƿ�Գ�
int SeqList::IsSymmtri()
{
	int i = 0, j = MaxSize - 1;
	while (i != (MaxSize / 2))
	{
		if (array[i] == array[j])
		{
			i++;
			j--;
		}
		else
		{
			return 0;
		}
	}
	return 1;
}

//��������������ż��ǰ
void SeqList::orderList()
{
	int middle = MaxSize / 2;
	int i = 0, j = MaxSize - 1;
	int temp;
	while (i != middle)
	{
		if (array[i] % 2 == 0 && array[j] % 2 != 0)//array[i]Ϊż��array[i]Ϊ��
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
			j--;
		}else if (array[i] % 2 == 0 && array[j] % 2 == 0)//array[i]Ϊż��array[i]Ϊż
		{
			j--;
		}
		else if (array[i] % 2 != 0 && array[j] % 2 != 0)//array[i]Ϊ�棬array[i]Ϊ��
		{
			i++;
		}
		else if (array[i] % 2 != 0 && array[j] % 2 == 0)//array[i]Ϊ�棬array[i]Ϊż
		{
			i++;
			j--;
		}
	}

	//���
	for (int i = 0; i < MaxSize; i++)
		cout << array[i] << " ";
}

void SeqList::BubbleSort(int arr[],int l)
{
	int i, j, temp;
	for (i = 1; i < l; i++) {
		for (j = 0; j < l - i; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void SeqList::Sequence(int a[],int length)
{
	for (int i = 0; i < length; i++)
		cin >> a[i];

	//��������
	BubbleSort(a,length);
	cout << "	����: ";
	for (int i = 0; i < length; i++)
		cout<< a[i]<<" ";
}

//�ϲ����������
void SeqList::combineSeq()
{
	int i = 0, j = 0;
	int k = 0;//�ϲ���������±�
	while (i < len1 && j < len2)
	{
		if (arr1[i] <= arr2[j])
		{
			temp[k] = arr1[i];
			i++;
			k++;
		}
		else {
			temp[k] = arr2[j];
			j++;
			k++;
		}
	}

	if (i < len1)
		for (; i < len1; i++) {
			temp[k] = arr1[i];
			k++;
		}
	if (j < len2)
		for (; j < len2; j++) {
			temp[k] = arr2[j];
			k++;
		}

	for (int k = 0; k < len1 + len2; k++)
		cout << temp[k] << " ";
}