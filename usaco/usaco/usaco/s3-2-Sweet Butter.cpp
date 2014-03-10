/*
ID: benbenq1
PROG: butter
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

int q[810],g[810][810],dis[810];
int farm[501];
int n,p,c;
bool v[801];
int road[801][801];
int ans = 0x7fffffff;
void spfa(int s)
{
	int l = 0,r = 1;
	q[r] = s;
	v[s] = 1;
	int now,st,u;
	do
	{
		l++;
		st = q[(l - 1) % p + 1];
		for (int i =1;i <= road[st][0];i++)
		{
			u = road[st][i];
			if (dis[st] + g[st][u] < dis[u])
			{
				dis[u] = dis[st] + g[st][u];
				if (!v[u])
				{
					r++;
					q[(r - 1) % p + 1] = u;
					v[u] = 1;
				}
			}
			v[st] = 0;
		}
	}while (l < r);
	now = 0;
	for (int i = 1; i <= n; i++)
		now +=dis[farm[i]];
	if (ans > now)
		ans = now;
}
int main()
{
	int i,j;
	freopen("butter.in","r",stdin);
	freopen("butter.out","w",stdout);
	scanf("%d %d %d",&n,&p,&c);
	for (i = 1;i <= n;i++)
		cin >> farm[i];
	int x,y,z;
	for (i = 1;i <= c;i++)
	{
		cin >> x >> y >> z;
		road[x][0]++;
		road[x][road[x][0]] = y;
		g[x][y] = z;
		road[y][0]++;
		road[y][road[y][0]] = x;
		g[y][x] = z;
	}
	for (i = 1;i <= p;i++)
	{
		memset(dis,0x7f,sizeof(dis));
		memset(v,0,sizeof(v));
		dis[i] = 0;
		spfa(i);
	}
	cout << ans << endl;
}