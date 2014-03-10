#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;
struct coordinate
{
	double x,y;
} g[100001];

bool cmp(coordinate a,coordinate b)
{
	if (a.x != b.x)
	{
		return a.x < b.x;
	}
	else
	{
		return a.y < b.y;
	}
}

double getmin(double a,double b)
{
	if (a < b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

double getdistance(coordinate a,coordinate b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double dfs(int l,int r)
{
	if (r - l == 2)
	{
		return (getmin(getdistance(g[l],g[l + 1]),getdistance(g[r],g[l + 1])));
	}
	if (r - l == 1)
	{
		return getdistance(g[l],g[r]);
	}
	int i,j,mid = (l + r) >> 1;
	double curmin = getmin(dfs(l,mid),dfs(mid + 1,r));
	for (i = l;i <= r;i++)
	{
		for (j = i + 1;j <= i + 7 && j <= r;j++)
		{
			curmin = getmin(curmin,getdistance(g[i],g[j]));
		}
	}
	return curmin;
}
int main()
{
	int n,i;
	while (cin >> n && n)
	{
		for (i = 0;i < n;i++)
		{
			scanf("%lf %lf",&g[i].x,&g[i].y);
		}
		sort(g,g + n,cmp);
		printf("%.2lf\n",dfs(0,n - 1) / 2.0);
	}
}