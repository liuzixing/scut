/*
ID: benbenq1
PROG: concom
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int g[101][101],c[101],n;
bool v[101];
void dfs(int x)
{
	int i;
	v[x] = 1;
	for (i = 1;i <= n;i++)
	{
		c[i] += g[x][i];
	}
	for (i = 1;i <= n;i++)
	{
		if (c[i] > 50 && !v[i])
		{
			dfs(i);
		}
	}
}
int main()
{
	freopen("concom.in","r",stdin);
	freopen("concom.out","w",stdout);
	int i,j,a,b,p,m;
	scanf("%d",&m);
	for (i = 0;i < m;i++)
	{
		scanf("%d %d %d",&a,&b,&p);
		g[a][b] = p;
		n = (a > n) ? a: n;
		n = (b > n) ? b :n;
	}

	for (i = 1;i <= n;i++)
	{
		for (j = 0;j <= n;j++)
		{
			c[j] = 0;
			v[j] = 0;
		}
		dfs(i);
		for (j = 1;j <= n;j++)
		{
			if (i != j && c[j] > 50)
			{
				printf("%d %d\n",i,j);
			}
		}
	}
}
