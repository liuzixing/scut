/*
ID: benbenq1
LANG: C++
TASK: milk3
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <climits>
#include <vector>
using namespace std;
int f[21][21] = {0};
int a,b,c;

void dfs(int a1,int b1)
{
	f[a1][b1] = 1;
	int c1;
	c1 = c - a1 - b1;
	//c->b,c->a
	if (c1 > 0  && a1 < a)
	{
		if (a - a1 <= c1 && !f[a][b1])
		{
			dfs(a,b1);
		}
		if (a - a1 > c1 && !f[c - b1][b1])
		{
			dfs(c - b1,b1);
		}
	}
	if (c1 > 0 && b1 < b)
	{
		if (b - b1 <= c1 && !f[a1][b])
		{
			dfs(a1,b);
		}
		if (b - b1 > c1 && !f[a1][c - a1])
		{
			dfs(a1,c - a1);
		}
	}
	//b->c,b->a
	if (b1 > 0  && !f[a1][0])
	{
		dfs(a1,0);
	}
	if (b1 > 0 && a1 < a)
	{
		if (b1 >= a - a1 && !f[a][c - c1 - a])
		{
			dfs(a,c - c1 - a);
		}
		if (b1 < a - a1 && !f[a1 + b1][0])
		{
			dfs(a1 + b1,0);
		}
	}
	//a->b,a->c
	if (a1 > 0 && !f[0][b1])
	{
		dfs(0,b1);
	}
	if (a1 > 0 && b1 < b)
	{
		if (a1 <= b - b1 && !f[0][b1 + a1])
		{
			dfs(0,a1 + b1);
		}
		if (a1 > b - b1 && !f[c - b - c1][b])
		{
			dfs(c - b - c1,b);
		}
	}
}
int main()
{
	int i,ans[20],n = 0;
	freopen("milk3.in","r",stdin);
	freopen("milk3.out","w",stdout);
	scanf("%d %d %d",&a,&b,&c);
	dfs(0,0);
	for (i = b;i >= 0;i--)
	{
		if (f[0][i])
		{
			ans[n++] = c - i;
		}
	}
	for (i = 0;i < n - 1;i++)
	{
		printf("%d ",ans[i]);
	}
	printf("%d\n",ans[i]);
}