#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <iomanip>

using namespace std;

int main()
{
	int t;
	double a,b,c;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%lf %lf %lf",&a,&b,&c);
		if (a > 0 && b > 0 && c > 0 && a + b > c && a + c > b && b + c > a)
	    {
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}