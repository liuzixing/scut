#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int t,n;
	double max,a;
	cin >> t;
	while (t--)
	{
		cin >> n;
		max = -1;
		while (n--)
		{
			scanf("%lf",&a);
			max = (max < a) ? a:max;
		}
		printf("%.2lf\n",max);
	}

}