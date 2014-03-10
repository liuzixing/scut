/*
ID: benbenq1
LANG: C++
TASK: castle
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <climits>
#include <vector>
#include <memory>
using namespace std;
int g[51][51],n,m,maxsize = -1,numroom,largest = 0,x,y,cal;
bool v[51][51] = {0};
char dirction;
const int d[4] = {1,2,4,8};
const int dx[4] = {0,-1,0,1};
const int dy[4] = {-1,0,1,0};
void dfs1(int xx,int yy)
{
	int i;
	for (i = 0;i < 4;i++)
	{
		if (!(d[i] & g[xx][yy]) && !v[xx + dx[i]][yy + dy[i]])
		{
			v[xx + dx[i]][yy + dy[i]] = 1;
			cal++;
			dfs1(xx + dx[i],yy + dy[i]);
		}
	}
}
void dfs2(int xx,int yy)
{
	int i,xt,yt;
	for (i = 0;i < 4;i++)
	{
		if (!(d[i] & g[xx][yy]))
		{
			xt = xx + dx[i];
			yt = yy + dy[i];
			if (xt > 0 && xt <= n && yt > 0 && yt <= m && !v[xt][yt])
			{
				v[xt][yt] = 1;
				cal ++;
				dfs2(xt,yt);
			}
			
		}
	}
}
int main()
{
	freopen("castle.in","r",stdin);
	freopen("castle.out","w",stdout);
	int i,j;
	scanf("%d %d",&m,&n);
	for (i = 1;i <= n;i++)
	{
		for (j = 1;j <= m;j++)
		{
			scanf("%d",&g[i][j]);
		}
	}

	for (i = 1;i <= n;i++)
	{
		for (j = 1;j <= m;j++)
		{
			if (!v[i][j])
			{
				cal = 1;
				numroom++;
				v[i][j] = 1;
				dfs1(i,j);
				
				if (cal > maxsize)
				{
					maxsize = cal;
				}
			}
		}
	}
	for (i = 1;i <= m;i++)
	{
		for (j = n;j > 0;j--)
		{
			for (int k = 1;k <= n;k++)
			{
				for (int l = 1;l <= m;l++)
				{
					v[k][l] = 0;
				}
			}
			if (g[j][i] & d[1])
			{
				g[j][i] -= 2;
				v[j][i] = 1;
				cal = 1;
				dfs2(j,i);
				g[j][i] += 2;
				if (cal > largest)
				{
					largest = cal;
					x = j;
					y = i;
					dirction = 'N';
				}
			}
			if (g[j][i] & d[2])
			{
				g[j][i] -= 4;
				v[j][i] = 1;
				cal = 1;
				dfs2(j,i);
				g[j][i] += 4;
				if (cal > largest)
				{
					largest = cal;
					x = j;
					y = i;
					dirction = 'E';
				}
			}
		}
	}

	printf("%d\n%d\n%d\n%d %d %c\n",numroom,maxsize,largest,x,y,dirction);
}