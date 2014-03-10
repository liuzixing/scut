#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int a[51][51],b[51][51];
int d[51][51];
int ansx[25001][2],ansy[25001][2],ans;
const int dx[4] = {-1,-1,1,1};
const int dx2[8] = {0,-1,-1,0,0,1,1,0};
const int dy2[8] = {-1,0,0,1,1,0,0,-1};
const int dy[4] = {-1,1,1,-1};
bool v[51][51];
int n,m;
bool flag;
void init()
{
	for (int i = 0;i < n;i++)
		for (int j = 0;j < m;j++)
			scanf("%d",&a[i][j]);
	for (int i = 0;i < n;i++)
		for (int j = 0;j < m;j++)
		{
			scanf("%d",&b[i][j]);
			if (a[i][j] != b[i][j])
				d[i][j] = 1;
			else
				d[i][j] = 0;
		}
}
bool judge(int x,int y)
{
	if (x >= 0 && y >= 0 && x < n && y < m)
		return 1;
	return 0;
}
void colour(int x,int y)
{
	int tx,ty;
	for (int k = 0;k < 4;k++)
	{
		tx = dx[k] + x;
		ty = dy[k] + y;
		if (judge(tx,ty)  && d[tx][ty] == 1)
		{
			if (d[x + dx2[k * 2]][y + dy2[k * 2]] == 0)
				d[x + dx2[k * 2]][y + dy2[k * 2]] = flag = 1;
				
			if (d[x + dx2[k * 2 + 1]][y + dy2[k * 2 + 1]] == 0)
				d[x + dx2[k * 2 + 1]][y + dy2[k * 2 + 1]] = flag = 1;
		}
	}
}
int main()
{
	while (scanf("%d %d",&n,&m) != EOF)
	{
		memset(d,0,sizeof d);
		init();
		flag = 1;
		while (flag)
		{
			flag = 0;
			for (int i = 0;i < n;i++)
				for (int j = 0;j < m;j++)
					if (judge(i,j) && d[i][j] == 1)
						colour(i,j);	
		}

		memset(v,0,sizeof v);
		ans = 0;
		for (int i = 0;i < n;i++)
			for (int j = 0;j < m;j++)
			{
				if (d[i][j] == 1 && !v[i][j])
				{
					ansx[ans][0] = i;
					ansy[ans][0] = j;
					int k = i,l = j;
					while (d[i][l])
						l++;
					while (d[k][j])
						k++;
					ansx[ans][1] = k - 1;
					ansy[ans][1] = l - 1;
					for (k = ansx[ans][0];k <= ansx[ans][1];k++)
						for (l = ansy[ans][0];l <= ansy[ans][1];l++)
							v[k][l] = 1;
					ans++;
				}
			}
		printf("%d\n",ans);
		for (int i = 0;i < ans;i++)
			printf("%d %d %d %d\n",ansx[i][0] + 1,ansy[i][0] + 1,ansx[i][1] + 1,ansy[i][1] + 1);
	}
}