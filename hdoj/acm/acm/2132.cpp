#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
__int64 sum[100001],i,n;
int main()
{
	sum[1] = 1;
	for (i = 2;i < 100001;i++)
	{
		if (i % 3)
		{
			sum[i] = sum[i - 1] + i;
		}
		else
		{
			sum[i] = sum[i - 1] + i * i * i;
		}
	}
	while (scanf("%I64d",&n) && n >= 0 )
	{
		
		printf("%I64d\n",sum[n]);
	}
}