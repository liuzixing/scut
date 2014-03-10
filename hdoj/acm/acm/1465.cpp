#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	__int64 f[21];
	int i,n;
	f[0] = 0;
	f[1] = 0;f[2] = 1;
	for (i = 3;i < 21;i++)
	{
		f[i] = (i - 1) * (f[i - 1] + f[i - 2]);
	}
	while (cin >> n)
	{
		printf("%I64d\n",f[n]);
	}
}