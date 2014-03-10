#include <functional>
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

int d[101],g[11][11],f,n,total,ans[200];
int p1[101],p2[101];
void dfs(int v)
{
	for (int i = 0;i <= 6;i++)
		if (g[v][i] > 0)
		{
			g[v][i]--;
			g[i][v]--;
			d[v]--;
			d[i]--;
			dfs(i);
		}
		ans[++total] = v;
}
void solve()
{
	int find = 0,i,tem = 0,k,a,b;
	for (i = 0;i <= 6;i++)
		if (d[i] > 0)
		{
			find = i;
			break;
		}
	for (i = 0;i <= 6;i++)
		if (d[i] % 2)
		{
			find = i;
			tem++;
		}
	if (tem != 0 && tem != 2)
	{
		printf("No solution\n");
		exit(0);
	}
	dfs(find);
	if (total < f)
	{
		printf("No solution\n");
		exit(0);
	}
	for (k = 2;k <= total;k++)
	{
		a = ans[k - 1],b = ans[k];
		for (i = 1;i <= f;i++)
		{
			if (a == p1[i] && b == p2[i])
			{
				printf("%d +\n",i);
				p1[i] = p2[i] = -1;
				break;
			}
			else if (a == p2[i] && b == p1[i])
			{
				printf("%d -\n",i);
				p1[i] = p2[i] = -1;
				break;
			}
		}
	}
}
int main()
{
	int i,x,y;
	scanf("%d",&f);
	for (i = 1;i <= f;i++)
	{
		scanf("%d %d",&x,&y);
		g[x][y]++;
		g[y][x]++;
		d[x]++;
		d[y]++;
		p1[i] = x;
		p2[i] = y;
	}
	solve();
}