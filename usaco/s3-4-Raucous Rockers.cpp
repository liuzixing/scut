/*
ID: benbenq1
PROG: rockers
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

int ans[21],f[21][21],a,n,t,m,i,j,k;
int main()
{
	freopen("rockers.in","r",stdin);
	freopen("rockers.out","w",stdout);
	cin >> n >> t >> m;
	for (i = 0;i < n;i++)
	{
		cin >> a;
		for (j = m;j >= 1;j--)
		{

			f[j][0] = ans[j - 1];
			for (k = t;k >= a;k--)
			{
				if (f[j][k] <= f[j][k - a] + 1)
					f[j][k] = f[j][k - a] + 1;
				if (f[j][k] > ans[j])
					ans[j] = f[j][k];
			}
		}
	}
	printf("%d\n",ans[m]);
	
}