#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int i,n,m,k,j,t;
	int *ans;
	double *a;
	double tt;
	while(cin >> n >> m >> k)
	{
		a = new double[m];
		ans = new int[k];
		memset(a,0,sizeof(double) * m);
		memset(ans,0,sizeof(int) * k);
		for (i = 0;i < n;i++)
		{
			for (j = 0;j < m;j++)
			{
				scanf("%lf",&tt);
				a[j] += tt;
			}
		}
		
		for (i = 0;i < k; i++)
		{
			t = 0;
			for (j = 0;j < m;j++)
			{
				if (a[j] > a[t])
				{
					t = j;
				}
			}
			ans[i] = t; 
			a[t] = 0;
		}
		sort(ans,ans + k);
		for (i =  k - 1 ;i > 0;i--)
		{
			printf("%d ",ans[i] + 1);
		}
		printf("%d\n",ans[i] + 1);
	}
}