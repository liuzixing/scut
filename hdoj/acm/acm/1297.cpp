#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int f[1001][1001];
void add(int a[],int b[],int c[])
{
	int i,len;
	len = a[0] > b[0] ?a[0] : b[0];
	for (i = 1;i < len + 3;i++)
	{
		c[i] = 0;
	}
	for (i = 1;i <= len;i++)
	{
		c[i] += a[i] + b[i];
		if(c[i] >= 10)
		{
			c[i] -= 10;
			c[i + 1]++;
		}
	}
	if (c[i] > 0)
	{
		len++;
	}
	c[0] = len;
	return;
}
int main()
{
	int t[1001];
	int n;
	f[1][0] = 1;
	f[1][1] = 1;
	f[2][0] = 1;
	f[2][1] = 2;
	f[3][0] = 1;
	f[3][1] = 4;
	f[4][0] = 1;
	f[4][1] = 7;
	int i = 5;
	while (i <= 1000)
	{
		add(f[i - 2],f[i - 1],t);
		add(t,f[i - 4], f[i]);
		i++;
	}
	while (scanf("%d",&n) != EOF)
	{
		for (i = f[n][0];i > 0;i--)
		{
			printf("%d",f[n][i]);
		}
		printf("\n");
	}
}