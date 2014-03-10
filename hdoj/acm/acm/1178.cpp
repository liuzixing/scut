#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int n,exponent;
	double  sum,a;
	while (cin >> n && n)
	{
		a = n;
		sum = a * (a + 1) / 6.0 * (a + 2);
		exponent = log10(sum);
		sum = sum / pow(10.0,exponent);
		printf("%.2lfE%d\n",sum,exponent);
	}
}