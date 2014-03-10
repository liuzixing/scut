/*
ID: benbenq1
PROG: fence
LANG: C++
*/
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

int d[1001],g[501][501],f,n,total,ans[1000000];

void solve(int v)
{
	for (int i = 1;i <= n;i++)
		if (g[v][i] > 0)
		{
			g[v][i]--;
			g[i][v]--;
			solve(i);
		}
		total++;
		ans[total] = v;
}
int main()
{
	freopen("fence.in","r",stdin);
	freopen("fence.out","w",stdout);
	scanf("%d",&f);
	for (int i = 1;i <= f;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		g[x][y]++;
		g[y][x]++;
		d[x]++;
		d[y]++;
		n = max(max(n,x),y);
	}
	int find = 0;
	for (int i = 1;i <= n;i++)
		if (d[i] % 2)
		{
			find = i;
			break;
		}
	if (!find)
	{
		for (int i = 1;i <= n;i++)
			if (d[i] > 0)
			{
				find = i;
				break;
			}
	}
	solve(find);
	for (int i = total;i >= 1;i--)
		printf("%d\n",ans[i]);
}