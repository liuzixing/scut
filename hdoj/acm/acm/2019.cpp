#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int n,m,a[110],i;
	while (cin >> n >> m)
	{
		if (!n)
		{
			break;
		}
		bool flag = true;
		for (i = 1;i <= n + 1;i++)
		{
			scanf("%d",&a[i]);
			if (m < a[i] && flag)
			{
				a[i + 1] = a[i];
				a[i] = m;
				i++;
				flag = false;
			}
		}
		for (i = 1;i <= n;i++)
		{
			printf("%d ",a[i]);
		}
		printf("%d\n",a[n + 1]);
	}
}