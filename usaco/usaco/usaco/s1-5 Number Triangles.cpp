/*
ID: benbenq1
LANG: C++
TASK: numtri
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <climits>
#include <vector>
using namespace std;

int a[1002][1002],sum[1002][1002];

int main()
{
	freopen("numtri.in","r",stdin);
	freopen("numtri.out","w",stdout);
	int r,i,j;
	scanf("%d",&r);
	for (i = 1;i <= r;i++)
	{
		for (j = 1;j <= i;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for (i = r;i > 0;i--)
	{
		for (j = 1;j <= i;j++)
		{
			sum[i][j] = max(sum[i + 1][j],sum[i + 1][j + 1]) + a[i][j];
		}
	}
	printf("%d\n",sum[1][1]);
}