#include"BiTree.h"
#include<string>
#include<iostream>

using namespace std;

int main()
{
	system("color 2F");
	BiTree tree;
	BiNode *bt = new BiNode();
	BiNode *tempNode;//存储建立好的二叉树的根节点

	cout << "	@1.创建二叉树" << endl;
	cout << "按前序输入节点,@表示空节点,并以#结束输入: ";
	tempNode = tree.Creat(bt);
	cout << "	successfully" << endl; 
	cout << endl << endl;

	cout << "	@2.递归中序遍历二叉树" << endl;
	tree.MiddleOrderRecur(tempNode);
	cout << endl << endl;

	cout << "	@3.非递归中序遍历二叉树" << endl;
	tree.MiddleOrderNonrecur(tempNode);
	cout << endl << endl;

	cout << "	@4.递归求二叉树高度" << endl;
	int h;
	h = tree.HeightTree(tempNode);
	cout << "树高度: " << h << endl;
	cout << endl << endl;

	cout << "	@5.递归求二叉树叶子数" << endl;
	int leafNum;
	leafNum = tree.LeafTree(tempNode);
	cout << "leafNumber = " << leafNum << endl;
	cout << endl << endl;

	return 0;
}