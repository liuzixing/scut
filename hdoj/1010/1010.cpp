#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>
using namespace std;
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,1,0,-1};
int n,m,t,ex,ey;
bool flag;
char g[10][10];
void dfs(int x, int y,int step)
{
	if (flag)
		return;
	if (x == ex && y == ey && step == t)
	{
		flag = true;
		return;
	}
	int judge = (t - step) - abs(ex - x) - abs(ey - y);
	if (judge < 0 || judge % 2 == 1)
		return;
	int i,nextx,nexty;
	for (i = 0;i < 4;i++)
	{
		nextx = x + dx[i];
		nexty = y + dy[i];
		if (nextx >= 0 && nextx < n && nexty >= 0 && nexty < m && g[nextx][nexty] != 'X')
		{
			g[nextx][nexty] = 'X';
			dfs(nextx,nexty,step + 1);
			g[nextx][nexty] = '.';
		}
	}
	return;
}
int main()
{
	int i,j,sx,sy;
	while (cin >> n >> m >>t && m != 0 && n != 0 && t != 0)
	{
		flag = false;
		int count = 0;
		for (i = 0 ;i < n;i++)
		{
			for (j = 0;j < m;j++)
			{
				cin >> g[i][j];
				if (g[i][j] == 'S')
				{
					sx = i;
					sy = j;
				}
				if (g[i][j] == 'X')
					count++;
				if (g[i][j] == 'D')
				{
					ex = i;
					ey = j;
				}
			}
		}
		if  (n * m - count <= t)
		{
			cout << "NO" << endl;
			continue;
		}
		g[sx][sy] = 'X';
		dfs(sx,sy,0);
		if (!flag)
			printf("NO\n");
		else
			printf("YES\n");
	}
}
