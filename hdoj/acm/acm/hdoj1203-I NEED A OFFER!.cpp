#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int n,m,i,j,a;
	double f[10001],b;
	while (scanf("%d %d",&n,&m) != EOF && (n + m))
	{
		for (i = 0;i <= n;i++)
		{
			f[i] = 1.0;
		}
		while (m--)
		{
			scanf("%d %lf",&a,&b);
			b = 1.0 - b;
			for (j = n;j >= a;j--)
			{
				if (f[j] > f[j - a] * b || 1.0 - f[j] < 0.000000000001)
				{
					f[j] = f[j - a] * b;
				}
			}
		}

		printf("%.1lf%%\n",(1.0 - f[n]) * 100);
	}
}