#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int f[31] = {0};
	int i,t,n;
	f[1] = 1;
	f[2] = 3;
	for (i = 3;i < 31;i++)
	{
		f[i] = f[i - 2] * 2 + f[i - 1];
	}
	cin >> t;
	while (t--)
	{
		scanf("%d",&n);
		printf("%d\n",f[n]);
	}
}