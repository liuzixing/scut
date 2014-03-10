#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int a,b,i;
	while (scanf("%d %d",&a,&b), a + b)
	{
		a *= 100;
		bool flag = 0;
		for (i = 0;i < 100;i++)
		{
			if  ((a + i) % b == 0)
			{
				printf(flag ? " %02d" : "%02d",i);
				flag = 1;
			}
		}
		putchar('\n');
	}
}