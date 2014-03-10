/*
ID: benbenq1
PROG: stall4
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

const int maxn = 210;
bool getv[maxn];
int n,m,a[maxn][maxn],ans,match[maxn];
void init()
{
	freopen("stall4.in","r",stdin);
	freopen("stall4.out","w",stdout);
	int i,j;
	scanf("%d%d",&n,&m);
	for (i = 1;i <= n;i++)
	{
		scanf("%d",&a[i][0]);
		for (j = 1;j <= a[i][0];j++)
			scanf("%d",&a[i][j]);
	}
}
bool dfs(int k)
{
	int i,j;
	for (i = 1;i <= a[k][0];i++)
	{
		j = a[k][i];
		if (!getv[j])
		{
			getv[j] = 1;
			if (!match[j] || dfs(match[j]))
			{
				match[j] = k;
				return true;
			}
		}
	}
	return false;
}
void solve()
{
	int i;
	for (i = 1;i <= n;i++)
	{
		if (dfs(i)) ans++;
		memset(getv,0,sizeof(getv));
	}
}
int main()
{
	init();
	solve();
	printf("%d\n",ans);
	return 0;
}