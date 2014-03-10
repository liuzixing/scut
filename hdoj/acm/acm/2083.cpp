#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main()
{
	int m,n,a[501],tem,min,i,j;
	cin >> m;
	while (m--)
	{
		cin >> n;
		for (i = 0;i < n;i++)
		{
			scanf("%d",&a[i]);
		}
		min = 10000000;
		for (i = 0;i < n;i++)
		{
			int tem = 0;
			for (j = 0;j < n;j++)
			{
				tem += abs(a[i] - a[j]);
			}
			if (tem < min)
			{
				min = tem;
			}
		}
		cout << min << endl;
	}
}