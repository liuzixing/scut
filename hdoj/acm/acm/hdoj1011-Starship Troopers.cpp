#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;


struct node
{
	int bugs,p;
}a[101];
int dp[101][101],n,m;
vector <int> v[101];

void tree_dp(int x,int last)
{
	int i,j,num,next,k;
	num = (a[x].bugs + 19) / 20;
	for (i = num;i <= m;i++)
		dp[x][i] = a[x].p;
	for (i = 0;i < v[x].size();i++)
	{
		next = v[x][i];
		if (next == last)
			continue;//不能等于上一间房
		tree_dp(next,x);
		for (j = m;j >= num;j--)
			for (k = 1;k <= m;k++)
			{
				if (j - k >= num)
					dp[x][j] = max(dp[x][j], dp[x][j-k] + dp[next][k]);
				else 
					break;
			}
	}
}
int main()
{
	int x,y,i;
	while (scanf("%d%d",&n,&m) != EOF)
	{
		if (n == -1 && m == -1)
			break;
		memset(dp,0,sizeof dp);
		for (i = 0;i <= n;i++)
			v[i].clear();
		for (i = 1;i <= n;i++)
			scanf("%d%d",&a[i].bugs,&a[i].p);
		for (i = 1;i < n;i++)
		{
			scanf("%d%d",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		if (m == 0)
		{
			cout << 0 << endl;
			continue;
		}
		tree_dp(1,-1);
		printf("%d\n",dp[1][m]);
	}
}