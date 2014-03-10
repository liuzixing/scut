#include <iostream>
#include <string.h>
#include <cstdio>
#include <cmath>

using namespace std;

int n,m,ans;
int dp[4][1000001];

int main()
{
	memset(dp,0,sizeof dp);
	for (int i = 0;i < 1000001;i++)
	{
		dp[0][i] = i + 1;
		dp[1][i] = i + 2;
		dp[2][i] = i + i + 3;
	}
	dp[3][0] = 5;
	for (int i = 1;i < 25;i++)
		dp[3][i] = 2 * dp[3][i - 1] + 3;
	while (scanf("%d%d",&m,&n) != EOF && n)
	{
		printf("%d\n",dp[m][n]);
	}
	return 0;
}
