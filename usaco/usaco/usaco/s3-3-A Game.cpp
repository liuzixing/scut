/*
ID: benbenq1
PROG: game1
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

int n,a[101],f[101][101],sum[101],i,j;

int main()
{
	freopen("game1.in","r",stdin);
	freopen("game1.out","w",stdout);
	
	cin >> n;
	for (i = 1;i <= n;i++)
	{
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	for (i = 1;i <= n;i++)
		f[i][i] = a[i];
	for (i = 1;i < n;i++)
		for (j = 1;j <= n - i;j++)
			f[j][j + i] = sum[j + i] - sum[j] + a[j] - min(f[j][i + j - 1],f[j + 1][j + i]);
	printf("%d %d\n",f[1][n],sum[n] - f[1][n]);
		
}
