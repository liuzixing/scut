#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;
int f[5001][1010];
bool cmp(int a,int b)
{
	return a > b;
}
int main()
{
	int i,j,n,k,t,l[5001];
	cin >> t;

	while (t--)
	{
		scanf("%d %d",&k,&n);
		k += 8;
		for (i = 0;i < n;i++)
		{
			scanf("%d",&l[i]);
		}
		sort(l,l + n,cmp);

		f[3][1] = (l[2] - l[1]) * (l[2] - l[1]);
		for (i = 4;i <= n;i++)
		{
			f[i][1] = min(f[i - 1][1],(l[i - 1] - l[i - 2]) * (l[i - 1] - l[i - 2]));
		}
		for (j = 2;j <= k ;j++)
		{
			i = j * 3;
			f[i][j] = f[i - 2][j - 1] + (l[i - 1] - l[i - 2]) * (l[i - 1] - l[i - 2]);
			i++;
			for (;i <= n;i++)
			{
				f[i][j] = min(f[i - 1][j],f[i - 2][j - 1] + (l[i - 2] - l[i - 1]) * (l[i - 2] - l[i - 1]));
			}
		}
		printf("%d\n",f[n][k]);
	}
}