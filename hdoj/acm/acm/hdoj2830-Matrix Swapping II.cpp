#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;
int i,m,n,t,j;
const int N = 1005;
int  num[N],ans,g[N][N];
char c;
int main()
{
	while (cin >> n >> m)
	{
		ans = 0;
		for (i = 0;i < n;i++)
		{
			for (j = 0;j < m;j++)
			{
				while (scanf("%c",&c))
				{
					if (c == '1' || c == '0')
						break;
				}
				if (c == '0')
					g[i][j] = 0;
				else
					g[i][j] = 1;
			}
		}
		for (i = 1;i < n;i++)
			for (j = 0;j < m;j++)
			{
				if (g[i][j] > 0)
					g[i][j] += g[i - 1][j];
				else
					g[i][j] = 0;
			}

			for (i = 0;i < n;i++)
			{
				memset(num,0,sizeof num);
				for (j = 0;j < m;j++)
					num[g[i][j]]++;
				for (j = 999;j >= 0;j--)
					num[j] += num[j + 1];
				for (j = 0;j < m;j++)
					if (num[g[i][j]] * g[i][j] > ans)
						ans = num[g[i][j]] * g[i][j];
			}

			printf("%I64d\n",ans);
	}

}