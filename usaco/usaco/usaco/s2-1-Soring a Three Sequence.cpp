/*
ID: benbenq1
PROG: sort3
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	freopen("sort3.in","r",stdin);
	freopen("sort3.out","w",stdout);
	int i,n;
	int a[1001],count[4] = {0},ans[4] = {0};
	scanf("%d",&n);
	for (i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
		count[a[i]]++;
	}
	for (i = 1;i <= count[1] + count[2];i++)
	{
		if (a[i] == 3)
		{
			ans[3]++;
		}
		if (a[i] == 2 && i <= count[1])
		{
			ans[1]++;
		}
		if (a[i] == 1 && i > count[1])
		{
			ans[2]++;
		}
	}

	printf("%d\n",ans[3] +( (ans[2] > ans[1]) ? ans[2] : ans[1]));
}
