#include<bits/stdc++.h>
#include "adjList.h"
using namespace std;

int main()
{
	ALGraph myGraph;
	int n, m;
	//��n < 10��
	cout << "�����붥���� n:" << endl;
	cin >> n;
	cout << "������ߵ����� m:" << endl;
	cin >> m;
	cout << endl;

	//��������ͼ
	myGraph.createGraph(n, m);

	//DFS�ı���
	//���ڴ�����ͼһ������ͨͼ����ֱ�ӵ���DFS����
	string dfs_node;
	cout << "\n����ͼ�ѽ����ɹ���������DFS��������ʼ�����Ϣ:" << endl;
	cin >> dfs_node;
	myGraph.DFS(dfs_node);

	//BFS�ı���
	string bfs_node;
	cout << "\nBFS�ı���Ϊ:" << endl;
	myGraph.BFSTraverse();

	return 0;
}