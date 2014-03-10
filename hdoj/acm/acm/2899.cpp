#include <iostream>
#include <stdio.h>
#define POW(x) ((x) * (x))
#define POW5(x) (POW(x) * POW(x) * x)
#define POW6(x) (POW5(x) * (x))
using namespace std;

double count(double x)
{
	return 42 * POW6(x) + 48 * POW5(x) + 21 * POW(x) + 10 * x;
}
double ans(double x,double y)
{
	return 6 * POW6(x) * x + 8 * POW5(x) * x + 7 * POW(x) * x + 5 * POW(x) - y * x;
}
int main()
{
	int t;
	double l,r,mid,y = 0;
	cin >> t;
	while (t--)
	{
		scanf("%lf",&y);
		l = 0;
		r = 100.0;
		while (r - l > 1e-6)
		{
			mid  = (l + r) / 2.0;
			if (count(mid) > y)
			{
				r = mid;
			}
			else
			{
				l = mid;
			}
		}
		printf("%.4lf\n",ans((l + r) / 2.0,y));
	}
}