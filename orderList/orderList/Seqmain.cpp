#include"orderList.h"
#include<iostream>

using namespace std;

int main()
{
	SeqList list;
	int index;
	
	//**************************************������*********************************************
	list.buildList();
	cout << endl;

	//********************************����������Ԫ�ز���ӡ��***************************************
	list.printList();
	cout << endl;

	//***********************************���ж��Ƿ�Գơ�*****************************************
	if (list.IsSymmtri())
		cout << "(3)--The array is symmtrical��" << endl;
	else
		cout << "(3)--The array isn't symmtrical��" << endl;

	//************************************������Ԫ�ء�********************************************
	cout << endl;
	cout << "(4)--Input the number what you want to get: ";
	cin >> index;
	if (list.getElement(index))
		cout << "   Select successfully !" << endl;
	else
		cout << "   No that element~~~!" << endl;

	//************************************��������ż��ǰ��*****************************************
	cout << endl;
	cout << "(5)--������ż��ǰ���˳��Ϊ: ";
	list.orderList();
	cout << endl;

	//***********************************���������������*****************************************
	cout << endl;
	cout << "(6)--������һ����("<<len1<<"����): ";
	list.Sequence(list.arr1,len1);
	cout << endl;

	cout << "     �����ڶ�����(" << len2 << "����): ";
	list.Sequence(list.arr2, len2);
	cout << endl;

	//***********************************���ϲ����������*****************************************
	cout << endl;
	cout << "(7)--�ϲ���ı�Ϊ������: ";
	list.combineSeq();
	cout << endl;

	return 0;
}