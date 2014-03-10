#include <iostream>
#include <cstdio>
using namespace std;
struct node
{
	int l,r,rest;
}tree[33000];
int d[8001],ans[8001];

void MakeTree(int p ,int a,int b)
{
	tree[p].l = a;
	tree[p].r = b;
	tree[p].rest = b - a + 1;
	if (a == b)
		return;
	else
	{
		int next = p << 1;
		int mid = (a + b) >> 1;
		MakeTree(next,a,mid);
		MakeTree(next + 1,mid + 1,b);
	}
}
int FindTree(int p,int k)
{
	tree[p].rest--;
	if (tree[p].l == tree[p].r)
		return tree[p].l;
	int next = p << 1;
	if (tree[next].rest >= k)
		return FindTree(next,k);
	else
		return FindTree(next + 1,k - tree[next].rest);
}
int main()
{
	int n,i;
	scanf("%d",&n);
	for (i = 1;i < n;i++)
	{
		scanf("%d",&d[i]);
		d[i]++;
	}
	MakeTree(1,1,n);
	d[0] = 1;
	for (i = n - 1;i >= 0;i--)
		ans[i] = FindTree(1,d[i]);
	for (i = 0;i < n;i++)
		printf("%d\n",ans[i]);
}