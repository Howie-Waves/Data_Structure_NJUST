/*
* ����֤
* �ó��������ʽ�˷����Եó���ȷ���
*/

#include<bits/stdc++.h>
using namespace std;

//����ṹ��-�洢����ʽ
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
	//����n��Ķ���ʽ
	void create(int n);
	//�Ƚ�ָ��
	int comp(int a, int b);
	//����ʽ���
	void addpoly(poly& ha, poly hb);
	//�������ʽ
	void print();
	//��������
	void descSort();
	//����ʽ���
	void multiPoly(poly& ha, poly hb);
	//����ʽ�ĺϲ���
	void Simplify();
};

//ͷ�巨�����½��
void poly::create(int n) {
	head = new lnode;
	head->next = NULL;
	lnode* p;
	for (int i = 0; i < n; i++) {
		p = new lnode;
		cin >> p->coef >> p->exp;//��������
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
			//��������
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

//ͨ��ð������ʵ��
//ֱ�ӽ���������
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
			//��������
			L = L->next;
		}
	}
}

void poly::multiPoly(poly& ha, poly hb)
{
	poly tempPoly;
	lnode* p1 = ha.head->next, * p2 = hb.head->next;
	//����tempPoly��ͷ���
	tempPoly.head = new lnode;
	tempPoly.head->next = NULL;
	lnode* rear = tempPoly.head;

	while (p1)
	{
		while (p2)
		{
			//������㣬�洢��˽������
			lnode* node = new lnode;
			node->exp = p1->exp + p2->exp;
			node->coef = p1->coef * p2->coef;
			node->next = NULL;

			//������������tempPoly
			//��ʱʹ�õ�����λ����뷨��β�巨��
			rear->next = node;
			rear = node;
			rear->next = NULL;

			//����ָ�����
			p2 = p2->next;
		}
		p1 = p1->next;
		//���ǵ�reset
		p2 = hb.head->next;
	}
	//�ǵ�delete����ʽhaԭ����
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
	//���ȶ�ʽ�ӽ�������
	descSort();

	//����һ����ʱ����ʽ����
	poly tempPoly;
	tempPoly.head = new lnode;
	tempPoly.head->next = NULL;
	lnode* rear = tempPoly.head;

	//����һ��ָ��β����ö���
	lnode* p = head->next;
	int tempCoef = p->coef;
	while (p)
	{
		if (p->next == NULL)
		{
			//�����ظ���
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
			//����(��λ��)��������ϲ��Ķ���ʽ
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
	//�޸ĵ��ö����head
	/*p = head;
	do {
		delete p;
		p = p->next;
	} while (p);*/
	head = tempPoly.head;
}

//���������
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
