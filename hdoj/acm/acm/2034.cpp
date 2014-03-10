#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <ctype.h>
using namespace std;
 
int main()
{
	int n,m,a[101],b[101],i,j;
	while (cin >> n >> m)
	{
		if (n == 0 && m == 0)
		{
			break;
		}
		for (i = 0;i < n;i++)
		{
			scanf("%d",&a[i]);
		}
		for (i = 0;i < m;i++)
		{
			scanf("%d",&b[i]);
		}
		sort(a,a + n);
		sort(b,b + n);
		bool yorn = false;
		for (i = 0 ;i < n;i++)
		{
			bool flag = true;
			for (j = 0;j < m;j++)
			{
				if (a[i] == b[j])
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				printf("%d ",a[i]);
				yorn = true;
			}
		}
		if (!yorn)
		{
			cout << "NULL\n";
		}
		else
		{
			cout << "\n";
		}

	}

}