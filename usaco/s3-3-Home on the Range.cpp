/*
ID: benbenq1
PROG: range
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

int g[251][251],size[251];
int main()
{
	freopen("range.in","r",stdin);
	freopen("range.out","w",stdout);
	int n,i,j,k;
	char c;
	cin >> n;
	for (i = 1;i <= n;i++)
		for (j = 1;j <=n;j++)
		{
			cin >> c;
			g[i][j] = c - '0';
		}

	for (i = 1;i <= n ;i++)
		for (j = 1;j <= n;j++)
		{
			if (g[i][j])
				g[i][j] = min(min(g[i - 1][j],g[i][j - 1]),g[i - 1][j - 1]) + 1;
			for (k = 2 ;k <= g[i][j];k++)
				size[k]++;
		}

	for (i = 2;i <= 250;i++)
		if (size[i])
			printf("%d %d\n",i,size[i]);
}
