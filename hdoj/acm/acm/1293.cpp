#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int f[1001][1000] = {0};
int main()
{
	
	int i,j,n,r = 0,temp = 0;
	f[1][0] = 1;
	f[1][1] = 3;
	f[2][0] = 1;
	f[2][1] = 7;
	for (i = 3;i < 1001;i++)
	{
		f[i][0] = f[i - 1][0];
		for (j = 1;j <= f[i][0];j++)
		{
			f[i][j] = f[i - 1][j] * 2;
		}
		r = 0;
		for (j = 1;j <= f[i][0];j++)
		{
			temp = f[i][j]  + r;
			f[i][j] = temp % 10;
			r = temp / 10;
		}
		while (r)
		{
			f[i][f[i][0] + 1] = r % 10;
			r /= 10;
			f[i][0] ++;
		}
		//
		for (j = 1;j < f[i][0] + 3;j++)
		{
			r = f[i][j] + f[i - 2][j];
			f[i][j] = r % 10;
			f[i][j + 1] += r /10;
		}
		f[i][0] += 2;
		while (f[i][f[i][0]] == 0)
		{
			f[i][0]--;
		}
	}
	while (scanf("%d",&n)  != EOF)
	{
		for (i = f[n][0];i > 0;i--)
		{
			printf("%d",f[n][i]);
		}
		printf("\n");
	}

}