#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int p[1001],n,m;
int v[11][11],b[11][11];
int f[1100][11],s[1100][1100],person[1100],bonus[1100],interest[1100][12];
int nmax,res;

int check(int x)
{
	int ans = 0;
	for (int i = 0;i < n - 1;i++)
		for (int j = i + 1;j < n;j++)
			if (((1 << i) & x) && ((1 << j) & x))
				ans += b[i + 1][j + 1];
	return ans;
}
int check2(int x,int y)
{
	int ans = 0;
	for (int i = 0;i < n;i++)
		if ((1 << i) & x)
			ans += v[i + 1][y];
	return ans;
}
int check3(int x)
{
	int ans = 0;
	for (int i = 0;i < n;i++)
		if ((1 << i)& x)
			ans += 1;
	return ans;
}
bool pd(int x,int y)
{
	return ((x & y) == y);
}
int main()
{
	while (scanf("%d%d",&n,&m) != EOF)
	{
		if (n == 0 && m == 0) break;
		res = -100000000;
		for (int i = 1;i <= m;i++)
			scanf("%d",&p[i]);
		for (int i = 1;i <= n;i++)
			for (int j = 1; j <= m;j++)
				scanf("%d",&v[i][j]);
		for (int i = 1;i <= n;i++)
			for (int j = 1; j <= n;j++)
				scanf("%d",&b[i][j]);
		nmax = 1 << n;
		for (int i = 0;i < nmax;i++)
		{
			s[i][0] = 0;
			for (int j = 0;j < nmax;j++)
				if (pd(i,j))
					s[i][++s[i][0]] = j;
			bonus[i] = check(i);
			for (int j = 1;j <= m;j++)
				interest[i][j] = check2(i,j);
			person[i] = check3(i);
		}
		for (int i = 0;i <= m;i++)
			for (int j = 0;j <= nmax;j++)
				f[j][i] = -10000000;
		for (int i = 0;i < nmax;i++)
		{
			f[i][1] = bonus[i] + interest[i][1] - p[1] * person[i];
			res = max(res,f[i][1]);
		}

		for (int k = 2;k <= m;k++)
			for (int i = 0;i < nmax;i++)
				for (int j = 1;j <= s[i][0] ;j++)
				{
					f[s[i][j]][k] = max(f[s[i][j]][k],f[i][k - 1] + bonus[s[i][j]] + interest[s[i][j]][k] - p[k] * person[s[i][j]]);
					res = max(res,f[s[i][j]][k]);
				}
		if (res <= 0)
			printf("STAY HOME\n");
		else
			printf("%d\n",res);
	}
}