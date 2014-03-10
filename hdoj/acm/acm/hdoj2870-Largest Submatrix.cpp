#include <iostream>
#include <cstdio>

using namespace std;

int g[1001][1001][3];//0-a,1-b,2-c
int f[1001][1001];
int l[1001],r[1001];
int n,m;
char ch;

int main()
{
	while (scanf("%d%d",&n,&m) != EOF)
	{
		for (int i = 0;i < n;i++)
			for (int j = 0;j < m;j++)
				g[i][j][0] = g[i][j][1] = g[i][j][2] = 0;

		for (int i = 0;i < n;i++)
		{
			scanf("%c",&ch);
			for (int j = 0;j < m;j++)
			{
				scanf("%c",&ch);
				switch(ch)
				{
				case 'a':g[i][j][0]++;break;
				case 'b':g[i][j][1]++;break;
				case 'c':g[i][j][2]++;break;
				case 'w':g[i][j][0]++;g[i][j][1]++;break;
				case 'x':g[i][j][1]++;g[i][j][2]++;break;
				case 'y':g[i][j][0]++;g[i][j][2]++;break;
				case 'z':g[i][j][0]++;g[i][j][1]++;g[i][j][2]++;break;
				default:break;
				}
			}
		}
		int ans = 0;
		for (int k = 0;k < 3;k++)
		{
			for (int i = 1;i < n;i++)
				for (int j = 0;j < m;j++)
				{
					if (g[i][j][k] > 0)
						g[i][j][k] += g[i - 1][j][k];
				}
			for (int i = 0;i < n;i++)
			{
				l[0] = 0;
				r[m - 1] = m - 1;
				int tem;
				for (int j = 1;j < m;j++)
				{
					tem = j;
					while (tem > 0 && g[i][j][k] <= g[i][tem - 1][k])
						tem = l[tem - 1];
					l[j] = tem;
				}
				for (int j = m - 2;j >= 0;j--)
				{
					tem = j;
					while (tem < m - 1 && g[i][j][k] <= g[i][tem + 1][k])
						tem = r[tem + 1];
					r[j] = tem;
				}
				for (int j = 0;j < m;j++)
					if ((r[j] - l[j] + 1) * g[i][j][k] > ans)
						ans = (r[j] - l[j] + 1) * g[i][j][k];
			}
		}
		printf("%d\n",ans);
	}
}