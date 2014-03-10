#include <iostream>
#include <stdio.h>
int n,f[1000001],i;
int main()
{
	
	f[0] = 1;f[1] = 2;

	for (i = 2;i < 1000001;i++)
	{
		f[i]  = (f[i - 1] + f[i - 2]) % 3;
	}
	while (scanf("%d",&n) != EOF)
	{
		printf((f[n] == 0)?"yes\n":"no\n");
	}
}