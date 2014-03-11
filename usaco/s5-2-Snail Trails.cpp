/*
ID: benbenq1
PROG: snail
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
#include <memory>
#include <cstdio>
#include <cctype>
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

FILE *fin = fopen("snail.in","r");
FILE *fout = fopen("snail.out","w");

const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,1,0,-1};
int v[121][121];
int n,b,ans = 0;
void init()
{
	for (int i = 0;i < 120;i++)
		for (int j = 0;j < 120;j++)
			v[i][j] = 0;
	char c[10];
	int x,y,t;
	fscanf(fin,"%d%d",&n,&b);
	for (int i = 0;i < b;i++)
	{
		fscanf(fin,"%s",c);
		y = c[0] - 'A';
		t = 1;
		x = 0;
		while (t < strlen(c))
		{
			x = x * 10 + c[t] - '0';
			t++;
		}
		x -= 1;
		v[x][y] = 1;

	}
	v[0][0] = 2;
}
void dfs(int k,int x,int y,int len)
{
	int tx = x + dx[k],ty = y + dy[k],tk;
	if (tx >= 0 && tx < n && ty >= 0 && ty < n && v[tx][ty] == 2)
	{
		ans = max(ans,len);
		return;
	}
	if (tx >= 0 && tx < n && ty >= 0 && ty < n && v[tx][ty] == 0)
	{
		v[tx][ty] = 2;
		dfs(k,tx,ty,len + 1);
		v[tx][ty] = 0;
	}
	else
	{
		for (tk = (k + 1) % 4; tk != k;tk = (tk + 1) % 4)
		{
			tx = x + dx[tk];
			ty = y + dy[tk];
			if (tx >= 0 && tx < n && ty >= 0 && ty < n)
			{
				if (v[tx][ty] == 0)
				{
					v[tx][ty] = 2;
					dfs(tk,tx,ty,len + 1);
					v[tx][ty] = 0;
				}
				else
					ans = max(ans,len);	
			}
		}
	}
	
}
int main()
{
	
	init();
	for (int k = 0;k < 4;k++)
	{
		dfs(k,0,0,1);
	}
	fprintf(fout,"%d\n",ans);
	fclose(fin);
	fclose(fout);
}