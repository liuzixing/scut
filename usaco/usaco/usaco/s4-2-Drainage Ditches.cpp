/*
ID: benbenq1
PROG: ditch
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

int g[201][201],h[201],v[201],flow = 0,n,m,delta;
bool flag;
void sap(int vv)
{
	if (vv == n)
	{
		flow += delta;
		flag = true;
		return;
	}
	int temp = delta,i,minh = n - 1;
	for (i = 1;i <= n;i++)
		if (g[vv][i] > 0)
		{
			if (h[i] + 1 == h[vv])
			{
				delta = min(delta,g[vv][i]);
				sap(i);
				if (h[1] >= n) return;
				if (flag) break;
				delta = temp;
			}
			minh = min (minh,h[i]);
		}
		if (flag)
		{
			g[vv][i] -= delta;
			g[i][vv] += delta;
		}
		else
		{
			v[h[vv]]--;
			if (!v[h[vv]]) h[1] = n;
			h[vv] = minh + 1;
			v[h[vv]]++;
		}
}
int main()
{
	int i,x,y,z;
	freopen("ditch.in","r",stdin);
	freopen("ditch.out","w",stdout);
	cin >> m >> n;
	for (i = 1;i <= m;i++)
	{
		cin >> x >> y >> z;
		g[x][y] += z;
	}
	v[0] = n;
	while (h[1] < n)
	{
		delta = 0x7fffffff;
		flag = 0;
		sap(1);
	}
	cout << flow << endl;
	return 0;
}