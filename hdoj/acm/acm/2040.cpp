#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main()
{
	int m;
	int i,sum,a,b;
	cin >> m;
	while (m--)
	{
		scanf("%d %d",&a,&b);
		bool flag1 = false;
		bool flag2 = false;
		sum = 0;
		for (i = 1;i <= a / 2;i++)
		{
			if (a % i == 0)
			{
				sum += i;
			}
		}
		if (sum == b)
		{
			flag1 = true;
		}

		sum = 0;

		for (i = 1;i <= b / 2;i++)
		{
			if (b % i == 0)
			{
				sum += i;
			}
		}
		if (sum == a)
		{
			flag2 = true;
		}

		if (flag1 && flag2)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}