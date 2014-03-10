#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
int main()
{
	double x1,x2,y1,y2;
	int t;
	cin >> t;
	while (t--)
	{
		scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
		double a,b,s,ans,c;
		a = sqrt(double (x1 * x1 + y1 * y1));
		b = sqrt(double (x2 * x2 + y2 * y2));
		c = sqrt(double ((x1 - x2)*(x1 - x2) + (y1 - y2) * (y1 - y2)));
		
		s = abs(x1 * y2 - x2 * y1);
		ans = asin(s / a / b) / acos(-1.0) * 180;
		ans = (ans >= 360) ? ans - 360 : ans;
		ans = (ans < 0) ? ans + 360 : ans;
		ans = (ans > 180) ? 360 - ans : ans;
		if ((a * a + b * b - c * c) / 2 / a / b < 0)
		{
			if (ans < 90)
			{
				ans = 180 - ans;
			}
		}
		printf("%.2lf\n",ans);
	}
}