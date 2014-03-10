#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	int n,i,t,f[22] = {0};
	cin >> t;
	f[1] = 3;
	f[2] = 7;
	for(i = 3;i < 21;i++)
	{
		f[i] = f[i - 1] * 2 + f[i - 2];
	}
	while (t--)
	{
		scanf("%d",&n);
		printf("%d\n",f[n]);
	}
}