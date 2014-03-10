#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int a,b,c;
	while (cin >> a >> b >> c)
	{
		bool flag = false;
		if (a <= 168)
		{
			printf("CRASH %d\n",a);
			break;
		}
		if (b <= 168)
		{
			printf("CRASH %d\n",b);
			break;
		}
		if (c <= 168)
		{
			printf("CRASH %d\n",c);
			break;
		}
		printf("NO CRASH\n");
	}
}