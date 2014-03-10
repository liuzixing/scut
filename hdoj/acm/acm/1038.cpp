#include <iostream>
#include <stdio.h>

using namespace std;
const double PI = 3.1415927;
int main()
{
	int revolution,i = 0;
	double d,time,dist;
	while (scanf("%lf %d %lf",&d,&revolution,&time) && revolution)
	{
		i++;
		dist = d * PI * revolution / 12.0 / 5280.0;
		printf("Trip #%d: %.2lf %.2lf\n",i,dist,dist / time * 3600);
	}
}