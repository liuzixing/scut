#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;
double f[10001];

int main()
{
	double p,b;
	int i,j,T,N,a;
	cin >> T;
	while (T--)
	{
		scanf("%lf %d",&p,&N);
		p = 1 - p;
		int ans = 0;
		for (i = 1;i < 10001;i++)
			f[i] = -1;
		f[0] = 1;
		for (i = 0;i < N;i++)
		{
			scanf("%d %lf",&a,&b);
			b = 1 - b;
			for (j = 10000;j >= a;j--)
			{
				f[j] = max(f[j],f[j - a] * b);
				if (f[j] >= p && ans < j)
					ans = j;
			}
		}
		printf("%d\n",ans);
	}
}
