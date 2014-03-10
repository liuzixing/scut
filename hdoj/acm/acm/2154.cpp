#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int n,f[1001][3],i;
	memset(f,0,sizeof(f));
	f[1][1] = 1;
	f[1][2] = 1;
	for (i = 2;i < 1001;i++)
	{
		f[i][0] = (f[i - 1][1] + f[i - 1][2]) % 10000;
		f[i][1] = (f[i - 1][0] + f[i - 1][2]) % 10000;
		f[i][2] = (f[i - 1][1] + f[i - 1][0]) % 10000;
	}
	while (cin >> n && n)
	{
		printf("%d\n",f[n][0]);
	}
}