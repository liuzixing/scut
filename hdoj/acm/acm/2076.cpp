#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int main()
{
	int t,h,m,s;
	double ans;
	cin >> t;
	while (t--)
	{
		scanf("%d %d %d",&h,&m,&s);
		if (h > 12)
		{
			h -= 12;
		}
		ans =  fabs(30.0 * h - 11.0 * m / 2.0 - 11.0 * s / 120.0);
		if (ans > 180)
		{
			ans = 360 - ans;
		}
		printf("%d\n",int(ans));
	}
}