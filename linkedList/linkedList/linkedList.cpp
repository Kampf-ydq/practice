#include"linkedList.h"

using namespace std;

int linked_List::Length(Node *h)
{
	Node *p = new Node();//����һ������ָ��
	int count = 0;//������������
	p = h->next;
	while (p != NULL)
	{
		p = p->next;
		count++;
	}

	return count;
}

//����������
void linked_List::buildList(int n, int arr[])
{
	head = new Node();//����ͷ���
	Node *r = new Node();
	r = head;//βָ���ʼ��

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
	Node *p = new Node();//����һ������ָ��
	p = pHead->next;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
}

Node* linked_List::Reverse(Node *front)
{
	if (front == NULL || front->next == NULL)//�жϵ�����Ľڵ����
		return front;

	Node *ReverseList = NULL;//��������ͷ���
	Node *CurrPoint = front;//��������ָ��

	//**********************����n��Ԫ�����á�**************************
	while (CurrPoint != NULL)
	{
		Node *TempPoint = CurrPoint;
		CurrPoint = CurrPoint->next;//����ָ����ǰ����
		TempPoint->next = ReverseList;
		ReverseList = TempPoint;//�ѵ�ǰָ����뵽��������
	}

	
	return ReverseList;//������������ͷ�ڵ�
}

int linked_List::Delete(int i)
{
	Node *p = head;
	int count = 0;
	while (p != NULL && count < i - 1)//���ҵ�i - 1���ڵ�
	{
		p = p->next;
		count++;
	}

	if (p == NULL || p->next == NULL)//�ڵ�p�����ڻ���p�ĺ�̽ڵ㲻����
		cout << "��ɾ֮��������^_^~~" << endl;
	else
	{
		//*******************���ݴ汻ɾ�ڵ㡿**********************
		Node *q = new Node();
		int x;
		q = p->next;
		x = q->data;

		//ɾ��
		p->next = q->next;
		delete q;
		return x;
	}
}

//����
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
			//-------<1>�ڵ�һ���ڵ�֮ǰ����-------------
			if (pSortOrder->data > x) {
				s->next = pSortOrder;
				newHead->next = s;
				break;//λ�����ҵ�������ѭ��
			}

			//-------<2>һ�����------------------------
			if (pSortOrder->data <= x && x <= pSortOrder->next->data) {
				s->next = pSortOrder->next;
				pSortOrder->next = s;
				break;//λ�����ҵ�������ѭ��
			}
		 }

		//--------<3>�����һ���ڵ�֮�����-----------
		else 
		{
			s->next = NULL;
			pSortOrder->next = s;
			break;//λ�����ҵ�������ѭ��
		}
	}
}

//�ϲ�---->�ǵ�������
Node* linked_List::Merge(Node *pHead1, Node *pHead2)
{
	//�����������ǰ2�����
	Node *Merge_Head_List = new Node();
	Node *Merge_Tail_List = new Node();
	Merge_Head_List->next = Merge_Tail_List;
	Merge_Tail_List->data = pHead1->next->data;//����һ������ĵ�һ���ڵ�Ԫ�ظ��Ƹ�������ĵ�һ���ڵ�Ԫ��
	//��������ָ��
	Node *p1 = pHead1->next->next;
	Node *p2 = pHead2->next;

	while (p1 != NULL && p2 != NULL)
	{
		if (p1->data >= p2->data)
		{
			Insert(p1->data, Merge_Head_List);//���뵽�ϲ�������
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