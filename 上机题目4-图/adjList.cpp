#include<bits/stdc++.h>
#include "adjList.h"

void ALGraph::createGraph(int n, int m)
{
	//������Ϣ��ֵ
	ag.vexnum = n;
	ag.arcnum = m;
	ag.kind = UDG;

	//int i, j;
	//���ڼ�¼u, v����������±�location
	int h, t;

	//u, v�洢������Ϣ
	string u, v;
	//��������new���ʱʹ��
	arcNode* p;

	//��ʼ����ͷ����
	cout << "���������붥����Ϣ:��string�� " << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> ag.vertices[i].data;
		ag.vertices[i].firstarc = nullptr;
	}

	//�����߼�
	cout << "����������߼���Ϣ(u -> v): " << endl;
	for (int j = 0; j < m; j++)
	{
		//����һ����
		cin >> u >> v;

		h = locateVex(u);
		t = locateVex(v);

		//�洢����ߣ�u, v��
		p = new arcNode;
		p->adjvex = t;
		//ͷ�巨��������
		p->nextarc = ag.vertices[h].firstarc;
		ag.vertices[h].firstarc = p;

		//�洢����ߣ�v, u��
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

//���ʱ�־���飬��ʼ��ȫΪ0
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
	
	//�˴�ʹ��C++ STL�еĶ��� queue
	queue<int> q;
	q.push(h);
	visited[h] = 1;

	while (!q.empty())
	{
		//ɾ����ǰ���е�һ��Ԫ��
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
