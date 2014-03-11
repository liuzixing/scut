/*
ID: benbenq1
PROG: agrinet
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int n,g[101][101],shortest[101];
const int MAX = 0x7fffffff;
int prim(int v0)
{
	int i,j,mindist,minone,ans = 0;
	for (i = 1;i <= n;i++)
	{
		shortest[i] = g[v0][i];
	}
	for (i = 1;i < n;i++)
	{
		mindist = MAX;
		for (j = 1;j <= n;j++)
		{
			if (shortest[j] && mindist > shortest[j])
			{
				mindist = shortest[j];
				minone = j;
			}
		}
		ans += shortest[minone];
		shortest[minone] = 0;
		for (j = 1; j <= n;j++)
		{
			if (g[j][minone] < shortest[j])
			{
				shortest[j] = g[j][minone];
			}
		}
	}
	return ans;
}
int main()
{
	freopen ("agrinet.in","r",stdin);
	freopen ("agrinet.out","w",stdout);
	scanf("%d",&n);
	int i,j;
	for (i = 1;i <= n;i++)
	{
		for (j = 1;j <= n;j++)
		{
			scanf("%d",&g[i][j]);
		}
	}
	printf("%d\n",prim(1));

}