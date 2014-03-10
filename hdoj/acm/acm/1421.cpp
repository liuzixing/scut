#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
__int64 w[2001],f[2001][1000];
int main()
{
	int i,j,n,k;
	while (scanf("%d %d",&n,&k) != EOF)
	{
		for (i = 1;i <= n;i++)
		{
			scanf("%I64d",&w[i]);
		}
		for (i = 0;i <= n;i++)
		{
			for (j = 1;j <= k;j++)
			{
				f[i][j] = 200000000;
			}
		}
		sort(w + 1,w + n + 1);
		for (i = 2;i <= n;i++)
		{
			for (j = 1;j * 2 <= i;j++)
			{
				f[i][j] = min(f[i - 1][j],f[i - 2][j - 1] + (w[i] - w[i - 1]) * (w[i] - w[i - 1]));
			}
		}
		printf("%I64d\n",f[n][k]);
	}
}