/*
ID: benbenq1
PROG: nuggets
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

int f[256 * 256 + 500],a[11];
int main()
{
	freopen("nuggets.in","r",stdin);
	freopen("nuggets.out","w",stdout);
	int n,i,j;
	cin >> n;
	f[0] = 1;
	for (i = 0;i < n;i++)
	{
		scanf("%d",&a[i]);
		for (j = a[i];j <= 256 * 256+ 499;j++)
		{
			if (f[j - a[i]])
				f[j] = 1;
		}
	}
	int res = 0;
	for (j = 256 * 256;j > 0;j--)
	{
		if (!f[j])
		{
			res = j;
			break;
		}
	}
	for (j = 256 * 256 + 499;j > 256 * 256;j--)
	{
		if (!f[j])
		{
			res = 0;
			break;
		}
	}
	printf("%d\n",res);
}