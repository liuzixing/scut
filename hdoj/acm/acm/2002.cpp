#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
const double PI = 3.1415927;
int main()
{
	double ans,r;
	while (cin >> r)
	{
		
		ans = 4.0 / 3.0 * PI * r * r * r;
		printf("%.3lf\n" ,ans);
	}
}