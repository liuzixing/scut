#include <iostream>
#include <stdio.h>
#include <cmath>
const int N = 10000;
int len = 1,ans[1001][100] = {0};
using namespace std;

void add(int *a,int *b,int *c)
{
	for (int i = 1;i < len + 2;i++)
	{
		if (i == 1)
		{
			c[i] += 1;
		}
		c[i] += a[i] + b[i];
		c[i + 1] += c[i] / N;
		c[i] = c[i] % N;
	}
	if (c[len + 1] > 0)
	{
		len++;
	}
	c[0] = len;
}
int main()
{
	int i,n;
	ans[1][0] = 1;
	ans[1][1] = 3;
	ans[0][0] = 1;
	ans[0][1] = 1;
	for (i = 2;i < 1001;i++)
	{
		add(ans[i - 1],ans[i - 1],ans[i]);
	}
	while (scanf("%d",&n) != EOF)
	{
		printf("%d",ans[n][ans[n][0]]);
		for (i = ans[n][0] - 1;i > 0;i--)
		{
			printf("%04d",ans[n][i]);
		}
		putchar('\n');
	}
}