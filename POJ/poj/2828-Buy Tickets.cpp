#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

struct node
{
	int a,b,l,r,rest;
	int mid()
	{
		return (a + b) >> 1;
	}
}tree[600010];
int N,ans[200010];
int pp[200010],o[200010];
void MakeTree(int aa,int bb,int p = 1)
{
	tree[p].a = aa;
	tree[p].b = bb;
	tree[p].rest = bb - aa + 1;
	if (aa == bb)
		return;
	int mid = tree[p].mid();
	tree[p].l = p << 1;
	tree[p].r = tree[p].l | 1;
	MakeTree(aa,mid,tree[p].l);
	MakeTree(mid + 1,bb,tree[p].r);
}
int query(int k ,int p = 1)
{
	tree[p].rest--;
	if (tree[p].a == tree[p].b)
		return tree[p].a;
	if (tree[tree[p].l].rest >= k)
		return query(k,tree[p].l);
	else
		return query(k - tree[tree[p].l].rest,tree[p].r);
}
int main()
{
	while (scanf("%d",&N) !=EOF)
	{
		for (int i = 1;i <= N;i++)
		{
			scanf("%d %d",&o[i],&pp[i]);
			o[i]++;
		}
		MakeTree(1,N);
		for (int i = N;i >= 1;i--)
			ans[query(o[i])] = pp[i];
		for (int i = 1;i < N;i++)
			printf("%d ",ans[i]);
		printf("%d\n",ans[N]);
	}
}