#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <climits>
#include <set>
using namespace std;

const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,1,0,-1};

int w,h,xa,xb,ya,yb;
bool g[80][80],v[80][80];
int step[80][80],qx[10000],qy[10000],direct[10000];

int bfs()
{
	int head = 0,tail = 1,i,tx,ty,ans = 10000;
	bool flag = 0;
	qx[0] = xa;
	qy[0] = ya;
	step[xa][ya] = 0;
	v[xa][ya] = 1;
	direct[0] = -1;
	if (xa == xb && ya == yb)
		return 0;
	while (head < tail)
	{
		for (i = 0;i < 4;i++)
		{
			tx = qx[head] + dx[i];
			ty = qy[head] + dy[i];
			while (tx <= h + 1 && tx >= 0 && ty >= 0 && ty <= w + 1 && !v[tx][ty] && !g[tx][ty])
			{
				
				step[tx][ty] = step[qx[head]][qy[head]] + 1;
				if (tx == xb && ty == yb)
					return step[tx][ty];
				v[tx][ty] = 1;
				qx[tail] = tx;
				qy[tail] = ty;
				tail++;
				tx = tx + dx[i];
				ty = ty + dy[i];
			}
		}
		head++;
	}
	return -1;
}
int main()
{
	char c = '1';
	int i,j,p,b = 0,tem;
	
	while (scanf("%d %d",&w,&h) != EOF && (w || h))
	{
		b++;
		printf("Board #%d:\n",b);
		memset(g,0,sizeof(g));
		for (i = 1;i <= h;i++)
		{
			getchar();
			for (j = 1;j <= w;j++)
			{
				scanf("%c",&c);
				if (c == 'X')
					g[i][j] = 1;
			}
		}
		p = 0;
		while (scanf("%d%d%d%d",&ya,&xa,&yb,&xb) != EOF && (xa || xb || ya || yb))
		{
			p++;
			memset(v,0,sizeof(v));
			g[xb][yb] = 0;
			tem = bfs();
			if (tem > -1)
				printf("Pair %d: %d segments.\n",p,tem);
			else
				printf("Pair %d: impossible.\n",p);
			g[xb][yb] = 1;
		}
		printf("\n");
	}
}