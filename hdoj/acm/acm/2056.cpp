#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	double ans,x[4],y[4],x1,y1,x2,y2;
	while (cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2] >> x[3] >> y[3])
	{

		if (x[0] > x[1])
		{
			swap(x[0],x[1]);
		}
		if (y[0] > y[1])
		{
			swap(y[0],y[1]);
		}
		if (x[2] > x[3] )
		{
			swap(x[2],x[3]);
		} 
		if (y[2] > y[3])
		{
			swap(y[2],y[3]);
		}
		x1 = (x[0] < x[2]) ? x[2]:x[0];
		x2 = (x[1] < x[3]) ? x[1]:x[3];
		y1 = (y[0] < y[2]) ? y[2]:y[0];
		y2 = (y[1] < y[3]) ? y[1]:y[3];
		if (x1 > x2 || y1 > y2)
		{
			ans = 0;
		}
		else
		{
			ans = (x2 - x1) * (y2 - y1);
		}
		printf("%.2lf\n",ans);
	}
}