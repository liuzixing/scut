/*
ID: benbenq1
PROG: subset
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

int main()
{
	freopen("subset.in","r",stdin);
	freopen("subset.out","w",stdout);
	int n,m,i,j;
	long long int f[40][400] = {0};
	scanf("%d",&n);
	m = n * (n + 1) / 2;
	if (m % 2)
	{
		printf("0\n");
		return 0;
	}
	m /= 2;
	f[1][0] = 1;
	f[1][1] = 1;
	for (i = 2;i <= n;i++)
	{
		for (j = 0;j <= m;j++)
		{
			if (j - i >= 0)
			{
				f[i][j] = f[i - 1][j] + f[i - 1][j - i];
			}
			else
			{
				f[i][j] = f[i - 1][j];
			}
		}
	}
	printf("%lld\n",f[n][m] / 2);
}