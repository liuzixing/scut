#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int t, n, i ,j,f[400][400] = {0}, max = -100000;
	scanf("%d",&n);
	for (i = 1; i <= n;i++)
	{
		for (j = 1; j <= i;j++)
		{
			scanf("%d",&t);
			f[i][j] = (f[i - 1][j] > f[i - 1][j - 1]) ? f[i - 1][j] + t: f[i - 1][j - 1] + t;
			max = (max > f[i][j]) ? max : f[i][j];
		}
	}
	printf("%d\n",max);
}