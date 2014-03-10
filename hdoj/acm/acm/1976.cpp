#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int t,a1,a2,a3,b1,b2,b3,a,b;
	cin >> t;
	while (t--)
	{
		scanf("%d %d %d",&a1,&a2,&a3);
		scanf("%d %d %d",&b1,&b2,&b3);
		a = a1 * 1000000 + a2 * 1000 + a3;
		b = b1 * 1000000 + b2 * 1000 + b3;
		if (a > b)
		{
			printf("First\n");
		}
		if (a < b)
		{
			printf("Second\n");
		}
		if (a == b)
		{
			printf("Same\n");
		}
	}
}