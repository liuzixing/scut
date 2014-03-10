#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int a,sum,tem;
	while (cin >> a && a)
	{
		tem = a;
		sum = 0;
		while (tem)
		{
			sum += tem % 10;
			tem /= 10;
		}
		int sum2 = 0;
		tem = a;
		while (tem)
		{
			sum2 += tem % 16;
			tem /= 16;
		}
		if (sum2 != sum)
		{
			printf("%d is not a Sky Number.\n",a);
			continue;
		}
        sum2 = 0;
		tem = a;
		while (tem)
		{
			sum2 += tem % 12;
			tem /= 12;
		}
		if (sum2 != sum)
		{
			printf("%d is not a Sky Number.\n",a);
			continue;
		}
		else
		{
			printf("%d is a Sky Number.\n",a);
		}
	}

}