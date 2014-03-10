#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int g,n,m,c,sum[22][1001];
int main()
{
	int i,j,k;
	scanf("%d",&c);
	while (c--)
	{
		memset(sum,0,sizeof(sum));
		scanf("%d %d",&n,&m);
		for (i = 1;i <= n;i++)
			sum[i][0] = -1000000000;
		for (i = 1;i <= m;i++)
			sum[0][i] = -1000000000;
		for (i = 1;i <= n;i++)
		{
			for (j = 1;j <= m;j++)
			{
				scanf("%d",&g);
				if (i == 1 && j == 1)
				{
					sum[1][1] = g;
					continue;
				}
				int t = -100000000;
				for (k = 1;k < j;k++)
					if (j % k == 0)
						t = max(t,sum[i][k]);

				t = max(t,sum[i][j - 1]);
				t = max(t,sum[i - 1][j]);
				sum[i][j] = t + g;
			}
		}
		printf("%d\n",sum[n][m]);
	}
}