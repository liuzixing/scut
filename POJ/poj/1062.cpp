#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;
const int N = 101;
int g[N][N];
int v[N];
int topo[N];
int p[N],l[N];
int m,n,total = 0;
void dfstopo(int x)
{
	int i;
	v[x] = 1;
	for (i = 1;i <= n;i++)
	{
		if ((g[x][i] != -1) && (!v[i]))
		{
			dfstopo(i);
		}
	}
	total++;
	topo[total] = x;
}

int dp()
{
	int i,j,temp;
	for (i = 1;i < total;i++)
	{
		for (j = i + 1;j <= total;j++)
		{
			if (g[topo[j]][topo[i]] > 0)
			{
				temp = g[topo[j]][topo[i]] + p[topo[i]];
				if (temp < p[topo[j]])
				{
					p[topo[j]] = temp;
				}
			}
		}
	}
	return p[1];
}
int main()
{
	int i,j,a,b,x;
	memset(g,-1,sizeof(g));
	memset(v,0,sizeof(v));
	scanf("%d%d",&m,&n);
	for (i = 1;i <= n;i++)
	{
		scanf("%d%d%d",&p[i],&l[i],&x);
		for (j = 1;j <= x;j++)
		{
			scanf("%d%d",&a,&b);
			g[i][a] = b;
		}
		if ( abs( l[i] - l[1] ) > m)
		{
			for (j = 1;j <= n;j++)
			{
				g[j][i] = -1;
			}
		}
	}
	dfstopo(1);
	printf("%d\n",dp());
}