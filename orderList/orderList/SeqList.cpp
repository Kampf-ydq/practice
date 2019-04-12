#include<iostream>
#include"orderList.h"//包含顺序表头文件

using namespace std;

//建表函数
void SeqList::buildList()
{
	cout << "(1)--Please input " << MaxSize << " elements (int): ";
	for (int i = 0; i < MaxSize; i++)
		cin >> array[i];
}

//遍历操作
void SeqList::printList()
{
	cout << "(2)--the elements of array is: ";
	for (int i = 0; i < MaxSize; i++)
		cout << array[i] << " ";
	cout << endl;
}

//查找元素
int SeqList::getElement(int i)
{
	for (int j = 0; j < MaxSize; j++)
	{
		if (array[i - 1] == array[j])
			return 1;
	}
	return 0;
}

//判断是否对称
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

//将表中奇数排在偶数前
void SeqList::orderList()
{
	int middle = MaxSize / 2;
	int i = 0, j = MaxSize - 1;
	int temp;
	while (i != middle)
	{
		if (array[i] % 2 == 0 && array[j] % 2 != 0)//array[i]为偶，array[i]为奇
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
			j--;
		}else if (array[i] % 2 == 0 && array[j] % 2 == 0)//array[i]为偶，array[i]为偶
		{
			j--;
		}
		else if (array[i] % 2 != 0 && array[j] % 2 != 0)//array[i]为奇，array[i]为奇
		{
			i++;
		}
		else if (array[i] % 2 != 0 && array[j] % 2 == 0)//array[i]为奇，array[i]为偶
		{
			i++;
			j--;
		}
	}

	//输出
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

	//升序排列
	BubbleSort(a,length);
	cout << "	升序: ";
	for (int i = 0; i < length; i++)
		cout<< a[i]<<" ";
}

//合并两个升序表
void SeqList::combineSeq()
{
	int i = 0, j = 0;
	int k = 0;//合并后的数组下标
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