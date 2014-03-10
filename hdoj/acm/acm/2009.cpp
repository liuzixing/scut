#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
using namespace std;

int main()
{
	int i;
	double n,m;
	while (cin >> n >> m)
	{
		
		double  sum = 0;
		for (i = 0; i < m;i++)
		{
			sum += n;
			n = sqrt(n);
		}
        printf("%.2lf\n",sum);
	}
}