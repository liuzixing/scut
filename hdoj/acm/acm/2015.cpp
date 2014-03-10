#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int n,i,a[101],m;
	a[1] = 2;
	for (i = 2;i < 101;i++)
	{
		a[i] = a[i - 1] + 2;
	}
	while (cin  >> n >> m)
	{
		int sum = 0,last = 0;
		for (i = 1;i <= n;i++)
		{
			sum += a[i];
			if (i % m == 0)
			{
				if (last)
				{
					printf("%d ", last);
				}
				last = sum / m;
				sum  = 0;
			}
		}
		if (n % m)
		{
			printf("%d %d\n",last,sum / (n % m));
		}
		else
		{
			printf("%d\n",last);
		}
	}
}