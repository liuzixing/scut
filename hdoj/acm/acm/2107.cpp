#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int t,i,max,tem;
	while (cin >> t && t)
	{
		max = 0;
		for (i = 0;i < t;i++)
		{
			scanf("%d",&tem);
			if (max < tem)
			{
				max = tem;
			}
		}
		printf("%d\n",max);
	}
}