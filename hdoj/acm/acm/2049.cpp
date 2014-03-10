#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int t,m,n,i,j;
	__int64 f[21],c[21][21];
	f[1] = 0;f[2] = 1;
	for (i = 3;i < 21;i++)
	{
		f[i] = (i - 1) * (f[i - 1] + f[i - 2]);
	}
	for (i = 1;i < 21;i++)
	{
		c[i][1] = i;
		for (j = 2;j <= i;j++)
		{
			c[i][j] = c[i][j - 1] * (i - j + 1) / j;
		}
	}

	cin >> t;
	while (t--)
	{
		scanf("%d %d",&n,&m);
		printf("%I64d\n",f[m] * c[n][m]);
	}
}