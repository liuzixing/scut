#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int n,l,r,m,f[500001],i;
struct node
{
	int p,r;
}a[500001];

bool cmp(node x,node y)
{
	return x.p < y.p;
}

inline void binarysearch()
{
	while (l <= r)
	{
		m = (l + r) >> 1;
		if (f[m] < a[i].r)
			l = m + 1;
		else
			r = m - 1;
	}
}
int main()
{
	int cas = 0,ans;
	while (scanf("%d",&n) != EOF)
	{
		ans = 1;
		for (i = 0;i < n;i++)
			scanf("%d%d",&a[i].p,&a[i].r);
		memset(f,0,sizeof f);
		sort(a,a + n,cmp);
		f[1] = a[0].r;
		for (i = 1;i < n;i++)
		{
			l = 1,r = ans;
			binarysearch();
			if (f[l] > a[i].r || f[l] == 0)
				f[l] = a[i].r;
			if (ans < l)
			{
				ans++;
				f[ans] = a[i].r;
			}
		}
		if (ans == 1)
			printf("Case %d:\nMy king, at most 1 road can be built.\n\n",++cas);
		else
			printf("Case %d:\nMy king, at most %d roads can be built.\n\n",++cas,ans);
	}
}