/*
ID: benbenq1
PROG: camelot
LANG: C++
*/
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstring>
#include <utility>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <numeric>
#include <cstdio>
#include <bitset>
#include <string>
#include <vector>
#include <cmath>
#include <deque>
#include <stack>
#include <ctime>
#include <list>
#include <set>
#include <map>

using namespace std;

const int knightx[9]={0,1,1,-1,-1,2,2,-2,-2},knighty[9]={0,2,-2,2,-2,1,-1,1,-1};

int r,c,len;
int x[1000], y[1000],dist[31][27][31][27],ans,sum[31][27];
bool knightpass[31][27],v[31][27];
char tc;
int qx[300000],qy[300000],step[300000];

void bfs_knight(int xx,int yy)
{
	int head = 0,tail = 1,tx,ty,i;
	dist[xx][yy][xx][yy] = 0;
	qx[0] = xx;
	qy[0] = yy;
	step[0] = 0;
	v[qx[0]][qy[0]] = 1;
	while (head < tail)
	{
		for (i = 1;i <= 8;i++)
		{
			tx = qx[head] + knightx[i];
			ty = qy[head] + knighty[i];
			if (tx > 0 && tx <= r && ty > 0  && ty <= c && !v[tx][ty])
			{
				qx[tail] = tx;
				qy[tail] = ty;
				v[tx][ty] = 1;
				step[tail] = step[head] + 1;
				dist[xx][yy][tx][ty] = step[tail];
				tail++;
			}
		}
		head++;
	}
}
int main()
{
	int i,j,k,l,m,avx,avy;
	freopen("camelot.in","r",stdin);
	freopen("camelot.out","w",stdout);
	cin >> r >> c;
	cin >> tc >> x[0];
	len = 1;
	y[0] = tc - 'A' + 1;
	avx = 0;
	avy = 0;
	while (cin >> tc >> x[len])
	{
		y[len] = tc - 'A' + 1;
		avx += x[len];
		avy += y[len];
		len++;
	}
	if (len < 2)
	{
		printf("0\n");
		exit(0);
	}
	avx = avx / (len - 1);
	avy = avy / (len - 1);
	for (i = 1;i <= r;i++)
      for (j = 1;j <= c;j++)
		for (k = 1;k <= r;k++)
		  for (l = 1;l <= c;l++)
		  {
			 dist[i][j][k][l] = 0xffffff;
		  }

	for (i = 1;i <= r;i++)
      for (j = 1;j <= c;j++)
	  {
        bfs_knight(i,j);
		for (k = 1;k <= r;k++)
		  for (l = 1;l <= c;l++)
		  {
			  v[k][l] = 0;
		  }
	  }
    for (i = 1;i <= r;i++)
      for (j = 1;j <= c;j++)
	  {
          sum[i][j] = 0;
          for (k = 1;k < len ;k++)
            sum[i][j] = sum[i][j]+dist[i][j][x[k]][y[k]];
	  }

	ans = 0x7fffffff;
	for (i = 1;i <= r;i++)
		for (j = 1;j <= c;j++)
			ans = min(ans,sum[i][j] + max(abs(x[0] - i),abs(y[0] - j)));
	for (m = 1;m < len;m++)
		for (i = max(avx - 3,1);i <= min(avx + 3,r);i++)
			for (j = max(avy - 3,1);j <= min(avy + 3,c);j++)
				for (k = max(x[0] - 3,1);k <= min(x[0] + 3,r);k++)
					for (l = max(y[0] - 3,1);l <= min(y[0] + 3,c);l++)
						ans = min(ans,dist[x[m]][y[m]][k][l] + max(abs(x[0] - k),abs(y[0] - l)) + dist[k][l][i][j] + sum[i][j] - dist[i][j][x[m]][y[m]]);
	printf("%d\n",ans);
}