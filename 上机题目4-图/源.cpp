#include<bits/stdc++.h>
#include "adjList.h"
using namespace std;

int main()
{
	ALGraph myGraph;
	int n, m;
	//（n < 10）
	cout << "请输入顶点数 n:" << endl;
	cin >> n;
	cout << "请输入边的数量 m:" << endl;
	cin >> m;
	cout << endl;

	//创建无向图
	myGraph.createGraph(n, m);

	//DFS的遍历
	//由于创建的图一定是连通图，故直接调用DFS即可
	string dfs_node;
	cout << "\n无向图已建立成功，请输入DFS遍历的起始结点信息:" << endl;
	cin >> dfs_node;
	myGraph.DFS(dfs_node);

	//BFS的遍历
	string bfs_node;
	cout << "\nBFS的遍历为:" << endl;
	myGraph.BFSTraverse();

	return 0;
}