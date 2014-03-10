#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

struct node
{
	int l,r,cover;
	int mid()
	{
		return (l + r) >> 1;
	}
}tree[80010];
int T,N;
map<int,int>::iterator start,over;
map<int,int>mp;
set<int> st;
struct xy
{
	int l,r;
}pp[10010];
void MakeTree(int aa,int bb,int p = 1)
{
	tree[p].l = aa;
	tree[p].r = bb;
	tree[p].cover = 0;
	if (aa == bb)
		return;
	int mid = tree[p].mid();
	MakeTree(aa,mid,p << 1);
	MakeTree(mid + 1,bb,p << 1 | 1);
}
void insert(int x,int y,int cov,int p = 1)
{
	if (tree[p].l == x && tree[p].r == y)
	{
		tree[p].cover = cov;
		return;
	}
	int next = p << 1,mid = tree[p].mid();
	if (tree[p].cover != -1)
	{
		tree[next].cover = tree[next | 1].cover = tree[p].cover;
		tree[p].cover = -1;
	}
	if (y <= mid)
		insert(x,y,cov,next);
	else
		if(x > mid)
			insert(x,y,cov,next | 1);
		else
		{
			insert(x,mid,cov,next);
			insert(mid + 1,y,cov,next | 1);
		}
}
void query(int x,int y,int p = 1)
{
	if (tree[p].cover != -1 && tree[p].l == x && tree[p].r == y)
	{
		st.insert(tree[p].cover);
		return;
	}
	else
	{
		int next = p << 1,mid = tree[p].mid();
		if (y <= mid) 
			query(x,y,next);
		else
			if (x > mid)
				query(x,y,next | 1);
			else
			{
				query(x,mid,next);
				query(mid + 1,y,next | 1);
			}
	}
}

int main()
{
	scanf("%d",&T);
	MakeTree(1,20010);
	while (T--)
	{
		mp.clear();
		st.clear();
		scanf("%d",&N);
		for (int i = 1;i <= N;i++)
		{
			scanf("%d %d",&pp[i].l,&pp[i].r);
			mp[pp[i].l] = 1;
			mp[pp[i].r] = 1;
		}
		start = mp.begin();
		over = mp.end();
		for (int i = 1;start != over;++start,i++)
			start->second = i;
		insert(1,N * 2,0);
		for (int i = 1;i <= N;i++)
			insert(mp[pp[i].l],mp[pp[i].r],i);
		query(1,N * 2);
		int count = st.size();
		if (*st.begin() == 0)
			count--;
		printf("%d\n",count);
	}
}