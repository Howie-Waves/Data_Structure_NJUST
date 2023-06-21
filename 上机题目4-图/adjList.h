#pragma once
/*
* 定义图的邻接表存储结构
*/
#define maxVex 10	//定义最大定点数
#include<bits/stdc++.h>
using namespace std;

//有向图，无向图，有向网，无向网
typedef enum{DG, UDG, DN, UDN} GraphKind;

struct Edge {
	string tail;
	string head;
	//由于是无权图，不定义cost变量
};

struct arcNode {
	int adjvex;		//终点在顶点数组中的下标
	arcNode* nextarc;
};

//表头结点——即存储每个结点的数组类型
struct VNode {
	string data;
	arcNode* firstarc;
};

//一个完整的结构（包含了上述的所有子结构体）
struct adjLgraph {
	//表头结点数组
	VNode vertices[maxVex];
	
	int vexnum;
	int arcnum;

	GraphKind kind;
};

class ALGraph {
private:
	//完整结构体——邻接表
	adjLgraph ag;

public:
	void createGraph(int n, int m);
	int locateVex(string u);
	void DFS(string u);
	void BFS(string u);
	void BFSTraverse();
	adjLgraph getAg() { return ag; }
};

 
