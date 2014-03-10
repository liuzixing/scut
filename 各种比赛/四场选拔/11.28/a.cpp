#include <iostream>
#include <stdio.h>
using namespace std;
int n,m,l,g[110][110];
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,1,0,-1};
void dfs(int x, int y)
{
	int i,xt,yt;
	for (i =0;i <4;i++)
	{
		xt = x+dx[i];
		yt = x+dy[i];
		if ((xt <= n) &&(xt >0)&&(yt <=m)&&(yt >0))
		{
			g[xt][yt]++;
			it (g[xt][yt] == l)
			{
				g[xt][yt] = 0;
				dfs(x,y);
			} 
		}

	}
}
int main()
{
	int t,x,y,i,j,p;
	cin >>t;
	while(t)
	{
		t--;
		memset(g,0,sizeof(g));
		scanf("%d %d %d",&n,&m,&l);
		for (i = 1;i<=n;i++)
		{
			for (j = 1;j <= m;j++)
			{
				cin >>a[i][j];
			}
		}
		scanf("%d",&q);
        while (q)
		{
			q--;
			cin >> x >> y;
			g[x][y]++;
			it (g[x][y] == l)
			{
				g[x][y] =0;
				dfs(x,y);
			}
		}
	}
	
}