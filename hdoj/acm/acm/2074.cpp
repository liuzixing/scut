#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
int main()
{
	char g[81][81];
	char a[2];
	int i,j,n,t,nn;
	bool  flag = 0;
	while (scanf("%d %c %c",&n,a,a + 1) != EOF)
	{
		nn = n;
		if (flag)
		{
			putchar('\n');
		}
		int c = 0;
		while (n > 0)
		{
			c++;
			t = (n - 1) / 2 % 2;
			for (i = c;i < c + n;i++)
			{
				g[c][i] = a[t];
				g[c + n - 1][i] = a[t];
			}
			for (i = c + 1;i < c + n - 1;i++)
			{
				g[i][c] = a[t];
				g[i][n + c - 1] = a[t];
			}
			n-=2;
		}
		g[1][1] = ' ';g[1][nn] = ' ';g[nn][1] = ' ';g[nn][nn] = ' ';
		if (nn == 1)
		{
			g[1][1] = a[0];
		}
		for (i = 1;i <= nn;i++)
		{
			for (j =1;j <= nn;j++)
			{
				printf("%c",g[i][j]);
			}
			putchar('\n');
		}
		flag = 1;
	}
}