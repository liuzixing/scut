#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int n,i,a[101];
	double average;
	while (cin  >> n)
	{
		double sum = 0;
		for (i = 0;i < n;i++)
		{
			scanf ("%d",&a[i]);
			sum += a[i];
		}
		sort(a,a + n);
		sum = sum - a[0] - a[n - 1];
		average = double (sum / (n - 2));
		printf("%.2lf\n",average);
	}
}