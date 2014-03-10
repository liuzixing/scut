#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main()
{
	int n,step;
	while (scanf("%d",&n) != EOF && n)
	{
		step = 0;
		while (n > 1)
		{
			if (n % 2)
			{
				n = (3 * n + 1) / 2;
			}
			else
			{
				n = n / 2;
			}
			step++;
		}
		printf("%d\n",step);
	}
}