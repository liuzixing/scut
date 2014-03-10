#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	__int64 f[51],n,i;
	f[1] = 3;f[2] =6;f[3] =6;
	for (i = 4;i < 51;i++)
	{
		f[i] = f[i - 1] + 2 * f[i - 2];
	}
	while (cin >> n)
	{
		printf("%I64d\n",f[n]);
	}
}