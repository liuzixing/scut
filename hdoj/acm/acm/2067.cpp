#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int i,j,n,Case = 0;
	__int64 f[36][36];
	memset(f,0,sizeof(f));;
	f[0][0] = 1;
	for (i = 1;i <= 35;i++)
	{
		f[i][0] = 1;
		for (j = 1;j < i;j++)
		{
			f[i][j] = f[i - 1][j] + f[i][j - 1];
		}
		f[i][i] = f[i][i - 1];
	}
	while (cin >> n && n != -1)
	{
		Case++;
		printf("%d %d %I64d\n",Case,n,f[n][n] * 2);
	}
}