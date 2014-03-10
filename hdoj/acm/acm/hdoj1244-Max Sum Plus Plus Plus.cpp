#include <iostream>
#include <cstdio>
using namespace std;
const int M = 21;
const int N = 1001;
int len[M],sum[N],dp[N][M],maxdp[N][M];
int n,m;
int main()
{
	int i,j,ans;
	while (scanf("%d",&n) != EOF && n)
	{
		memset(dp,0,sizeof dp);
		memset(maxdp,0,sizeof maxdp);
		scanf("%d",&m);
		for (i = 1;i <= m;i++)
			scanf("%d",&len[i]);
		for (i = 1;i <= n;i++)
		{
			scanf("%d",&sum[i]);
			sum[i] += sum[i - 1];
		}
		for (j = 1;j <= m;j++)
			for (i = 1;i <= n;i++)
			{
				if (i - len[j] >= 0)
					dp[i][j] = maxdp[i - len[j]][j - 1] + sum[i] - sum[i - len[j]];
				maxdp[i][j] = max(maxdp[i - 1][j],dp[i][j]);
			}	
		ans = 0;
		for (i = 1;i <= n;i++)
			ans = max(ans,dp[i][m]);
		printf("%d\n",ans);
	}
}