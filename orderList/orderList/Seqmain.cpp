#include"orderList.h"
#include<iostream>

using namespace std;

int main()
{
	SeqList list;
	int index;
	
	//**************************************【建表】*********************************************
	list.buildList();
	cout << endl;

	//********************************【遍历表中元素并打印】***************************************
	list.printList();
	cout << endl;

	//***********************************【判断是否对称】*****************************************
	if (list.IsSymmtri())
		cout << "(3)--The array is symmtrical！" << endl;
	else
		cout << "(3)--The array isn't symmtrical！" << endl;

	//************************************【查找元素】********************************************
	cout << endl;
	cout << "(4)--Input the number what you want to get: ";
	cin >> index;
	if (list.getElement(index))
		cout << "   Select successfully !" << endl;
	else
		cout << "   No that element~~~!" << endl;

	//************************************【奇数放偶数前】*****************************************
	cout << endl;
	cout << "(5)--奇数放偶数前后的顺序为: ";
	list.orderList();
	cout << endl;

	//***********************************【建立两个升序表】*****************************************
	cout << endl;
	cout << "(6)--创建第一个表("<<len1<<"个数): ";
	list.Sequence(list.arr1,len1);
	cout << endl;

	cout << "     创建第二个表(" << len2 << "个数): ";
	list.Sequence(list.arr2, len2);
	cout << endl;

	//***********************************【合并两个升序表】*****************************************
	cout << endl;
	cout << "(7)--合并后的表为（升序）: ";
	list.combineSeq();
	cout << endl;

	return 0;
}