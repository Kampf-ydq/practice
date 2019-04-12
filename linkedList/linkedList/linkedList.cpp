#include"linkedList.h"

using namespace std;

int linked_List::Length(Node *h)
{
	Node *p = new Node();//建立一个滑动指针
	int count = 0;//声明计数变量
	p = h->next;
	while (p != NULL)
	{
		p = p->next;
		count++;
	}

	return count;
}

//创建单链表
void linked_List::buildList(int n, int arr[])
{
	head = new Node();//生成头结点
	Node *r = new Node();
	r = head;//尾指针初始化

	for (int i = 0; i < n; i++)
	{
		Node *s = new Node();
		s->data = arr[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
}

void linked_List::printList(Node *pHead)
{
	Node *p = new Node();//建立一个滑动指针
	p = pHead->next;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
}

Node* linked_List::Reverse(Node *front)
{
	if (front == NULL || front->next == NULL)//判断单链表的节点个数
		return front;

	Node *ReverseList = NULL;//创建逆置头结点
	Node *CurrPoint = front;//创建滑动指针

	//**********************【将n个元素逆置】**************************
	while (CurrPoint != NULL)
	{
		Node *TempPoint = CurrPoint;
		CurrPoint = CurrPoint->next;//滑动指针向前滑动
		TempPoint->next = ReverseList;
		ReverseList = TempPoint;//把当前指针放入到逆置链中
	}

	
	return ReverseList;//返回逆置链表头节点
}

int linked_List::Delete(int i)
{
	Node *p = head;
	int count = 0;
	while (p != NULL && count < i - 1)//查找第i - 1个节点
	{
		p = p->next;
		count++;
	}

	if (p == NULL || p->next == NULL)//节点p不存在或者p的后继节点不存在
		cout << "所删之数不存在^_^~~" << endl;
	else
	{
		//*******************【暂存被删节点】**********************
		Node *q = new Node();
		int x;
		q = p->next;
		x = q->data;

		//删除
		p->next = q->next;
		delete q;
		return x;
	}
}

//插入
void linked_List::Insert(int x, Node *newHead)
{
	Node *pSortOrder = newHead;
	Node *s = new Node();
	s->data = x;
	
	//if(pSortOrder == NULL)

	while (pSortOrder->next != NULL)
	{
		pSortOrder = pSortOrder->next;

		if (pSortOrder->next != NULL)
		{
			//-------<1>在第一个节点之前插入-------------
			if (pSortOrder->data > x) {
				s->next = pSortOrder;
				newHead->next = s;
				break;//位置已找到，跳出循环
			}

			//-------<2>一般情况------------------------
			if (pSortOrder->data <= x && x <= pSortOrder->next->data) {
				s->next = pSortOrder->next;
				pSortOrder->next = s;
				break;//位置已找到，跳出循环
			}
		 }

		//--------<3>在最后一个节点之后插入-----------
		else 
		{
			s->next = NULL;
			pSortOrder->next = s;
			break;//位置已找到，跳出循环
		}
	}
}

//合并---->非递增链表
Node* linked_List::Merge(Node *pHead1, Node *pHead2)
{
	//创建新链表的前2个结点
	Node *Merge_Head_List = new Node();
	Node *Merge_Tail_List = new Node();
	Merge_Head_List->next = Merge_Tail_List;
	Merge_Tail_List->data = pHead1->next->data;//将第一个链表的第一个节点元素复制给新链表的第一个节点元素
	//创建工作指针
	Node *p1 = pHead1->next->next;
	Node *p2 = pHead2->next;

	while (p1 != NULL && p2 != NULL)
	{
		if (p1->data >= p2->data)
		{
			Insert(p1->data, Merge_Head_List);//加入到合并链表中
			p1 = p1->next;
		}
		else
		{
			Insert(p2->data, Merge_Head_List);
			p2 = p2->next;
		}
		
	}
	if (p1 != NULL) {
		while (p1 != NULL)
		{
			Insert(p1->data, Merge_Head_List);
			p1 = p1->next;
		}
	}
   
	if (p2 != NULL) {
		while (p2 != NULL)
		{
			Insert(p2->data, Merge_Head_List);
			p2 = p2->next;
		}
	}

	return Merge_Head_List;
}