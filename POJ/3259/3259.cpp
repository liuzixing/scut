#include <iostream>
#include <stdio.h>
using namespace std;
int n,m,w,total;
struct sp
{
	int s,e,t;
} g[6000];
int d[501];
bool bellman_ford()
{
	int i,j;

	for (i = 0;i < n;i++)
	{
		for (j = 0;j < total; j++)
		{
			if (d[g[j].e] > d[g[j].s] + g[j].t)
			{
				d[g[j].e] = d[g[j].s] + g[j].t;
			}
		}
	}
	for (j = 0;j < total; j++)
	{
		if (d[g[j].e] > d[g[j].s] + g[j].t)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	int f,s,e,t,i;
	scanf ("%d",&f);
	while (f)
	{
		f--;
		total = 0;
		scanf ("%d%d%d",&n,&m,&w);
		for (i = 0;i < m;i++)
		{
			scanf("%d%d%d",&s,&e,&t);
			g[total].s = s;g[total].e = e;g[total].t = t;
			total++;
			g[total].s = e;g[total].e = s;g[total].t = t;
			total++;
		}
		for (i = 0;i < w;i++)
		{
			scanf("%d%d%d",&s,&e,&t);
			g[total].s = s;g[total].e = e;g[total].t = -t;
			total++;
		}
		memset(d,127,sizeof(d));
		if (bellman_ford())
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}