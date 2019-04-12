#include"Graph.h"

int main()
{
	system("color 2F");

	int arrayGraph[MaxSize];
	UndirectGraph graph;
	int edge;
	cout << "����"<<MaxSize<<"������: ";
	for (int i = 0; i < MaxSize; i++)
		cin >> arrayGraph[i];
	cout << "����ߵ�����: "; cin >> edge;
	cout << "	@1.Adjacency List - Graph " << endl;
	graph.CreateAdjListGraph(arrayGraph, MaxSize, edge);

	cout << "\n�ڽӱ�: " << endl;
	graph.ALGraphOut();
	

	cout << "	@2.�� 0 �ſ�ʼ������ȱ��� - Adjacency List" << endl;
	graph.DFSTraverse(0);
	cout << "\nThe Number Of Node: " << graph.NodeNum << endl;
	cout << endl << endl;

	cout << "	@3.�� 0 �ſ�ʼ������ȱ��� - Adjacency List" << endl;
	graph.BFSTraverse(0);
	cout << endl << endl;

	cout << "	@4.Adjacency Matrix - Graph " << endl;
	graph.CreateMatrixGraph(arrayGraph, MaxSize, edge);
	cout << endl << endl;

	cout << "	@5.Prim�㷨�����С������" << endl;
	Prim(graph);
	cout << endl << endl;

	return 0;
}