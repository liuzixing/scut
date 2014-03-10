#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int t,n,f[10001],i;
	f[1] = 2;
	for (i = 2;i <= 10000;i++)
	{
		f[i] = f[i - 1] + (i - 1) * 4  + 1;
	}
	cin >> t;
	while (t--)
	{
		scanf("%d",&n);
		printf("%d\n",f[n]);
	}
}