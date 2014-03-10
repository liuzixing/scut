#include <iostream>
#include <stdio.h>
using namespace std;

int judge (int x)
{
	int k = 1;
	while (x)
	{
		if (x % 10 == 4 || x % 100 == 62)
		{
			return k;
		}
		x /= 10;
		k *= 10;
	}
	return 0;
}
int main()
{
	int *a = new int[1000000];
	int n,m,i,j,up,count;
	a[0] = 0;
	for (i = 1,count = 0;i < 1000000;i += up)
	{
		up = judge(i);
		if (!up)
		{
			count++;
			up = 1;
		}
		for (j = 0;j < up;j++)
		{
			a[i + j] = count;
		}
	}
	while (scanf("%d %d",&n,&m) && n + m)
	{
		printf("%d\n",a[m] - a[n - 1]);
	}
}