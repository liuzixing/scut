#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

double a[1000000];
long long i;
int n = 1;
int main()
{
	while (scanf("%lld",&i) != EOF )
	{
		a[n] = sqrt(double (i)); 
		n++; 
	}

	for (i = n - 1;i > 0;i--)
		printf("%.4lf\n",a[i]); 
	return 0;
}