#pragma once
/*
* ����ͼ���ڽӱ�洢�ṹ
*/
#define maxVex 10	//������󶨵���
#include<bits/stdc++.h>
using namespace std;

//����ͼ������ͼ����������������
typedef enum{DG, UDG, DN, UDN} GraphKind;

struct Edge {
	string tail;
	string head;
	//��������Ȩͼ��������cost����
};

struct arcNode {
	int adjvex;		//�յ��ڶ��������е��±�
	arcNode* nextarc;
};

//��ͷ��㡪�����洢ÿ��������������
struct VNode {
	string data;
	arcNode* firstarc;
};

//һ�������Ľṹ�������������������ӽṹ�壩
struct adjLgraph {
	//��ͷ�������
	VNode vertices[maxVex];
	
	int vexnum;
	int arcnum;

	GraphKind kind;
};

class ALGraph {
private:
	//�����ṹ�塪���ڽӱ�
	adjLgraph ag;

public:
	void createGraph(int n, int m);
	int locateVex(string u);
	void DFS(string u);
	void BFS(string u);
	void BFSTraverse();
	adjLgraph getAg() { return ag; }
};

 
