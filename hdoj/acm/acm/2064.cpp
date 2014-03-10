#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int n,i;
	__int64 f[36] = {0};
	f[1] = 2;
	for (i = 2;i < 36;i++)
	{
		f[i] = 3 * f[i - 1] + 2;
	}
	while (scanf("%d",&n) != EOF)
	{
		printf("%I64d\n",f[n]);
	}
}