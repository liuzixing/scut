/*
ID: benbenq1
PROG: fence6
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

const int INF = 1 << 25;
int n,a[200][200],b[200][200],l[200],leftnode[200][200],rightnode[200][200];
int s,ans = 1 << 29,i,j,k;
int main()
{
	freopen("fence6.in","r",stdin);
	freopen("fence6.out","w",stdout);
	cin >> n;
	for (i = 1;i <= n;i++)
		for (j = 1;j <= n;j++)
			a[i][j] = INF;
	for (i = 1;i <= n;i++)
	{
		//如果全部连起来一齐读入，那么就不能读入正确的数据
		cin >> s ;
		cin >> l[s] >> leftnode[s][0] >> rightnode[s][0];
		for (j = 1;j <= leftnode[s][0];j++)
			cin >> leftnode[s][j];
		for (j = 1;j <= rightnode[s][0];j++)
			cin >> rightnode[s][j];
	}
	for (i = 1;i <= n;i++)
	{
		for (j = 1;j <= leftnode[i][0];j++)
			a[i][leftnode[i][j]] = l[i] + l[leftnode[i][j]];
		for (j = 1;j <= rightnode[i][0];j++)
			a[i][rightnode[i][j]] = l[i] + l[rightnode[i][j]];
	}

	for (i = 1;i <= n;i++)
		for (j = 1;j <= n;j++)
			b[i][j] = a[i][j];
	for (k = 1;k <= n;k++)
	{
		for (i = 1;i <= leftnode[k][0];i++)
		{
			int ii = leftnode[k][i];
			if (ii < k)
			{
				for (int j = 1;j <= rightnode[k][0];j++)
				{
					int jj = rightnode[k][j];
					if (jj < k)
						ans = min(ans,a[ii][jj] + b[ii][k] + b[k][jj]);
				}
			}
		}
		for (i = 1;i <= n;i++)
			for (j = 1;j <= n;j++)
				a[i][j] =  min(a[i][j] , a[i][k] + a[k][j]);
	}
	printf("%d\n",ans / 2);
}