#include <stdio.h>
#include <iostream>
using namespace std;
const double zero = 0.000000001;
int total = 0;
double v,dist[101];
struct station
{
	int a,b;
	double r,c;
}g[250];
bool bellman_ford(int source)
{
	int i;	
	bool flag;
	while(dist[source] <= zero + v)
	{
		flag = 1;
		for (i = 0; i < total;i++)
		{
			if (dist[g[i].b] + zero < (dist[g[i].a] - g[i].c) * g[i].r)
			{
				dist[g[i].b] = (dist[g[i].a] - g[i].c) * g[i].r;
				flag = 0;
			}
		}
		if (flag)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	int s,n,m,i,a,b;
	double r1,c1,r2,c2;
	scanf ("%d%d%d%lf",&n,&m,&s,&v);
	memset(dist,0.0,sizeof(dist));
	dist[s] = v;
	for (i = 0;i < m; i++)
	{
		scanf ("%d%d%lf%lf%lf%lf",&a,&b,&r1,&c1,&r2,&c2);
		g[total].a = a;g[total].b = b;g[total].r = r1;g[total].c = c1;
		total++;
		g[total].b = a;g[total].a = b;g[total].r = r2;g[total].c = c2;
		total++;
	}
	if (bellman_ford(s))
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}
