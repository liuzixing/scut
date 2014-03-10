#include <iostream>
#include <string.h>
#include <cstdio>
#include <cmath>
using namespace std;

int n,m,g[51][51],ans;
int f[51][51];

int dp(int x,int y)
{
	if (f[x][y] > -1)
		return f[x][y];
	int i,j,t = 0;
	f[x][y] = g[x][y];
	for (i = 0;i <= x;i++)
		for (j = 0;j < n;j++)
		{
			if (i * m + j >= x * m + y)
				break;
			if ((i == x && j < y - 1) || (i != x - 1 && j != y))
			{
				t = max(t,dp(i,j));
			}
		}
	f[x][y] += t;
	if (ans < f[x][y])
		ans = f[x][y];
	return f[x][y];
}
int main()
{
	int i,j;
	while (scanf("%d %d",&m, &n) != EOF)
	{
		for(i = 0;i < m;i++)
		{
			for (j = 0;j < n;j++)
			{
				scanf("%d",&g[i][j]);
			}
		}
		memset(f,-1,sizeof(f));
		ans = 0;
		f[0][0] = g[0][0];
		dp(m - 1,n - 1);
		printf("%d\n",ans);
	}
}
