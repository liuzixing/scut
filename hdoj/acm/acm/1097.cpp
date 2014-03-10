#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int a,b,f[10],i;

	while (scanf("%d %d",&a,&b) != EOF)
	{
		a = a % 10;
		f[0] = 0;
		f[1] = a;
		i = 2;
		f[2] = 10;
		while (1)
		{
			f[i] = f[i - 1] * a % 10;
			if (f[i] == a)
				break;
			i++;
		}
		
		i--;
		f[0] = f[i];
		printf("%d\n",f[b % i]);

	}
}