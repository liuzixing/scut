#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
int main()
{
	int n,m,i,tem;
	while (scanf("%d %d",&n,&m) && (n + m))
	{
		i = int(sqrt(m * 2.0));
		for (;i >= 1;i--)
		{
			tem = m -(i * i + i) / 2;
			if (tem % i ==0)
			{
				printf("[%d,%d]\n",tem / i + 1,tem / i + i);
			}
		}
		printf("\n");
	}

}