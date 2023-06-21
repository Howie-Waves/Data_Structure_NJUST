#include<bits/stdc++.h>
#include "adjList.h"

void ALGraph::createGraph(int n, int m)
{
	//基本信息赋值
	ag.vexnum = n;
	ag.arcnum = m;
	ag.kind = UDG;

	//int i, j;
	//用于记录u, v顶点的数组下标location
	int h, t;

	//u, v存储顶点信息
	string u, v;
	//创建链表new结点时使用
	arcNode* p;

	//初始化表头数组
	cout << "请依次输入顶点信息:（string） " << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> ag.vertices[i].data;
		ag.vertices[i].firstarc = nullptr;
	}

	//建立边集
	cout << "请依次输入边集信息(u -> v): " << endl;
	for (int j = 0; j < m; j++)
	{
		//输入一条狐
		cin >> u >> v;

		h = locateVex(u);
		t = locateVex(v);

		//存储无向边（u, v）
		p = new arcNode;
		p->adjvex = t;
		//头插法接入链表
		p->nextarc = ag.vertices[h].firstarc;
		ag.vertices[h].firstarc = p;

		//存储无向边（v, u）
		p = new arcNode;
		p->adjvex = h;
		p->nextarc = ag.vertices[t].firstarc;
		ag.vertices[t].firstarc = p;
	}
}

int ALGraph::locateVex(string u)
{
	for (int i = 0; i < ag.vexnum; i++)
		if (u == ag.vertices[i].data)
			return i;

	return -1;
}

//访问标志数组，初始化全为0
int visited[maxVex];

void ALGraph::DFS(string u)
{
	int h = locateVex(u);
	cout << u << " ";
	visited[h] = 1;

	arcNode* p;

	for (p = ag.vertices[h].firstarc; p; p = p->nextarc)
	{
		if (visited[p->adjvex] == 0)
			DFS(ag.vertices[p->adjvex].data);
	}
}

void ALGraph::BFS(string u)
{
	int h = locateVex(u);
	arcNode* p;
	
	//此处使用C++ STL中的队列 queue
	queue<int> q;
	q.push(h);
	visited[h] = 1;

	while (!q.empty())
	{
		//删除当前队列第一个元素
		cout << ag.vertices[q.front()].data << " ";
		q.pop();

		for(p = ag.vertices[h].firstarc; p; p = p->nextarc)
			if (visited[p->adjvex] == 0)
			{
				q.push(p->adjvex);
				visited[p->adjvex] = 1;
			}
	}
}

void ALGraph::BFSTraverse()
{
	memset(visited, 0, sizeof(visited));

	for (int i = 0; i < ag.vexnum; i++)
	{
		if (visited[i] == 0)
			BFS(ag.vertices[i].data);
	}
}
