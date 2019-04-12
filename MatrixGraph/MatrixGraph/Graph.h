#pragma once
#include<iostream>

#define MaxSize 4    
#define MaxMax 1000  //代表边权重为无穷大

using namespace std;

//************************【邻接表存储所需数据结构】**********************
//定义边表节点
struct ArcNode
{
	int adjvex;//邻接点域
	ArcNode *next;
};
//定义顶点表节点
struct VertNode
{
	int vertex;
	ArcNode *firstEdge;
};

//***********************【Prim算法所需数据结构】*************************
// 描述: 设置一个数组shortEdge[n]表示候选最短边集，数组元素包括两个域
//      分别表示候选最短边的邻接点和权值
// 例如:   B(A,6) 表示B与集合U中A的最小代价边
//***********************************************************************
struct shortEdge
{
	int adjvex;//邻接点
	int lowCast;//权值
};

class UndirectGraph
{
public:
	int NodeNum = 0;//统计节点个数
	UndirectGraph() { }
	~UndirectGraph(){ }

	void CreateMatrixGraph(int a[], int n, int e);
	void CreateAdjListGraph(int a[],int n, int e);

	void DFSTraverse(int v);//深度优先遍历
	void BFSTraverse(int v);//广度优先遍历

	void ALGraphOut(); //输出邻接表
	friend void Prim(UndirectGraph G);//最小生成树

private:
	int vertex[MaxSize];//存放图的顶点
	int arc[MaxSize][MaxSize];//存放边
	int vertNum, arcNum;//顶点数、边数
	VertNode adjList[MaxSize];//存放顶点表的数组
	int visited[MaxSize];//深度优先遍历时访问标记
};

/**
 * @Introduction 
 *     邻接矩阵存储带权的无向图
 */
void UndirectGraph::CreateMatrixGraph(int a[], int n, int e)
{
	int i, j,w;
	vertNum = n;
	arcNum = e;
	for (int v = 0; v < vertNum; v++)
	{
		vertex[v] = a[v];
		visited[v] = 0;//未访问标记
	}
	//初始化邻接矩阵
	for (int v = 0; v < vertNum; v++)
		for (int e = 0; e < arcNum; e++)
			arc[v][e] = MaxMax;
	cout << "输入边所依附的两个顶点编号及权重" << endl;
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
 * 邻接表存储无向图
 */
void UndirectGraph::CreateAdjListGraph(int a[],int n, int e)
{
	int i, j;
	ArcNode *s,*g;
	vertNum = n;
	arcNum = e;
	for (int v = 0; v < vertNum; v++)//初始化顶点信息
	{
		adjList[v].vertex = a[v];
		adjList[v].firstEdge = NULL;
		visited[v] = 0;//未访问标记
	}

	//依次输入每一条边
	cout << "输入边所依附的两个顶点编号: " << endl;
	cout << "  --------" << endl;
	for (int k = 0; k < arcNum; k++)
	{
		cout << "    ";
		cin >> i >> j;//输入边所依附的两个顶点编号
		s = new ArcNode();s->adjvex = j;
		s->next = adjList[i].firstEdge;
		adjList[i].firstEdge = s;

		/**
		 * 【注意】 需要再申请另一个边表节点，因为每边有两个节点 i--->j  j--->i
		 ****/
		g = new ArcNode(); g->adjvex = i;
		g->next = adjList[j].firstEdge;
		adjList[j].firstEdge = g;
	}
	cout << "  --------" << endl;
}

/**
 * 邻接表--深度优先遍历
 */
void UndirectGraph::DFSTraverse(int v)//v为遍历的起始顶点编号 
{
	int j;
	ArcNode *p;//工作指针
	cout << adjList[v].vertex << " ";
	NodeNum++;//节点个数加一
	visited[v] = 1;//已访问
	p = adjList[v].firstEdge;
	while (p != NULL)
	{
		j = p->adjvex;
		if (visited[j] == 0) DFSTraverse(j);//一条链访问结束
		p = p->next;
	}
}

/**
* 邻接表--广度优先遍历
*/
void UndirectGraph::BFSTraverse(int v)
{
	//-------------定义队列数据结构------------
	int front, rear;
	front = rear = -1;
	int Q[MaxSize];
    
	//------------因为深度优先是visited[]的所有值全为1，所以需要清空---------
	for (int v = 0; v < vertNum; v++)
		visited[v] = 0;

	ArcNode *p;
	int j;
	cout << adjList[v].vertex << " ";
	visited[v] = 1;
	Q[++rear] = v;//被访问顶点入队
	while (front != rear)
	{
		v = Q[++front];
		p = adjList[v].firstEdge;//工作指针指向v的边表
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
 *        Prim算法生成最小生成树
 *---------------------------------------
 *  描述: 1.图的所有顶点集合为V；初始令集合u={s},v=V?u;
 *       2.在两个集合u,v能够组成的边中，选择一条代价最小的边(u0,v0)，加入到最小生成树中，并把v0并入到集合u中
 *		 3.重复上述步骤，直到最小生成树有n-1条边或者n个顶点为止
 ************************************/
int Minmun(shortEdge closeEdge[])//返回最小代价边
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


//------------------正式定义Prim算法-------------------------
void Prim(UndirectGraph G)
{
	shortEdge tmp[MaxSize];
	int k;
	for (int i = 1; i < G.vertNum; i++)
	{
		tmp[i].lowCast = G.arc[0][i];
		tmp[i].adjvex = 0;
	}

	tmp[0].lowCast = 0;//将顶点V0加入初始集合U，表示不再考虑这条边的权值
	for (int i = 1; i < G.vertNum; i++)
	{
		k = Minmun(tmp);//选择最小代价边
		cout << "(" << k << "----" << tmp[k].adjvex << ")" << tmp[k].lowCast;

		tmp[k].lowCast = 0;//将顶点k加入集合U中

		for (int j = 1; j < G.vertNum; j++)//更新v中顶点最小代价边信息
		{
			if (G.arc[k][j] < tmp[j].lowCast)
			{
				tmp[j].lowCast = G.arc[k][j];
				tmp[j].adjvex = k;
			}
		}
	}
}