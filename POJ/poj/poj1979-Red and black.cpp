#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};
char g[21][21];
int v[21][21],w,h,ans,x,y,i,j;
void dfs(int x,int y)
{
	int i,tx,ty;
	for (i = 0;i < 4;i++)
	{
		tx = dx[i] + x;
		ty = dy[i] + y;
		if (tx >= 0 && ty >= 0 && ty < w && tx < h && !v[tx][ty] && g[tx][ty] == '.')
		{
			v[tx][ty] = 1;
			ans++;
			dfs(tx,ty);
		} 
	}
}
int main()
{
	while (scanf("%d %d",&w,&h) != EOF && (w || h))
	{
		for (i = 0;i < h;i++)
		{
			scanf("%s",&g[i]);
			for (j = 0;j < w;j++)
				if (g[i][j] == '@')
				{
					x = i;
					y = j;
				}
		}
		memset(v,0,sizeof(v));
		ans = 1;
		v[x][y] = 1;

		dfs(x,y);
		printf("%d\n",ans);
	}
}