/*
ID: benbenq1
PROG: hamming
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;
int n,b,d,ans[65],len = 1,over;

bool check(int a,int b)
{
	int x = a ^ b;
	x = (x & 0x55555555) + ((x >> 1) & 0x55555555); 
	x = (x & 0x33333333) + ((x >> 2) & 0x33333333); 
	x = (x & 0x0F0F0F0F) + ((x >> 4) & 0x0F0F0F0F); 
	x = (x & 0x00FF00FF) + ((x >> 8) & 0x00FF00FF); 
	x = (x & 0x0000FFFF) + ((x >> 16) & 0x0000FFFF); 
	if (x >= d)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void dfs(int x)
{
	int i;
	bool flag = 1;
	for (i = 1;i <= len;i++)
	{
		if (!check(ans[i],x))
		{
			flag = 0;
			break;
		}
	}
	if (flag)
	{
		len++;
		ans[len] = x;
		if (len == n)
		{
			for (i = 1;i <= n;i++)
			{
				printf("%d",ans[i]);
				if (i % 10 == 0 || i == n)
				{
					printf("\n");
				}
				else
				{
					printf(" ");
				}
			}
			exit(0);
		}
		for (i = x + 1;i < b;i++)
		{
			dfs(i);
		}
	}
}
int main()
{
	int i;
	freopen("hamming.in","r",stdin);
	freopen("hamming.out","w",stdout);
	scanf("%d %d %d",&n,&b,&d);
	b = 1 << b;
	for (i = 1;i < b;i++)
	{
		dfs(i);
	}
}