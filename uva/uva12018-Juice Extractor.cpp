#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <cstdio>
#include <memory>

using namespace std;

struct node
{
	int x,y;
}a[1005];
int n,dp[1005];
bool cmp(node x,node y)
{
	return x.x < y.x;
}
int main()
{
	int cas = 0,t,ans;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (int i = 0;i < n;i++)
			scanf("%d%d",&a[i].x,&a[i].y);
		sort(a,a + n,cmp);
		fill(dp,dp + n,0);
		ans = 0;
		for (int i = 2;i < n;i++)
		{
			if (i + 1 < n && a[i].x == a[i + 1].x) continue;
			int tem = 1;
			for (int j = i - 1;j >= 0;j--)
			{
				if (a[j].x <= a[i].x && a[j].y >= a[i].x)
					tem++;
				int tem2 = tem;
				if (tem2 < 3)
					tem2 = 0;
				if (j == 0)
					dp[i] = max(dp[i],tem2);
				else
					dp[i] = max(dp[i],dp[j - 1] + tem2);
				ans = max(ans,dp[i]);
			}
		}
		printf("Case #%d: %d\n",++cas,ans);
	}
}