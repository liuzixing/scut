#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;
long long m;
int n;

map<long long,long long> dp[45];

long long gcd(long long a,long long b)
{
	return b == 0 ? a:gcd(b,a % b);
}
long long lcm(long long a,long long b)
{
	return a * b /gcd(a,b);
}
void DP()
{
	dp[1][1] = 1;
	for (int i = 2;i <= 40;i++)
	{
		dp[i] = dp[i - 1];
		dp[i][i] += 1;
		for (map<long long,long long>::iterator j = dp[i - 1].begin();j != dp[i - 1].end();j++)
		{
			long long lc = lcm(i,j->first);
			dp[i][lc] += j->second;
		}
	}
}
void solve()
{
	long long  ans = 0;
	for (map<long long,long long>::iterator i = dp[n].begin();i != dp[n].end();i++)
		if (i->first >= m)
			ans += i->second;
	cout << ans << endl;
}
int main()
{
	int T,cas = 0;
	DP();
	scanf("%d",&T);
	while (T--)
	{
		cin >> n >> m;
		printf("Case #%d: ",++cas);
		solve();
	}
}