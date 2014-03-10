#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main()
{
	int t,x;
	double n;
	cin >> t;
	while (t--)
	{
		scanf("%d",&x);
		n = (sqrt(1 + 8.0 * sqrt(double(x))) - 1) / 2.0;
		if (n - int(n) > 0.00000000001)
		{
			n = int(n) + 1;
		}
		printf("%.lf\n",n);
	}

}