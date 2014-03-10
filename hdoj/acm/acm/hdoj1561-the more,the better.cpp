#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> a[201];
int dp[202][202],b[201];
bool v[201];
int n,m;

void tree_dp(int x)
{
	int j,next,k,i;
	v[x] = 1;
	for (i = 1;i <= m;i++)
		dp[x][i] = b[x];
	for (i = 0;i < a[x].size();i++)
		if (!v[a[x][i]])
		{
			tree_dp(a[x][i]);
			for (k = m;k >= 1;k--)
				for (j = 1;j < k;j++)
					dp[x][k] = max(dp[x][k],dp[x][k - j] + dp[a[x][i]][j]);
		}
}
int main()
{
	int i,x,y;
	while (scanf("%d%d",&n,&m) != EOF)
	{
		if (n == 0 && m == 0)
			break;
		memset(dp,0,sizeof dp);
		memset(v,0,sizeof v);
		for (i = 0;i <= n;i++)
			a[i].clear();
		for (i = 1;i <= n;i++)
		{
			scanf("%d%d",&x,&y);
			a[x].push_back(i);
			b[i] = y;
		}
		m++;
		tree_dp(0);
		printf("%d\n",dp[0][m]);
	}
}