#pragma once
#include<iostream>

typedef struct Node
{
	Node *next;
	int data;
}Node;

class  linked_List
{
public:
	Node *head;
	linked_List():head(NULL){};
	~linked_List() {};
	int Length(Node *h);
	 void buildList(int n,int arr[]);//创建单链表
	 void printList(Node *pHead);//遍历
	 Node* Reverse(Node *front);//逆置
	 int Delete(int);//删除
	 void Insert(int x,Node *newHead);//插入
	 Node* Merge(Node *pHead1,Node *pHead2);//合并
//private:
	
};
