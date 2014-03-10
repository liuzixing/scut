#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int i,j;
	char a[3],c;
	while (cin >> a[0] >> a[1] >> a[2])
	{
		for (i = 0;i < 2;i++)
		{
			for (j = i + 1;j < 3;j++)
			{
				if (a[i] > a[j])
				{
					c = a[i];
					a[i] = a[j];
					a[j] =c;
				}
			}
		}
		printf("%c %c %c\n" , a[0],a[1],a[2]);
	}
}