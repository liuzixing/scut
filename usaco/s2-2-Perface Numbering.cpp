/*
ID: benbenq1
PROG: preface
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;
int g[10][2] = {0,0,
	            1,0,
				2,0,
				3,0,
				1,1,
				0,1,
				1,1,
				2,1,
				3,1,
				1,0
};
const char b[7] = {'I','V','X','L','C','D','M'};
int f[3501][7];
void work(int x)
{
	int i,t,tem;
	t = x;
	for (i = 0;i < 7;i++)
	{
		f[t][i] += f[t - 1][i];
	}
	while (x)
	{
		tem = x / 1000;
		if (tem)
		{
			f[t][6] += tem; 
			x %= 1000; 
		}
		tem = x / 100;
		if (tem)
		{
			for (i = 0;i < 2;i++)
			{
				f[t][i + 4] += g[tem][i];
			}
			if (tem == 9)
			{
				f[t][6]++;
			}
			x %= 100;
		}
		tem = x / 10;
		if (tem)
		{
			for (i = 0;i < 2;i++)
			{
				f[t][i + 2] += g[tem][i];
			}
			if (tem == 9)
			{
				f[t][4]++;
			}
			x %= 10;
		}
		if (x)
		{
			for (i = 0;i < 2;i++)
			{
				f[t][i] += g[x][i];
			}
			if (x == 9)
			{
				f[t][2]++;
			}
			x = 0;
		}
	}
}
void init()
{
	int i;
	for (i = 1;i <= 3500;i++)
	{
		work(i);
	}
}
void output(int n)
{
	int i;
	for (i = 0;i < 7;i++)
	{
		if (f[n][i])
		{
			printf("%c %d\n",b[i],f[n][i]);
		}
	}
}
int main()
{
	freopen("preface.in","r",stdin);
	freopen("preface.out","w",stdout);
	int n;
	init();
	scanf("%d",&n);
	output(n);
}