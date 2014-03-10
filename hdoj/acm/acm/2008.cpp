#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
using namespace std;

int main()
{
	int i,n;
	double tem;
	while (cin >> n && n != 0)
	{
		
		int  positive = 0,negative = 0,zero = 0;
		for (i = 0; i < n;i++)
		{
			scanf("%lf",&tem);
			if (!tem)
			{
				zero++;
				continue;
			}
			if (tem < 0)
			{
				negative++;
			}
			else
			{
				positive++;
			}
		}
        printf("%d %d %d\n",negative,zero,positive);
	}
}