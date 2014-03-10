#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
using namespace std;

int main()
{
	int i,n,tem,x,y;
	while (cin >> x >> y)
	{
		if (x > y)
		{
			tem = x;
			x = y;
			y = tem;
		}
		int pf = 0,lf = 0;

		for (i = x; i <= y;i++)
		{
			if (i % 2)
			{
				lf += i * i * i;
			}
			else
			{
				pf += i * i;
			}
		}
        printf("%d %d\n",pf,lf);
	}
}