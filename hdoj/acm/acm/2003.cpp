#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int main()
{
	double x;
	while (cin >> x)
	{
		printf("%.2lf\n" ,fabs(x));
	}
}