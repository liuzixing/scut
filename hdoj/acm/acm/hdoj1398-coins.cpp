#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int i,j,f[301] = {0},x,k,n,t[301];
	f[0] = 1;
	for (i = 1;i <= 17;i++)
	{
		x = i * i;
		memset(t,0,sizeof(t));
		for (j = 0;j < 301;j ++)
		{
			if (f[j] != 0)
			{
				for (k = 0;k + j <= 300;k += x)
				{
					t[j + k] += f[j];
				}
			}
		}
		for (j = 0;j < 301;j++)
		{
			f[j] = t[j];
		}
	}
	while (scanf("%d",&n) != EOF && n)
	{
		printf("%d\n",f[n]);
	}
}