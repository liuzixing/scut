#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main()
{
	int i,n,min1,min2;
	int a[11],c,flag;
	cin >> c;
	while (c--)
	{
		cin >> n;
		flag = 0;
		min1 = 10000000;
		for (i = 0 ;i < n;i++)
		{
			cin >> a[i];
			if (min1 > a[i])
			{
				min1 = a[i];
			}
			else
			{
				if (a[i] == min1)
				{
					flag++;
				}
			}
		}
		min2 = 10000000;
		for (i = 0;i < n;i++)
		{
			if (a[i] > min1 && min2 > a[i])
			{
				min2 = a[i];
			}
		}
		min2 = (min2 == 10000000 || flag)? min1 : min2;
		printf("%d\n",min2);
	}

}