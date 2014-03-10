#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int n,i;
	__int64 f[41][2];
	f[1][0] = 1 ; f[1][1] = 2;
	for (i = 2;i < 41;i++)
	{
		f[i][0] = f[i - 1][1];
		f[i][1] = (f[i - 1][0] + f[i - 1][1]) * 2;
	}
	while (cin >> n)
	{
		printf("%I64d\n",f[n][0] + f[n][1]);
	}
}