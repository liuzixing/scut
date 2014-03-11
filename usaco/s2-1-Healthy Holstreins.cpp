/*
ID: benbenq1
PROG: holstein
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int b[15],path[15],t = 1,cal = 16,tp[15],tc;
int n,a[25],m,g[15][25];

bool check(int x)
{
	int i,j,k,tem[25] = {0};
	for (i = 0;i < m;i++)
	{
		if (x & b[i])
		{
			tp[tc] = i + 1;
			tc++;
			for (j = 0;j < n;j++)
			{
				tem[j] += g[i][j];
			}
		}
	}
	tc--;
	for (i = 0;i < n;i++)
	{
		if (tem[i] < a[i])
		{
			return 0;
		}
	}
	return 1;
}

void output()
{
	int i;
	printf("%d ",cal + 1);
	for (i = 0;i <= cal - 1;i++)
	{
		printf("%d ",path[i]);
	}
	printf("%d\n",path[i]);
}
int main()
{
	freopen("holstein.in","r",stdin);
	freopen("holstein.out","w",stdout);
	int i,j;
	b[0] = 1;
	for (i = 1;i < 15;i++)
	{
		b[i] = b[i - 1] * 2;
	}
	scanf("%d",&n);
	for (i = 0;i < n;i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&m);
	for (i = 1;i <= m;i++)
	{
		t *= 2;
	}
	for (i = 0;i < m;i++)
	{
		for (j = 0;j < n;j++)
		{
			scanf("%d",&g[i][j]);
		}
	}

	for (i = 1;i < t;i++)
	{
		tc = 0;
		if (check(i) && tc < cal )
		{
			cal = tc;
			for (j = 0;j <= cal;j++)
			{
				path[j] = tp[j];
			}
		}
	}
	output();
}