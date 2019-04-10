#pragma once
#include<iostream>

using namespace std;

/**
 * @Intrduction 采用二叉链表存储结构
 */
struct BiNode
{
	char data;
	BiNode *leftChild, *rightChild;
};


class BiTree
{
public:
	
	BiTree() {}
	~BiTree() {}

	BiNode* Creat(BiNode *bt);//建立二叉链表

	void MiddleOrderRecur(BiNode *node);//中序变历(递归算法)
	void MiddleOrderNonrecur(BiNode *node);//中序遍历（非递归）

	int HeightTree(BiNode *root);//求二叉树的高度
	int LeafTree(BiNode *broot);//求叶子节点个数
private:
	
};


/**
 * 递归建立二叉树
 */
BiNode* BiTree::Creat(BiNode *bt)
{
	char ch;
	if(cin >> ch && ch != '#')//【注】if(ch = getchar() && ch != '#')读取不了输入的字符
	{
		if (ch == '@') bt = NULL;//@表示空节点
		else
		{
			bt = new BiNode();
			bt->data = ch;
			bt->leftChild = Creat(bt->leftChild);
			bt->rightChild = Creat(bt->rightChild);
		}
		
	}
	return bt;
}


/**
* 递归中序遍历二叉树
*/
void BiTree::MiddleOrderRecur(BiNode *node)
{
	if (node == NULL) return;//递归调用的结束条件
	else
	{
		MiddleOrderRecur(node->leftChild);
		cout << node->data;
		MiddleOrderRecur(node->rightChild);
	}
}

/**
* 非递归中序遍历二叉树
*/
void BiTree::MiddleOrderNonrecur(BiNode *node)
{
	BiNode *stackNode[20];//节点栈
	int top = -1;
	while (node != NULL || top != -1)
	{
		while (node != NULL)
		{
			stackNode[++top] = node;//根指针入栈
			node = node->leftChild;
		}
		if (top != -1)//栈非空
		{
			node = stackNode[top--];
			cout << node->data;//输出根节点数据
			node = node->rightChild;
		}
	}
}

//递归求二叉树高度
int BiTree::HeightTree(BiNode *root)
{
	if (root == NULL) return 0;
	else
	{
		int leftTreeH,rightTreeH;
		leftTreeH = HeightTree(root->leftChild);
		rightTreeH = HeightTree(root->rightChild);
		
		//求左右子树高度的最大值
		if (leftTreeH > rightTreeH)
			return 1 + leftTreeH;
		else
			return 1 + rightTreeH;
	}
}

//递归求二叉树叶子数
int BiTree::LeafTree(BiNode *broot)
{
	if (broot == NULL) {
		return 0;
	}
	else if(broot->leftChild == NULL){
		return 1;    //类似于定义一个计数器count,找到一个左右孩子都为空的节点（即叶子节点）,count就加1
	}
	else {
		return LeafTree(broot->leftChild) + LeafTree(broot->rightChild);
	}
}