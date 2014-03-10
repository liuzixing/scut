#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
using namespace std;

int main()
{
	int i,m,n;
	double sum = 0;
	cin >> m;
	while (m)
	{
		m--;
		scanf("%d",&n);
		sum = 0;
		for (i = 1;i <= n; i++)
		{
			if (i % 2)
			{
				sum += 1.0 / i;
			}
			else
			{
				sum = sum - 1.0 / i;
			}
		}
		printf("%0.2lf\n",sum);

	}

}