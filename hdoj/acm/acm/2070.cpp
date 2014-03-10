#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int i,n;
	__int64 f[51];
	f[0] = 0;
	f[1] = 1;
	for (i = 2;i < 51;i++)
	{
		f[i] = f[i - 1] + f[i  - 2];
	}
	while (cin >> n && n >= 0)
	{
		printf("%I64d\n",f[n]);
	}
}