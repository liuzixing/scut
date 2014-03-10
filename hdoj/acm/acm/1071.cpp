#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	double x1,x2,x3,y1,y2,y3,a,b,k,bb,c,area;
    int t;
	cin >> t;
	while (t--)
	{
		scanf("%lf %lf",&x1,&y1);
		scanf("%lf %lf",&x2,&y2);
		scanf("%lf %lf",&x3,&y3);
		b = ((y3 - y2) / (pow(x3,2) - pow(x2,2)) - (y2 - y1) / (pow(x2,2) - pow(x1,2))) / (1.0 / (x2 + x3) - 1.0 / (x2 + x1));
		k = (y2 - y3) / (x2 - x3);
		a = b / (-2 * x1);
		c = y1 - a * pow(x1,2) - b * x1;
		bb = y2 - x2 * k;
		area = 1.0/3.0 * a * (pow(x3,3) - pow(x2,3)) + 0.5 * (b - k) *(pow(x3,2) - pow(x2,2)) + (c - bb) * (x3 - x2);
		printf("%.2lf\n",area);
	}
}