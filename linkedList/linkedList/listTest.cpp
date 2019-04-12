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
	cout << "\n*********************������Ļ���������*********************" << endl;
	cout << "��������" << N << "������: ";
	for (int i = 0; i < N; i++)
		cin >> a[i];

	//-----------------------------��1������������-------------------------------
	FirstList.buildList(N, a);
	cout << "	@you����������ɹ� " << endl;

	//-----------------------------��2������������-------------------------------
	cout << "-----------------------------------" << endl;
	FirstList.printList(FirstList.head); cout << "	@you����������ɹ�";
	cout << "\n-----------------------------------" << endl;

	//-----------------------------��3��ɾ����ż���ڵ�-------------------------------
	for (int i = 2; i <= N; i = i + 2) {
		FirstList.Delete(i);
	}
	Sleep(3000);
	FirstList.printList(FirstList.head);
	cout << "	@youɾ��ż���ڵ�ɹ� " << endl;
	cout << endl;

	//-----------------------------��4������-------------------------------
	linked_List ReverObj;
	int src[5] = { 10,6,3,9,5 };
	ReverObj.buildList(5, src);

	cout << "\n*********************������Ļ���������*********************" << endl;
	cout << "����ǰ����: ";
	ReverObj.printList(ReverObj.head);
	cout << endl;
	Node *pReve = ReverObj.Reverse(ReverObj.head);
	cout << "���ú�Ϊ: ";
	while (pReve->next != NULL)
	{
		cout << pReve->data << " ";
		pReve = pReve->next;
	}
	cout << "	@you��������ɹ� " << endl;

	//-----------------------��5���ڷǵݼ����������i������x������������-----------------------

	//----------------������һ���ǵݼ���������------------------
	linked_List SecondList;
	int Order_Asc_List[5] = { 4,9,12,15,18 };
	SecondList.buildList(5, Order_Asc_List);
	cout << "\n**********************���ϲ���������**********************" << endl;
	cout << "Order_Asc_List: ";
	SecondList.printList(SecondList.head);
	
	//--------------�����������в��룬ʹ��������-----------
	int InsertData;
	cout << "	����: "; cin >> InsertData;
	SecondList.Insert(InsertData, SecondList.head);

	//��ӡ���ĵ�������һ����������
	cout << "\n	The_Merge_First_List: ";
	SecondList.printList(SecondList.head);
	cout << "	@you�����������в���Ԫ�سɹ� " << endl;
	cout << endl;

	//-------------------��6������5���������������������Ǻϲ��ɷǵ�������---------------------
	
	//----------------�����ڶ����ǵݼ���������------------------
	linked_List ThirdList;
	int Order_Asc_Array[2] = { 5,9 };
	ThirdList.buildList(2, Order_Asc_Array);

	//��ӡ�ڶ�����������
	cout << "	The_Merge_Second_List: ";
	ThirdList.printList(ThirdList.head);
	cout << endl;

	//׼���ϲ�������������
	linked_List FourthList;
	FourthList.head = FourthList.Merge(SecondList.head, ThirdList.head);//�ϲ�����
	cout << "\n	===>>�ϲ���: ";

	//����ϲ��������
	Node* pMerge = FourthList.head;
	while (pMerge->next != NULL)
	{
		pMerge = pMerge->next;
		cout << pMerge->data << " ";
	}
	cout << "	@you�ϲ�������������ɹ�" << endl;
	cout << endl;

	return 0;
}