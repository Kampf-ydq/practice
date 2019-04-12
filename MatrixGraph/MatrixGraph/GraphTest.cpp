#include"Graph.h"

int main()
{
	system("color 2F");

	int arrayGraph[MaxSize];
	UndirectGraph graph;
	int edge;
	cout << "输入"<<MaxSize<<"个顶点: ";
	for (int i = 0; i < MaxSize; i++)
		cin >> arrayGraph[i];
	cout << "输入边的数量: "; cin >> edge;
	cout << "	@1.Adjacency List - Graph " << endl;
	graph.CreateAdjListGraph(arrayGraph, MaxSize, edge);

	cout << "\n邻接表: " << endl;
	graph.ALGraphOut();
	

	cout << "	@2.从 0 号开始深度优先遍历 - Adjacency List" << endl;
	graph.DFSTraverse(0);
	cout << "\nThe Number Of Node: " << graph.NodeNum << endl;
	cout << endl << endl;

	cout << "	@3.从 0 号开始广度优先遍历 - Adjacency List" << endl;
	graph.BFSTraverse(0);
	cout << endl << endl;

	cout << "	@4.Adjacency Matrix - Graph " << endl;
	graph.CreateMatrixGraph(arrayGraph, MaxSize, edge);
	cout << endl << endl;

	cout << "	@5.Prim算法求解最小生成树" << endl;
	Prim(graph);
	cout << endl << endl;

	return 0;
}