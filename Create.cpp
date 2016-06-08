#include <iostream>

using namespace std;

struct Node
{
	int data;
	struct Node *pNext;
};
typedef struct Node NODE;

struct Queue
{
	NODE *pHead, *pTail;
};
typedef struct Queue QUEUE;

void Init(QUEUE &q)
{
	q.pHead = q.pTail = NULL;
}

NODE *GetNode(int x)
{
	NODE *p = new NODE;
	if(p == NULL)
	{
		exit(0);
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}

bool isEmpty(QUEUE q)
{
	if( q.pHead == NULL)
		return false;//there is no data in stack
	return true;
}

bool Push(QUEUE &q, NODE *p)
{
	if(p == NULL)
	{
		exit(0);
	}
	if(isEmpty(q) == false)
	{
		q.pHead = q.pTail = p;
	}
	else
	{
		q.pTail->pNext = p;
		q.pTail = p;
	}
	return true;
}

bool Pop(QUEUE &q)
{
	NODE *p = q.pHead;
	q.pHead = q.pHead->pNext;
	delete p;
	return true;
}

int Top(QUEUE q)
{
	return q.pHead->data;
}

void InputStack(QUEUE &q)
{
	Init(q);
	int n;
	cout << "\nInput elements: ";
	cin >> n;

	for(int i = 1; i <= n; i++)
	{
		int x;
		cout << "\nInput data: ";
		cin >> x;
		NODE *p = GetNode(x);
		Push(q, p);
	}
}

void OutputStack(QUEUE &q)
{

	/*for(NODE *p = q.pHead; p; p = p->pNext)
	{
		cout << p->data << "   ";
	}*/

	while(isEmpty(q))
	{
		int x = Top(q);
		Pop(q);
		cout << x << "   ";
	}
}

int main()
{
	QUEUE q;
	InputStack(q);
	OutputStack(q);
	return 0;
}