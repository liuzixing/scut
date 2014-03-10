#include <iostream>
#include <stdio.h>

using namespace std;
int main()
{
	int m,n,i,j;
	__int64 f[21][21];
	memset(f,0,sizeof(f));
	for (i = 0;i <= 20;i++)
	{
		f[i][0] = 1;
		f[0][i] = 0;
	}
	for (i = 1;i <= 20;i++)
	{
		for (j = 1;j <= 20;j++)
		{
			if (i < j)
			{
				f[i][j] = 0;
			}
			else
			{
				f[i][j] = f[i - 1][j] + f[i][j - 1];
			}
		}
	}
	while (scanf("%d %d",&m,&n) != EOF)
	{
		printf("%I64d\n",f[m][n]);
	}
}