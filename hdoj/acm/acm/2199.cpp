#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
#define POW(x) ((x) * (x))
#define POW3(x) (POW(x) * (x))
#define POW4(x) (POW(x) * POW(x))

double count(double x)
{
	return 8 * POW4(x) + 7 * POW3(x) + 2 * POW(x) + 3 * x + 6;
}
int main()
{
	int t;
	double y = 0,l,r,mid;
	cin >> t;
	while (t--)
	{
		scanf("%lf",&y);
		if (y < count(0.0) || y > count(100.0))
		{
			printf("No solution!\n");
			continue;
		}
		l = 0.0;r = 100.0;
		while (r - l > 1e-6)
		{
			mid = (l + r) / 2.0;
			if (count(mid) > y )
			{
				r = mid - 1e-6;
			}
			else
			{
				l = mid + 1e-6;
			}
		}
		printf("%.4lf\n",(l + r) / 2.0 );
	}
}