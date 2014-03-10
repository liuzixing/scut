#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
using namespace std;

int main()
{
	int i,n,tem;
	while (cin >> n)
	{
		long long int sum = 1;
		for (i = 0; i < n;i++)
		{
			scanf("%d",&tem);
			if (tem % 2)
			{
				sum *= tem;
			}
		}
        printf("%d\n",sum);
	}
}