#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int i,j,n,a[101],tem;
	while (cin >> n && n != 0)
	{
		for (i = 0;i < n;i++)
		{
			scanf("%d",&a[i]);

		}
		for (i = 0;i < n - 1;i++)
		{
			for (j = i + 1;j < n;j++)
			{
				if (abs(a[i])< abs(a[j]))
				{
					tem = a[i];
					a[i] = a[j];
					a[j] = tem;
				}
			}
		}
		for (i = 0;i < n - 1;i++)
		{
			printf("%d ",a[i]);
		}
		printf("%d\n",a[n - 1]);
	}
}