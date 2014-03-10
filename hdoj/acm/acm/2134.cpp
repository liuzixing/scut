#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main()
{
	double r,r1,r2;
	while (scanf("%lf",&r))
	{
		if (r < 0.000000001)
		{
			break;
		}
		r2 = r / sqrt(3.0);
		r1 = r / sqrt(1.5);
		printf("%.3lf %.3lf\n",r2,r1);
	}
}