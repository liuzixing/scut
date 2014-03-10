#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main()
{
	double ans,x1,x2,y2,y1;
	while (cin >> x1 >> y1 >> x2 >> y2)
	{
		
		ans = sqrt((x1 - x2) *(x1 - x2) + (y1 - y2) * (y1 - y2));
		printf("%.2lf\n" ,ans);
	}
}