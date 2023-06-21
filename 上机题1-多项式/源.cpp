/*
* 已验证
* 该程序球多项式乘法可以得出正确结果
*/

#include<bits/stdc++.h>
using namespace std;

//定义结构体-存储单项式
typedef struct lnode {
	int coef;
	int exp;
	lnode* next;
}lnode;

//
class poly {
	lnode* head;
	int count = 0;
public:
	//创建n项的多项式
	void create(int n);
	//比较指数
	int comp(int a, int b);
	//多项式相加
	void addpoly(poly& ha, poly hb);
	//输出多项式
	void print();
	//降序排列
	void descSort();
	//多项式相乘
	void multiPoly(poly& ha, poly hb);
	//多项式的合并简化
	void Simplify();
};

//头插法插入新结点
void poly::create(int n) {
	head = new lnode;
	head->next = NULL;
	lnode* p;
	for (int i = 0; i < n; i++) {
		p = new lnode;
		cin >> p->coef >> p->exp;//升序输入
		p->next = head->next;
		head->next = p;
		count++;
	}
}


int poly::comp(int a, int b) {
	if (a > b)return -1;
	else if (a == b)return 0;
	else return 1;
}


void poly::addpoly(poly& ha, poly hb) {
	lnode* q = ha.head, * pa = ha.head->next, * pb = hb.head->next, * r;
	while (pa && pb)
		switch (comp(pa->exp, pb->exp)) {
		case -1: q = pa; pa = pa->next;
			break;
		case 0: pa->coef += pb->coef;
			if (pa->coef == 0) {
				q->next = pa->next;
				delete pa;
				pa = q;
			}
			else q = pa;
			//继续遍历
			pa = pa->next;
			pb = pb->next;
			break;
		case 1:  r = new  lnode;
			r->coef = pb->coef;
			r->exp = pb->exp;
			q->next = r;
			r->next = pa;
			q = r;
			pb = pb->next;
			break;
		}
	while (pb != NULL) {
		r = new lnode;
		r->coef = pb->coef;
		r->exp = pb->exp;
		q->next = r;
		r->next = pa;
		q = r;
		pb = pb->next;
	}
}


void poly::print() {
	lnode* p = head->next;
	while (p) {
		cout << p->coef << ' ' << p->exp << ' ';
		p = p->next;
	}
	cout << endl;
}

//通过冒泡排序实现
//直接交换数据域
void poly::descSort()
{
	lnode* L = head;
	lnode* p1, * p2;

	for (int i = 0; i < count - 1; i++)
	{
		L = head->next;
		for (int j = 0; j < count - i - 1; j++)
		{
			int temp;
			p1 = L;
			p2 = L->next;
			if (p1->exp < p2->exp)
			{
				temp = p1->exp;
				p1->exp = p2->exp;
				p2->exp = temp;
				temp = p1->coef;
				p1->coef = p2->coef;
				p2->coef = temp;
			}
			//容易忘记
			L = L->next;
		}
	}
}

void poly::multiPoly(poly& ha, poly hb)
{
	poly tempPoly;
	lnode* p1 = ha.head->next, * p2 = hb.head->next;
	//建立tempPoly的头结点
	tempPoly.head = new lnode;
	tempPoly.head->next = NULL;
	lnode* rear = tempPoly.head;

	while (p1)
	{
		while (p2)
		{
			//创建结点，存储相乘结果数据
			lnode* node = new lnode;
			node->exp = p1->exp + p2->exp;
			node->coef = p1->coef * p2->coef;
			node->next = NULL;

			//将结点插入链表tempPoly
			//此时使用的是正位序插入法（尾插法）
			rear->next = node;
			rear = node;
			rear->next = NULL;

			//链表指针后移
			p2 = p2->next;
		}
		p1 = p1->next;
		//最后记得reset
		p2 = hb.head->next;
	}
	//记得delete多项式ha原来的
	p1 = ha.head;
	p2 = p1->next;
	while (p2)
	{
		delete p1;
		p1 = p2;
		p2 = p2->next;
	}
	delete p1;
	ha.head = tempPoly.head;
}

void poly::Simplify()
{
	//首先对式子进行排序
	descSort();

	//创建一个临时多项式对象
	poly tempPoly;
	tempPoly.head = new lnode;
	tempPoly.head->next = NULL;
	lnode* rear = tempPoly.head;

	//建立一个指针尾随调用对象
	lnode* p = head->next;
	int tempCoef = p->coef;
	while (p)
	{
		if (p->next == NULL)
		{
			//代码重复了
			lnode* node = new lnode;
			node->coef = tempCoef;
			node->exp = p->exp;
			node->next = NULL;
			rear->next = node;
			rear = node;
			rear->next = NULL;
			break;
		}

		if (p->exp == p->next->exp)
		{
			tempCoef += p->next->coef;
			p = p->next;
			continue;
		}
		else
		{
			//首先(正位序法)插入这个合并的多项式
			lnode* node = new lnode;
			node->coef = tempCoef;
			node->exp = p->exp;
			node->next = NULL;
			rear->next = node;
			rear = node;
			rear->next = NULL;

			//reset other values
			tempCoef = p->next->coef;
			p = p->next;
		}

	}
	//修改调用对象的head
	/*p = head;
	do {
		delete p;
		p = p->next;
	} while (p);*/
	head = tempPoly.head;
}

//主函数入口
int main(void) {
	poly ha, hb;
	ha.create(2);
	hb.create(2);

	ha.multiPoly(ha, hb);

	ha.Simplify();

	ha.print();

	/*ha.descSort();
	ha.print();*/
	/*hb.print();
	ha.addpoly(ha, hb);
	ha.print();*/
	return 0;
}
