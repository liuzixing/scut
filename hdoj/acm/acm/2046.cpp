#include <iostream>
#include <stdio.h>

using namespace std;
int main()
{
	__int64 f[51];
	int i,n;
	f[1] = 1;
	f[2] = 2;
	for(i = 3;i < 51;i++)
	{
		f[i] = f[i - 1]+ f[i - 2];
	}
	while (cin >> n)
	{
		printf("%I64d\n",f[n]);
	}
}