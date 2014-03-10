#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	double x1,y1,x2,y2,x3,y3;
	int t;	
	while (cin >> t && t)
	{
		while (t--)
		{
			scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3);
			printf("%.1lf %.1lf\n",(x1 + x2 + x3) / 3.0,(y1 + y2 + y3) / 3.0);
		}
	}
}