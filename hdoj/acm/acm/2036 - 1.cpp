#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <ctype.h>
using namespace std;
 
double d(double x1, double y1, double x2, double y2)
{

	return sqrt(pow(x1 - x2,2) + pow( y1 - y2,2));
}
int main()
{
	int n,i;
	double ans,c,d1,d2,d3,x1,x2,x3,y1,y2,y3;
	while (cin >> n && n)
	{
		scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3);
		d1 = d(x1,y1,x2,y2);
		d2 = d(x2,y2,x3,y3);
		d3 = d(x1,y1,x3,y3);
		c = (d1 + d2 + d3) / 2.0;
		ans = sqrt( (c - d1) * (c - d2) * (c - d3) * c);
		for (i = 3;i < n;i++)
		{
			x2 = x3;
			y2 = y3;
			scanf("%lf %lf",&x3,&y3);
			d1 = d(x1,y1,x2,y2);
	    	d2 = d(x2,y2,x3,y3);
	    	d3 = d(x1,y1,x3,y3);
	    	c = (d1 + d2 + d3) / 2.0 ;
	        ans += sqrt( (c - d1) * (c - d2) * (c - d3) * c);
		}
		printf("%.1lf\n",ans);
	}
}