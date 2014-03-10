#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <ctype.h>
using namespace std;
 
int main()
{
	int n,i;
	double ans,x[101],y[101];
	while (cin >> n && n)
	{
		for (i = 0;i < n;i++)
		    scanf("%lf %lf",&x[i],&y[i]);
		ans = 0;
		for (i = 0;i < n - 1;i++)
		{
	        ans += (x[i] * y[i + 1]- x[i + 1] * y[i]) / 2.0;
		}
		ans += (x[n - 1] * y[0]- x[0] * y[n - 1]) / 2.0;
		printf("%.1lf\n",ans);
	}
}