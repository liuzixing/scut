#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;


int main()
{
	int f[101][100] = {0};
	int i,j,n,r = 0,temp = 0,len = 1;
	f[1][0] = 1;
	for (i = 2;i < 101;i++)
	{
		for (j = 0;j < len;j++)
		{
			f[i][j] = f[i - 1][j] * (4 * i - 2);
		}
		for (j = 0;j < len;j++)
		{
			temp = f[i][j]  + r;
			f[i][j] = temp % 10;
			r = temp / 10;
		}
		while (r)
		{
			f[i][len] = r % 10;
			r /= 10;
			len ++;
		}
		//
		for (j = len - 1,r = 0;j >= 0;j--)
		{
			temp = r * 10 + f[i][j];
			f[i][j] = temp / ( i + 1);
			r = temp % (i + 1);
		}
		while (!f[i][len - 1])
		{
			len--;
		}
	}
	while (scanf("%d",&n)  && n != -1)
	{
		for (i = 99;!f[n][i];i--);
		for (;i >= 0;i--)
		{
			printf("%d",f[n][i]);
		}
		printf("\n");
	}

}