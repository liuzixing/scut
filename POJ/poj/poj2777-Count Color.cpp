#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

struct node
{
	int a,b,l,r,cover;

}tree[600010];
int L,T,O,ans;
int pa,pb,color;
int b[31] = {0,1};
bool v[31];
void MakeTree(int aa,int bb,int p = 1)
{
	tree[p].a = aa;
	tree[p].b = bb;
	tree[p].cover = 1;
	if (aa == bb)
		return;
	int mid = (tree[p].a + tree[p].b) >> 1; 
	tree[p].l = p << 1;
	tree[p].r = tree[p].l | 1;
	MakeTree(aa,mid,tree[p].l);
	MakeTree(mid + 1,bb,tree[p].r);
}
void query(int x,int y,int p = 1)
{
	if (tree[p].cover != -1)
	{
		if(!v[tree[p].cover])
		{
			ans += b[tree[p].cover];
			v[tree[p].cover] = 1;
		}
		return;
	}
	int mid = (tree[p].a + tree[p].b) >> 1;
	if (y <= mid)
		query(x,y,tree[p].l);
	else
		if (x > mid)
			query(x,y,tree[p].r);
		else
		{
			query(x,mid,tree[p].l);
			query(mid + 1,y,tree[p].r);
		}
}
void insert(int x,int y,int cov ,int p = 1)
{
	if (tree[p].a == x && tree[p].b == y)
	{
		tree[p].cover = cov;
		return;
	}
	if (tree[p].cover != -1)
	{
		tree[tree[p].l].cover = tree[tree[p].r].cover = tree[p].cover;
		tree[p].cover = -1;
	}
	int mid = (tree[p].a + tree[p].b) >> 1;
	if (y <= mid)
		insert(x,y,cov,tree[p].l);
	else
		if (x > mid)
			insert(x,y,cov,tree[p].r);
		else
		{
			insert(x,mid,cov,tree[p].l);
			insert(mid + 1,y,cov,tree[p].r);
		}
}
int output(int x)
{
	int i,t = 0;
	for (i = 30;i > 0;i--)
		if (b[i] <= x)
		{
			x -= b[i];
			t++;
		}
	return t;
}
int main()
{
	int i;
	for (i = 2;i < 31;i++)
		b[i] = b[i - 1] << 1;
	char c;
	scanf("%d %d %d",&L,&T,&O);
	MakeTree(1,L);
	for (int i = 1;i <= O;i++)
	{
		scanf("%*c%c",&c);
		if (c == 'C')
		{
			scanf("%d %d %d",&pa,&pb,&color);
			if (pa > pb)
				swap(pa,pb);
			insert(pa,pb,color);
		}
		else
		{
			ans = 0;
			scanf("%d %d",&pa,&pb);
			if (pa > pb)
				swap(pa,pb);
			memset(v,0,sizeof(v));
			query(pa,pb);
			printf("%d\n",output(ans));
		}
	}
}