#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	__int64 f[301] = {0};
	int i,j,n;
	f[0] = 1;
	f[1] = 1;
	for (j = 3;j < 301;j += 2)
	{
		for (i = 300;i >= 0;i--)
		{
			if (i + j < 301)
			{
				f[j + i] += f[i];
			}
		}
	}
	while (scanf("%d",&n) != EOF)
	{
		printf("%I64d\n",f[n]);
	}
}