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
	 void buildList(int n,int arr[]);//����������
	 void printList(Node *pHead);//����
	 Node* Reverse(Node *front);//����
	 int Delete(int);//ɾ��
	 void Insert(int x,Node *newHead);//����
	 Node* Merge(Node *pHead1,Node *pHead2);//�ϲ�
//private:
	
};
