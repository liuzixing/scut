#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 200001;
int h,w,n;
int Max[maxn << 2];
void PushUp(int rt)
{
	Max[rt] = max(Max[rt << 1],Max[rt << 1 | 1]);
}
void build(int l,int r,int rt)
{
	Max[rt] = w;
	if (l == r) return;
	int m = (l + r) >> 1;
	build(l,m,rt << 1);
	build(m + 1,r,rt << 1 | 1);
}

int query(int x,int l,int r,int rt)
{
	if (l == r)
	{
		Max[rt] -= x;
		return l;
	}
	int m = (l + r) >> 1;
	int ans = (Max[rt << 1] >= x) ? query(x,l,m,rt << 1):query(x,m + 1,r,rt << 1 | 1);
	PushUp(rt);
	return ans;
}
int main()
{
	while (~scanf("%d%d%d",&h,&w,&n))
	{
		if (h > n) h = n;
		build(1,h,1);
		while (n--)
		{
			int x;
			scanf("%d",&x);
			if (Max[1] < x) puts("-1");
			else
				printf("%d\n",query(x,1,h,1));
		}
	}
	return 0;
}