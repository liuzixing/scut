#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int n,t;
	double i,f[21],c[21];
	f[1] = 0;f[2] = 1;
	c[1] = 1;c[2] = 2;
	for (i = 3;i < 21;i++)
	{
		f[int(i)] = (i - 1) * (f[int(i) - 1] + f[int(i) - 2]);
		c[int(i)] = c[int(i) - 1] * i;
	}
	cin >> t;
	while (t--)
	{
		cin >> n;
		printf("%.2lf%%\n",f[n] / c[n] * 100);
	}
}