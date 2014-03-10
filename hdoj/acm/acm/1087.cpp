#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int n,i,j,a[1001],max,f[1001];
	while (cin >> n && n)
	{
		a[0] = -1;
		for (i = 1;i <= n;i++)
		{
			scanf("%d",&a[i]);
		}
		max = 0;
		for (i = 1;i <= n;i++)
		{
			f[i] = a[i];
			for (j = i - 1;j > 0;j--)
			{
				if (a[i] > a[j] && f[i] < f[j] + a[i])
				{
					f[i] = f[j] + a[i];
				}
			}
			max =  (f[i] > max) ? f[i] : max;
		}
		printf("%d\n",max);
	}

}