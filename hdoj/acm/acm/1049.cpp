#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int x,y,d,u,n;
	while (scanf("%d %d %d",&n,&u,&d) && n)
	{
		x = 0;
		y = 0;
		do
		{
			x++;
			n -= u;
			if (n <= 0)
			{
				break;
			}
			y++;
			n += d;
		}while (n);
		printf("%d\n",x + y);
	}
}