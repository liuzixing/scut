#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;

int prime[10000];
void createprime(int primev[],int prime[])
{
	int i,j;
	memset(primev,0,sizeof(int) * 65536);
	primev[1] = 1;
	for (i = 2;i < sqrt(65535.0);i++)
	{
		for (j = i * 2;j < 65536;j += i)
		{
			primev[j] = 1;
		}
	}
	j = 0;
	for (i = 1;i < 65536;i++)
	{
		if (!primev[i])
		{
			j++;
			prime[j] = i;
		}
	}
	prime[0] = j;
}
void dfs(int i,int x,int flag)
{
	if (x==0)
	{
		return;
	}
	int j;
	for (j = i;j > 0;j--)
	{
		if (x % prime[j] == 0)
		{
			dfs(j,x  / prime[j],flag + 1);
			if (!flag)
			{
				printf("%d",prime[j]);
			}
			else
			{
				printf("%d*",prime[j]);
			}
			return;
		}
	}
}

int main()
{
	int primev[65536],x;
	createprime(primev,prime);

	while (cin >> x)
	{
		dfs(prime[0],x,0);
		printf("\n");
	}
}