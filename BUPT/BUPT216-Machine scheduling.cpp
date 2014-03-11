#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;

long long  f[1001][1001],g[1001][1001];
int n,r,k,m;
const long long mod = 1000000007;
void init()
{
	int i,j;
	//C(n-s(k-1),k),
	//f是组合数
	for (i = 1;i <= 1000;i++)
	{
		f[1][i] = 1;
		f[i][1] = i;
	}
	for (i = 2;i <= 1000;i++)
		for (j = 2;j <= 1000;j++)
			f[i][j] = (f[i - 1][j] + f[i][j - 1]) % mod;
	//g[i][j]代表把i个数分成j组
	for (i = 1;i <= 1000;i++)
		g[i][1] = g[i][i] = 1;
	for (i = 2;i <= 1000;i++)
		for (j = 2;j <= i;j++)
			g[i][j] = (j * g[i - 1][j] + g[i - 1][j - 1]) % mod;
}
long long cal()
{
	long long sum = 0;
	for (long long i = 1;i <= m;i++)
		sum = (sum + g[r][i]) % mod; 
	return sum;
}
int main()
{
	init();
	while (scanf("%d%d%d%d",&n,&r,&k,&m) != EOF)
	{
		if (k * (r - 1) + 1 > n)
		{
			printf("0\n");
			continue;
		}
		printf("%lld\n",cal() * f[n - k * (r - 1)][r] % mod);
	}

}