#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int  maxn = 100010;
struct node
{
	int sum,mins,maxs;//总和，最小子段，最大子段
	int lmin,lmax;//左最小子段，左最大子段，
	int rmin,rmax;//右最小子段，右最小子段
}tree[maxn * 4];
int data[maxn];
int n,m;
int Min(int a,int b,int c,int d,int e)
{
	int ans = (a < b) ? a : b;
	ans = (ans < c) ? ans : c;
	ans = (ans < d) ? ans : d;
	ans = (ans < e) ? ans : e;
	return ans;
}
int Max(int a,int b,int c,int d,int e)
{
	int ans = (a > b) ? a : b;
	ans = (ans > c) ? ans : c;
	ans = (ans > d) ? ans : d;
	ans = (ans > e) ? ans : e;
	return ans;
}
void update(int k)
{
	int lson = k << 1,rson = lson | 1;
	tree[k].sum = tree[lson].sum + tree[rson].sum;
	tree[k].lmax = max(tree[lson].sum + tree[rson].lmax,tree[lson].lmax);
	tree[k].lmin = min(tree[lson].sum + tree[rson].lmin,tree[lson].lmin);
	tree[k].rmax = max(tree[rson].sum + tree[lson].rmax,tree[rson].rmax);
	tree[k].rmin = min(tree[rson].sum + tree[lson].rmin,tree[rson].rmin);
	tree[k].mins = Min(tree[lson].mins,tree[rson].mins,tree[lson].rmin + tree[rson].lmin,tree[k].rmin , tree[k].lmin);
	tree[k].maxs = Max(tree[lson].maxs,tree[rson].maxs,tree[lson].rmax + tree[rson].lmax,tree[k].rmax , tree[k].lmax);
}
void maketree(int l,int r,int p = 1)
{
	if (l == r)
	{
		tree[p].sum = tree[p].mins = tree[p].maxs = data[l];
		tree[p].rmin = tree[p].lmin = tree[p].lmax = tree[p].rmax = data[l];
	}
	else
	{
		int mid = (l + r) >> 1;
		maketree(l,mid,p << 1);
		maketree(mid + 1,r,(p << 1) | 1);
		update(p);
	}
}
void insert(int l,int r,int a,int b,int p = 1)
{
	if (l == r)
	{
		tree[p].sum = tree[p].mins = tree[p].maxs = b;
		tree[p].rmin = tree[p].lmin = tree[p].lmax = tree[p].rmax = b;
	}
	else
	{
		int mid = (l + r) >> 1;
		if (a <= mid)
			insert(l ,mid ,a,b,p << 1);
		else
			insert(mid + 1,r,a,b,(p << 1) | 1);
		update(p);
	}
}
int main()
{
	int ans,a,b;
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		scanf("%d",&data[i]);
	maketree(1,n);
	scanf("%d",&m);

	while (m--)
	{
		scanf("%d %d",&a,&b);
		insert(1,n,a,b);
		if (tree[1].maxs = tree[1].sum)
			ans = tree[1].sum - tree[1].mins;
		else
			ans = max(tree[1].maxs,tree[1].sum - tree[1].mins);
		printf("%d\n",ans);
	}
}