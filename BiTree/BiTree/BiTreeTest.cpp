#include"BiTree.h"
#include<string>
#include<iostream>

using namespace std;

int main()
{
	system("color 2F");
	BiTree tree;
	BiNode *bt = new BiNode();
	BiNode *tempNode;//�洢�����õĶ������ĸ��ڵ�

	cout << "	@1.����������" << endl;
	cout << "��ǰ������ڵ�,@��ʾ�սڵ�,����#��������: ";
	tempNode = tree.Creat(bt);
	cout << "	successfully" << endl; 
	cout << endl << endl;

	cout << "	@2.�ݹ��������������" << endl;
	tree.MiddleOrderRecur(tempNode);
	cout << endl << endl;

	cout << "	@3.�ǵݹ��������������" << endl;
	tree.MiddleOrderNonrecur(tempNode);
	cout << endl << endl;

	cout << "	@4.�ݹ���������߶�" << endl;
	int h;
	h = tree.HeightTree(tempNode);
	cout << "���߶�: " << h << endl;
	cout << endl << endl;

	cout << "	@5.�ݹ��������Ҷ����" << endl;
	int leafNum;
	leafNum = tree.LeafTree(tempNode);
	cout << "leafNumber = " << leafNum << endl;
	cout << endl << endl;

	return 0;
}