/*
ID: benbenq1
PROG: maze1
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int w,h;
char c[210][210];
int g[210][210];
const int b[4] = {1,2,4,8};
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,1,0,-1};
int qx[20001],qy[20001],step[20001],ans = 0;
bool v[210][210];
ifstream fin ("maze1.in");
ofstream fout ("maze1.out");
void init()
{
	int i,j,x,y,k;
	for (i = 1,x = 0;i < h * 2;i += 2 ,x++)
	{
		for (j = 1,y = 0; j <  w * 2;j += 2,y++)
		{
			for (k = 0;k < 4;k++)
			{
				if (c[i + dx[k]][j + dy[k]] != '-' && c[i + dx[k]][j + dy[k]] != '|' )
				{
					g[x][y] += b[k];
				}
			}
		}
	}
}
void bfs(int x,int y)
{
	bool f = 1;
	int head = 0,tail = 1,tx,ty,k;
	qx[0] = x;
	qy[0] = y;
	step[0] = 0;
	for (int i = 0;i < h;i++)
	{
		for (int j = 0;j < w;j++)
		{
			v[i][j] = 0;
		}
	}
	v[qx[0]][qy[0]] = 1;
	while (head < tail && f)
	{
		for (k = 0;k < 4 && f;k++)
		{
			if (b[k] & g[qx[head]][qy[head]])
			{
				tx = qx[head] + dx[k];
				ty = qy[head] + dy[k];
				if (tx < 0 || tx == h || ty < 0 || ty == w )
				{
					ans = (ans < step[head] + 1) ? step[head] + 1:ans;
					f = 0;
				}
				if (!v[tx][ty])
				{
					qx[tail] = tx;
					qy[tail] = ty;
					step[tail] = step[head] + 1;
					v[tx][ty] = 1;
					tail++;
				}
			}
		}
		head++;
	}
}
int main()
{
	int i,j;
	fin >> w >> h;
	fin.getline(c[99],w * 2 + 2,'\n');
	for (i = 0;i <= h * 2;i++)
	{
		fin.getline(c[i],w * 2 + 2,'\n');
	}
	init();
	for (i = 0;i < h;i++)
	{
		for (j = 0;j < w;j++)
		{
			bfs(i,j);
		}
	}
	fout << ans << endl;
}