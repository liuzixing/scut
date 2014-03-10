#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 70000;
int b[32];
double f[maxn];
int n,t;
double g[32][32];
double dp(int x)
{
	if (x == 0 || f[x] > -1e10)
		return f[x];
	int i = 1,j,a[17];
	a[0] = 0;
	while (i <= n )
	{
		if (b[i] & x)
			a[++a[0]] = i;
		i++;
	}
	for (j = 2;j <= a[0];j++)
		f[x] = max(f[x],dp(x - b[a[1]] - b[a[j]]) + g[a[1]][a[j]]);
	return f[x];
}
int main()
{
	int i,j;
	b[1] = 1;
	for (i = 2;i <= 17;i++)
		b[i] = b[i - 1] * 2;
	scanf("%d",&t);
	while (t--)
	{
		f[0] = 0;
		scanf("%d",&n);
		for (i = 1;i <= b[n + 1] - 1;i++)
			f[i] = -1e10;
		for (i = 1;i <= n;i++)
			for (j = 1;j <= n;j++)
				scanf("%lf",&g[i][j]);
		printf("%.2lf\n",dp(b[n + 1] - 1));
	}
}