#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const int money[6] = {100,50,10,5,2,1};
int main()
{
	int i,j,n,t,m;
	int max,x,y;
	while (cin >> m >> n)
	{
		max = 0;
		x = 0;
		for (i = 1;i <=m;i++)
		{
			for (j = 1;j <= n;j++)
			{
				scanf ("%d",&t);
				if (abs(max) < abs(t) || x == 0)
				{
					max = t;
					x = i;
					y = j;
				}
			}
		}
		printf("%d %d %d\n",x,y,max);
	}
}