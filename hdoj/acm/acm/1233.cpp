#include <iostream>
#include <stdio.h>
using namespace std;
int mincost[101],cost[101][101];
int prim(int v0,int n)
{
	int i,j,mindist,mindot,ans = 0;
	for (i = 1;i <= n;i++)
	{
		mincost[i] = cost[v0][i];
	}
	for (i = 1;i <= n - 1;i++)
	{
		mindist = 10000000;
		for (j = 2;j <= n;j++)
		{
			if (mincost[j] && mindist > mincost[j])
			{
				mindot = j;
				mindist = mincost[j];
			}
		}
		ans += mincost[mindot];
		mincost[mindot] = 0;
		for (j = 1;j <= n;j++)
		{
			if (cost[j][mindot] < mincost[j])
			{
				mincost[j] = cost[j][mindot];
			}
		}
	}
	return ans;
}
int main()
{
	int n,i,a,b,c;
	while (scanf("%d",&n) != EOF && n)
	{
		memset(cost,0,sizeof(cost));
		for (i = 0;i < n * (n - 1) / 2;i++)
		{
			scanf("%d %d %d",&a,&b,&c);
			cost[a][b] = cost[b][a] = c;
		}
		printf("%d\n",prim(1,n));
	}
	
}