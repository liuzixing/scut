#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int n,hire,salary,fire,worker[13],maxneed,ans;
int dp[13][1000];
int main()
{
	int i,j,k;
	while (scanf("%d",&n) != EOF && n)
	{
		maxneed = 0;
		memset(dp,127,sizeof dp);
		scanf("%d%d%d",&hire,&salary,&fire);
		for (i = 1;i <= n;i++)
		{
			scanf("%d",&worker[i]);
			maxneed = max(maxneed,worker[i]);
		}
		dp[0][0] = 0;
		for (i = 1;i <= n;i++)
			for (j = worker[i];j <= maxneed;j++)
				for (k = worker[i - 1];k <= maxneed;k++)
				{
					if (j > k)
						dp[i][j] = min(dp[i - 1][k] + (j - k) * hire + j * salary,dp[i][j]);
					else
						dp[i][j] = min(dp[i - 1][k] + (k - j) * fire + j * salary,dp[i][j]);
				}
		ans = 1000000;
		for (i = worker[n];i <= maxneed;i++)
			ans = min(ans,dp[n][i]);
		printf("%d\n",ans);
	}
	return 0;
}