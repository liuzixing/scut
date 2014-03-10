#include<iostream>
#include <cstdio>
using namespace std;

const int N = 101;
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,1,0,-1};
int g[N][N],f[N][N];
int k,n,ans;

int dp(int x,int y)
{
	if (f[x][y])
		return f[x][y];
	int i,j,tx,ty;
	f[x][y] = g[x][y];
	for (j = 1;j <= k;j++)
		for (i = 0;i < 4;i++)
		{
			tx = x + j * dx[i];
			ty = y + j * dy[i];
			if (tx >= 0 && tx < n && ty >= 0 && ty < n && g[tx][ty] > g[x][y])
			{
				int tem = dp(tx,ty);
				f[x][y] =  max(tem + g[x][y] , f[x][y]);
			}
		}
	return f[x][y];
}

int main()
{
	int i,j;
	while (scanf("%d %d",&n,&k) != EOF)
	{
		if (n == -1 && k == -1) break;
		memset(f,0,sizeof f);
		for (i = 0;i < n;i++)
			for (j = 0;j < n;j++)
				scanf("%d",&g[i][j]);
		printf("%d\n",dp(0,0));
	}
}
