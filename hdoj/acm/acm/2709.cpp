#include <iostream>
#include <stdio.h>

using namespace std;
int f[1000001];
int main()
{
	int i,n;
	f[1] = 1;
	f[2] = 2;
	for (i = 3;i < 1000001;i++)
	{
		if (i % 2)
		{
			f[i] = f[i - 1];
		}
		else
		{
			f[i] = (f[i - 2] + f[i / 2] ) % 1000000000;
		}
	}
	while (scanf("%d",&n) != EOF)
	{
		printf("%d\n",f[n]);
	}
}