#include <iostream> 
#include <cstdlib> 
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int n,m,a[1001],i,j,u;
	int f[1100];
	while (cin >> n && n)
	{
		for (i = 0;i < n;i++)
			scanf("%d",&a[i]);
		scanf("%d",&m);
		sort(a,a + n);
		memset(f,0,sizeof(f));
		if (m < 5)
		{
			printf("%d\n",m);
			continue;
		}
		for (i = 0;i < n - 1;i++)
		{
			for (j = m - 5;j >= a[i];j--)
			{
				f[j] = (f[j] > f[j - a[i]] + a[i]) ? f[j] : f[j - a[i]] + a[i];
			}
		}
		printf("%d\n",m - f[m - 5] - a[n - 1]);
	}
}