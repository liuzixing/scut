#include <iostream>
#include <queue>
using namespace std;

struct BTNode
{
	char data;
	BTNode* left;
	BTNode* right;
	int deep;//节点所在层
};

queue<BTNode*> Q;

BTNode* PreOrder(BTNode* T,int d)//先序遍历
{
	T = new BTNode();
	char data;
	cin >> data;
	if(data!='\/')
	{
		T->data=data;
		T->deep = d;
		T->left = PreOrder(T->left, d + 1);
		T->right = PreOrder(T->right, d + 1);
	}
	else
		T=NULL;
	return T;
}

void BFS(BTNode* T)//广度优先搜索
{
	int d = 1;
	if(T)
	{
		BTNode* t;
		while (!Q.empty())
		{
			t = Q.front();
			if (d != t->deep)
			{
				cout << endl;//不在同一层，则换行输出
				d++;
			}
			cout << t->data;
			
			Q.pop();
			if (t->left)
				Q.push(t->left);
			if (t->right)
				Q.push(t->right);
		}
		cout << endl;
	}
	
}
int main()
{
	BTNode* T;
	T = PreOrder(T, 1);
	Q.push(T);
	BFS(T);
	
	return 0;
}

/*
data_in: A/BCDEF/G/H/I/JSTV//W//UX//Y//Z////K/LMR//O//P/Q///


data_out:
A
B
C
DK
EL
FMP
GROQ
H
I
J
SZ
TU
VWXY
*/
