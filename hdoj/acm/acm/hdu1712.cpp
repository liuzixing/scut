#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int a[101][101],dp[101][101];
int n,m;
int main()
{
	while (~scanf("%d%d",&n,&m) && (n || m)){
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= m;j++)
			{
				scanf("%d",&a[i][j]);
				dp[i][j] = 0;
				for (int k = 0;k <= j;k++)
					if (dp[i][j] < dp[i - 1][k] + a[i][j - k])
						dp[i][j] = dp[i - 1][k] + a[i][j - k];
			}
			printf("%d\n",dp[n][m]);
	}
}