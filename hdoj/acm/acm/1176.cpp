#include <iostream>
#include <stdio.h>

using namespace std;
int f[100001][11];
int main()
{
	int n,i,j,x,t,max,ans,temp,temp2;
	while (cin >> n && n)
	{
		memset(f,0,sizeof(f));
		for (i = 0,max = 0;i < n;i++)
		{
			scanf("%d %d",&x,&t);
			f[t][x]++;
			if (t > max)
			{
				max = t;
			}
		}
		ans = 0;
		for (i = 4;i <= 6;i++)
		{
			ans = (f[1][i] > ans) ? f[1][i] : ans;
		}
		for (i = 2;i <= max;i++)
		{
			for (j = 0;j < 11;j++)
			{
				if (j == 0)
				{
					temp = f[i - 1][j] > f[i - 1][j + 1] ? f[i - 1][j] : f[i - 1][j + 1];
				}
				else
				{
					if (j == 10)
					{
						temp = f[i - 1][j] > f[i - 1][j - 1] ? f[i - 1][j] : f[i - 1][j - 1];
					}
					else
					{
						temp2 = f[i - 1][j - 1] > f[i - 1][j] ? f[i - 1][j - 1] : f[i - 1][j];
						temp = f[i - 1][j + 1] > temp2 ? f[i - 1] [j + 1] : temp2;
					}
				}
				f[i][j] += temp;
				ans = (ans < f[i][j]) ? f[i][j] : ans;
			}
		}
		printf("%d\n",ans);
	}
}