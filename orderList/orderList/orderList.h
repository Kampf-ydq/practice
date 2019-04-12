#pragma once

#define MaxSize 5
#define len1 5
#define len2 7

class SeqList
{
public:
	int arr1[len1], arr2[len2];
	int temp[len1 + len2];
	SeqList() {};//无参构造
	~SeqList() {};
	void buildList();//建表
	void printList();//遍历操作
	int getElement(int i);//查找元素,查找成功返回1，否则返回0
	int IsSymmtri();//判断是否对称，对称返回1，否则返回0
	void orderList();//将表中奇数排在偶数前

	void Sequence(int a[],int length);//建立有序表，非递减
	void BubbleSort(int arr[],int l);//冒泡排序
	void combineSeq();//合并两个有序表
private:
	int array[MaxSize];
};
