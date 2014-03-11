/*
ID: benbenq1
LANG: C++
TASK: ariprog
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <climits>
#include <vector>
using namespace std;
bool b[125001] = {0};
int f[40001];
struct node
{
	int a,b;
}ans[10001];
bool cmp(node x,node y)
{
	if (x.b == y.b)
	{
		return x.a < y.a;
	}
	return x.b < y.b;
}
int main()
{
	int n,m,i,j,maxn,total = 0,ansn = -1,k;
	freopen("ariprog.in","r",stdin);
	freopen("ariprog.out","w",stdout);
	scanf("%d",&n);
	scanf("%d",&m);
	for (i = 0;i <= m;i++)
	{
		for (j = 0;j <= m;j++)
		{
			b[i * i + j * j] = 1;
		}
	}

	maxn = m * m * 2;
	for (i =0;i <= maxn;i++)
	{
		if (b[i])
		{
			f[total++] = i;
		}
	}
	
	for (i = 0;i < total;i++)
	{
		for (j = 1;f[i] + (n - 1) * j <= maxn;j++)
		{
			bool flag = 0;
			int tem = f[i];
			for (k = 1;k < n ;k++)
			{
				tem += j;
				if (!b[tem])
				{
					flag = 1;
					break;
				}
			}
			if (!flag)
			{
				ans[++ansn].a = f[i];
				ans[ansn].b = j;
			}
		}
	}

	sort(ans,ans + ansn + 1,cmp);
	if (ansn < 0)
	{
		printf("NONE\n");
	}
	else
	{
		for (i = 0;i <= ansn;i++)
		{
			printf("%d %d\n",ans[i].a,ans[i].b);
		}
	}
}