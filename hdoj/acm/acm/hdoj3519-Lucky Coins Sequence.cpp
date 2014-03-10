#include <iostream>
#include <stdio.h>

void multiply(int a[3][3],int b[3][3])
{
	int t[3][3];
	int i,j,k;
	memset(t,0,sizeof(t));
	for (i = 0;i < 3;i++)
	{
		for (j = 0;j < 3;j++)
		{
			for (k = 0;k < 3;k++)
			{
				t[i][j] += (a[i][k] * b[k][j]) % 10007;
			}
		}
	}
	for (i = 0;i < 3;i++)
	{
		for (j = 0;j < 3;j++)
		{
			a[i][j] = t[i][j];
		}
	}
}

int main()
{
	int n,i,j;
	int t[3][3],ans[3][3];
	int a[5] = {0,0,0,2,6};
	while (scanf("%d",&n) != EOF)
	{
		if (n <= 4)
		{
			printf("%d\n",a[n]);
			continue;
		}
		t[0][0] = t[0][1] = t[0][2] = t[1][0] = 1;
		t[1][1] = t[1][2] = t[2][0] = t[2][1] = 0;
		t[2][2] = 2;
		for (i = 0;i < 3;i++)
		{
			for (j = 0;j < 3;j++)
			{
				ans[i][j] = (i == j)? 1: 0;
			}
		}
		n -= 4;
		while (n > 0)
		{
			if (n & 1)
			{
				multiply(ans,t);
				n--;
			}
			else
			{
				multiply(t,t);
				n /= 2;
			}
		}
		printf("%d\n",(ans[0][0] * 6 + ans[0][1] * 2 + ans[0][2] * 8) % 10007);
	}
}