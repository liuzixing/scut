#include<iostream>
#include <stdio.h>

using namespace std;

int main()
{
	__int64 n,ans;
	while (cin >>n)
	{
		ans = (((n + 1) % 10000 * n / 2) % 10000 * ((n + 1) % 10000 * n / 2) % 10000) % 10000;
		if (ans < 10)
		{
			printf("000%I64d\n",ans);
		}
		else
		{
			if (ans < 100)
			{
				printf("00%I64d\n",ans);
			}
			else
			{
				if (ans < 1000)
				{
					printf("0%I64d\n",ans);
				}
				else
				{
					printf("%I64d\n",ans);
				}
			}
		}
	}
}