#include <iostream>
#include <cstdio>
#include <string.h>
#include <queue>

using namespace std;

struct node{
	int x,y;
};
int a[51][51];
int dist[51][51];
__int64 dp[51][51];
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
int n;
queue<node> q;

void bfs()
{
	node now,next;
	while (!q.empty())
		q.pop();
	now.x = n,now.y = n;
	dist[n][n] = a[n][n];
	q.push(now);
	while (!q.empty())
	{
		now = q.front();
		q.pop();
		for (int i = 0;i < 4;i++)
		{
			next.x = now.x + dx[i];
			next.y = now.y + dy[i];
			if (next.x > 0 && next.x <= n && next.y > 0 && next.y <= n && a[next.x][next.y] + dist[now.x][now.y] < dist[next.x][next.y])
			{
				dist[next.x][next.y] = a[next.x][next.y] + dist[now.x][now.y];
				q.push(next);
			}
		}
	}
}
__int64 dfs(int x,int y)
{
	if (dp[x][y] > 0)
		return dp[x][y];
	for (int i = 0;i < 4;i++)
	{
		int tx = x + dx[i],ty = y + dy[i];
		if (tx > 0 && tx <= n && ty > 0 && ty <= n && dist[tx][ty] < dist[x][y])
				dp[x][y] += dfs(tx,ty);
	}
	return dp[x][y];
}
int main()
{
	while (~scanf("%d",&n))
	{
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++)
			{
				scanf("%d",&a[i][j]);
				dist[i][j] = 1000000;
			}
		bfs();
		memset(dp,0,sizeof dp);
		dp[n][n] = 1;
		printf("%I64d\n",dfs(1,1));
	}
	return 0;
}