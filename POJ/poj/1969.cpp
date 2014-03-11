#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{ 
	int m,i,n = 0,sum[10000];
	sum[0] =0;
	for (i = 1;i <= 10000;i++)
	{
		sum[i] = sum[i - 1] + i;
		if (sum[i] >= 10000000)
		{
			break;
		}
	}
	while (scanf("%d",&m) != EOF)
	{
		for (i = 1; i < 10000;i++)
		{
			if (sum[i] >= m)
			{
				break;
			}
		}
		if (i % 2 == 0)
		{
			printf("TERM %d IS %d/%d\n",m,i - (sum[i] - m),1 + (sum[i] - m));
		}
		else
		{
			printf("TERM %d IS %d/%d\n",m,1 + (sum[i] - m),i - (sum[i] - m));
		}
	}
}