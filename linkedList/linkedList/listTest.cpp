#include"linkedList.h"
#include<iostream>
#include<WINDOWS.h>

#define N 5

using namespace std;

int main()
{
	system("color 6F");

	linked_List FirstList;
	int a[N];
	cout << "\n*********************【链表的基本操作】*********************" << endl;
	cout << "任意输入" << N << "个整数: ";
	for (int i = 0; i < N; i++)
		cin >> a[i];

	//-----------------------------【1】创建单链表-------------------------------
	FirstList.buildList(N, a);
	cout << "	@you创建单链表成功 " << endl;

	//-----------------------------【2】遍历单链表-------------------------------
	cout << "-----------------------------------" << endl;
	FirstList.printList(FirstList.head); cout << "	@you遍历单链表成功";
	cout << "\n-----------------------------------" << endl;

	//-----------------------------【3】删除第偶数节点-------------------------------
	for (int i = 2; i <= N; i = i + 2) {
		FirstList.Delete(i);
	}
	Sleep(3000);
	FirstList.printList(FirstList.head);
	cout << "	@you删除偶数节点成功 " << endl;
	cout << endl;

	//-----------------------------【4】逆置-------------------------------
	linked_List ReverObj;
	int src[5] = { 10,6,3,9,5 };
	ReverObj.buildList(5, src);

	cout << "\n*********************【链表的基本操作】*********************" << endl;
	cout << "逆置前链表: ";
	ReverObj.printList(ReverObj.head);
	cout << endl;
	Node *pReve = ReverObj.Reverse(ReverObj.head);
	cout << "逆置后为: ";
	while (pReve->next != NULL)
	{
		cout << pReve->data << " ";
		pReve = pReve->next;
	}
	cout << "	@you逆置链表成功 " << endl;

	//-----------------------【5】在非递减有序链表第i处插入x，是其仍有序-----------------------

	//----------------创建第一个非递减有序链表------------------
	linked_List SecondList;
	int Order_Asc_List[5] = { 4,9,12,15,18 };
	SecondList.buildList(5, Order_Asc_List);
	cout << "\n**********************【合并有序链表】**********************" << endl;
	cout << "Order_Asc_List: ";
	SecondList.printList(SecondList.head);
	
	//--------------在有序链表中插入，使其仍有序-----------
	int InsertData;
	cout << "	插入: "; cin >> InsertData;
	SecondList.Insert(InsertData, SecondList.head);

	//打印最后的单链表（第一个有序单链表）
	cout << "\n	The_Merge_First_List: ";
	SecondList.printList(SecondList.head);
	cout << "	@you在有序链表中插入元素成功 " << endl;
	cout << endl;

	//-------------------【6】利用5创建两个单链表，并将它们合并成非递增链表---------------------
	
	//----------------创建第二个非递减有序链表------------------
	linked_List ThirdList;
	int Order_Asc_Array[2] = { 5,9 };
	ThirdList.buildList(2, Order_Asc_Array);

	//打印第二个有序单链表
	cout << "	The_Merge_Second_List: ";
	ThirdList.printList(ThirdList.head);
	cout << endl;

	//准备合并两个有序单链表
	linked_List FourthList;
	FourthList.head = FourthList.Merge(SecondList.head, ThirdList.head);//合并操作
	cout << "\n	===>>合并后: ";

	//输出合并后的链表
	Node* pMerge = FourthList.head;
	while (pMerge->next != NULL)
	{
		pMerge = pMerge->next;
		cout << pMerge->data << " ";
	}
	cout << "	@you合并两个有序链表成功" << endl;
	cout << endl;

	return 0;
}