#pragma once
#include<iostream>

using namespace std;

/**
 * @Intrduction ���ö�������洢�ṹ
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

	BiNode* Creat(BiNode *bt);//������������

	void MiddleOrderRecur(BiNode *node);//�������(�ݹ��㷨)
	void MiddleOrderNonrecur(BiNode *node);//����������ǵݹ飩

	int HeightTree(BiNode *root);//��������ĸ߶�
	int LeafTree(BiNode *broot);//��Ҷ�ӽڵ����
private:
	
};


/**
 * �ݹ齨��������
 */
BiNode* BiTree::Creat(BiNode *bt)
{
	char ch;
	if(cin >> ch && ch != '#')//��ע��if(ch = getchar() && ch != '#')��ȡ����������ַ�
	{
		if (ch == '@') bt = NULL;//@��ʾ�սڵ�
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
* �ݹ��������������
*/
void BiTree::MiddleOrderRecur(BiNode *node)
{
	if (node == NULL) return;//�ݹ���õĽ�������
	else
	{
		MiddleOrderRecur(node->leftChild);
		cout << node->data;
		MiddleOrderRecur(node->rightChild);
	}
}

/**
* �ǵݹ��������������
*/
void BiTree::MiddleOrderNonrecur(BiNode *node)
{
	BiNode *stackNode[20];//�ڵ�ջ
	int top = -1;
	while (node != NULL || top != -1)
	{
		while (node != NULL)
		{
			stackNode[++top] = node;//��ָ����ջ
			node = node->leftChild;
		}
		if (top != -1)//ջ�ǿ�
		{
			node = stackNode[top--];
			cout << node->data;//������ڵ�����
			node = node->rightChild;
		}
	}
}

//�ݹ���������߶�
int BiTree::HeightTree(BiNode *root)
{
	if (root == NULL) return 0;
	else
	{
		int leftTreeH,rightTreeH;
		leftTreeH = HeightTree(root->leftChild);
		rightTreeH = HeightTree(root->rightChild);
		
		//�����������߶ȵ����ֵ
		if (leftTreeH > rightTreeH)
			return 1 + leftTreeH;
		else
			return 1 + rightTreeH;
	}
}

//�ݹ��������Ҷ����
int BiTree::LeafTree(BiNode *broot)
{
	if (broot == NULL) {
		return 0;
	}
	else if(broot->leftChild == NULL){
		return 1;    //�����ڶ���һ��������count,�ҵ�һ�����Һ��Ӷ�Ϊ�յĽڵ㣨��Ҷ�ӽڵ㣩,count�ͼ�1
	}
	else {
		return LeafTree(broot->leftChild) + LeafTree(broot->rightChild);
	}
}