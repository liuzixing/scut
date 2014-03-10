#include <iostream>
#include <cstdio>

using namespace std;
int i,m,n,t,j,T;
const int N = 1005;
int  l[N],r[N],ans,g[N][N];
char c;
int main()
{
	cin >> T;
	while (T--)
	{
		ans = 0;
		cin >> m >> n;
		for (i = 0;i < m;i++)
		{
			for (j = 0;j < n;j++)
			{
				while (scanf("%c",&c))
				{
					if (c == 'R' || c == 'F')
						break;
				}
				if (c == 'R')
					g[i][j] = 0;
				else
					g[i][j] = 1;
			}
		}
		for (i = 1;i < m;i++)
			for (j = 0;j < n;j++)
			{
				if (g[i][j] > 0)
					g[i][j] += g[i - 1][j];
				else
					g[i][j] = 0;
			}

		for (i = 0;i < m;i++)
		{
			l[0] = 0;
			r[n - 1] = n - 1;
			for (j = 1;j < n;j++)
			{
				t = j;
				while (t > 0 && g[i][j] <= g[i][t - 1])
					t = l[t - 1];
				l[j] = t;
			}
			for (j = n - 2;j >= 0;j--)
			{
				t = j;
				while (t < n - 1 && g[i][j] <= g[i][t + 1])
					t = r[t + 1];
				r[j] = t;
			}	
			for (j = 0;j < n;j++)
				if ((r[j] - l[j] + 1) * g[i][j] > ans)
					ans = (r[j] - l[j] + 1) * g[i][j];
		}

		printf("%I64d\n",ans * 3);
	}

}