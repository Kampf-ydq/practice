#pragma once
#include<iostream>

#define MaxSize 4    
#define MaxMax 1000  //�����Ȩ��Ϊ�����

using namespace std;

//************************���ڽӱ�洢�������ݽṹ��**********************
//����߱�ڵ�
struct ArcNode
{
	int adjvex;//�ڽӵ���
	ArcNode *next;
};
//���嶥���ڵ�
struct VertNode
{
	int vertex;
	ArcNode *firstEdge;
};

//***********************��Prim�㷨�������ݽṹ��*************************
// ����: ����һ������shortEdge[n]��ʾ��ѡ��̱߼�������Ԫ�ذ���������
//      �ֱ��ʾ��ѡ��̱ߵ��ڽӵ��Ȩֵ
// ����:   B(A,6) ��ʾB�뼯��U��A����С���۱�
//***********************************************************************
struct shortEdge
{
	int adjvex;//�ڽӵ�
	int lowCast;//Ȩֵ
};

class UndirectGraph
{
public:
	int NodeNum = 0;//ͳ�ƽڵ����
	UndirectGraph() { }
	~UndirectGraph(){ }

	void CreateMatrixGraph(int a[], int n, int e);
	void CreateAdjListGraph(int a[],int n, int e);

	void DFSTraverse(int v);//������ȱ���
	void BFSTraverse(int v);//������ȱ���

	void ALGraphOut(); //����ڽӱ�
	friend void Prim(UndirectGraph G);//��С������

private:
	int vertex[MaxSize];//���ͼ�Ķ���
	int arc[MaxSize][MaxSize];//��ű�
	int vertNum, arcNum;//������������
	VertNode adjList[MaxSize];//��Ŷ���������
	int visited[MaxSize];//������ȱ���ʱ���ʱ��
};

/**
 * @Introduction 
 *     �ڽӾ���洢��Ȩ������ͼ
 */
void UndirectGraph::CreateMatrixGraph(int a[], int n, int e)
{
	int i, j,w;
	vertNum = n;
	arcNum = e;
	for (int v = 0; v < vertNum; v++)
	{
		vertex[v] = a[v];
		visited[v] = 0;//δ���ʱ��
	}
	//��ʼ���ڽӾ���
	for (int v = 0; v < vertNum; v++)
		for (int e = 0; e < arcNum; e++)
			arc[v][e] = MaxMax;
	cout << "����������������������ż�Ȩ��" << endl;
	cout << "  --------" << endl;
	for (int k = 0; k < arcNum; k++)
	{
		cout << "    ";
		cin >> i >> j >> w;
		arc[i][j] = w;
		arc[j][i] = w;
	}
	cout << "  --------" << endl;
}

/**
 * �ڽӱ�洢����ͼ
 */
void UndirectGraph::CreateAdjListGraph(int a[],int n, int e)
{
	int i, j;
	ArcNode *s,*g;
	vertNum = n;
	arcNum = e;
	for (int v = 0; v < vertNum; v++)//��ʼ��������Ϣ
	{
		adjList[v].vertex = a[v];
		adjList[v].firstEdge = NULL;
		visited[v] = 0;//δ���ʱ��
	}

	//��������ÿһ����
	cout << "�����������������������: " << endl;
	cout << "  --------" << endl;
	for (int k = 0; k < arcNum; k++)
	{
		cout << "    ";
		cin >> i >> j;//�����������������������
		s = new ArcNode();s->adjvex = j;
		s->next = adjList[i].firstEdge;
		adjList[i].firstEdge = s;

		/**
		 * ��ע�⡿ ��Ҫ��������һ���߱�ڵ㣬��Ϊÿ���������ڵ� i--->j  j--->i
		 ****/
		g = new ArcNode(); g->adjvex = i;
		g->next = adjList[j].firstEdge;
		adjList[j].firstEdge = g;
	}
	cout << "  --------" << endl;
}

/**
 * �ڽӱ�--������ȱ���
 */
void UndirectGraph::DFSTraverse(int v)//vΪ��������ʼ������ 
{
	int j;
	ArcNode *p;//����ָ��
	cout << adjList[v].vertex << " ";
	NodeNum++;//�ڵ������һ
	visited[v] = 1;//�ѷ���
	p = adjList[v].firstEdge;
	while (p != NULL)
	{
		j = p->adjvex;
		if (visited[j] == 0) DFSTraverse(j);//һ�������ʽ���
		p = p->next;
	}
}

/**
* �ڽӱ�--������ȱ���
*/
void UndirectGraph::BFSTraverse(int v)
{
	//-------------����������ݽṹ------------
	int front, rear;
	front = rear = -1;
	int Q[MaxSize];
    
	//------------��Ϊ���������visited[]������ֵȫΪ1��������Ҫ���---------
	for (int v = 0; v < vertNum; v++)
		visited[v] = 0;

	ArcNode *p;
	int j;
	cout << adjList[v].vertex << " ";
	visited[v] = 1;
	Q[++rear] = v;//�����ʶ������
	while (front != rear)
	{
		v = Q[++front];
		p = adjList[v].firstEdge;//����ָ��ָ��v�ı߱�
		while (p != NULL)
		{
			j = p->adjvex;
			if (visited[j] == 0)
			{
				cout << adjList[j].vertex << " ";
				visited[j] = 1;
				Q[++rear] = j;
			}
			p = p->next;
		}
	}
	
}

void UndirectGraph::ALGraphOut()
{
	int k;
	ArcNode *p;
	for (k = 0; k<vertNum; k++)
	{
		cout << adjList[k].vertex << ' ';
		p = adjList[k].firstEdge;
		while (p)
		{
			cout << p->adjvex << ' ';
			p = p->next;
		}
		cout << '\n';
	}
}

/****************************************
 *        Prim�㷨������С������
 *---------------------------------------
 *  ����: 1.ͼ�����ж��㼯��ΪV����ʼ���u={s},v=V?u;
 *       2.����������u,v�ܹ���ɵı��У�ѡ��һ��������С�ı�(u0,v0)�����뵽��С�������У�����v0���뵽����u��
 *		 3.�ظ��������裬ֱ����С��������n-1���߻���n������Ϊֹ
 ************************************/
int Minmun(shortEdge closeEdge[])//������С���۱�
{
	int minVal = MaxMax;
	int index = -1;
	for (int i = 0; i < MaxSize; i++)
	{
		if (closeEdge[i].lowCast < minVal && closeEdge[i].lowCast != 0)
		{
			minVal = closeEdge[i].lowCast;
			index = i;
		}
	}
	return index;
}


//------------------��ʽ����Prim�㷨-------------------------
void Prim(UndirectGraph G)
{
	shortEdge tmp[MaxSize];
	int k;
	for (int i = 1; i < G.vertNum; i++)
	{
		tmp[i].lowCast = G.arc[0][i];
		tmp[i].adjvex = 0;
	}

	tmp[0].lowCast = 0;//������V0�����ʼ����U����ʾ���ٿ��������ߵ�Ȩֵ
	for (int i = 1; i < G.vertNum; i++)
	{
		k = Minmun(tmp);//ѡ����С���۱�
		cout << "(" << k << "----" << tmp[k].adjvex << ")" << tmp[k].lowCast;

		tmp[k].lowCast = 0;//������k���뼯��U��

		for (int j = 1; j < G.vertNum; j++)//����v�ж�����С���۱���Ϣ
		{
			if (G.arc[k][j] < tmp[j].lowCast)
			{
				tmp[j].lowCast = G.arc[k][j];
				tmp[j].adjvex = k;
			}
		}
	}
}