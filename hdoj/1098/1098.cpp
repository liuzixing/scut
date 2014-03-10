#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int k,i;
	while (cin >> k)
	{
		bool flag = false;
		for (i = 1;i < 65;i++)
		{
			if ((18 + k * i) % 65 == 0)
			{
				printf("%d\n",i);
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			printf("no\n");
		}
	}
}