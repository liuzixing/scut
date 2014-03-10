#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>

using namespace std;

void createprimenumber(int prime[])
{
	int i,j;
	memset(prime,0,sizeof(int) * 10001);
	prime[1] = 1;
	for (i = 2;i < 100;i++)
	{
		if (!prime[i])
		{
			for (j = i * 2;j < 10001;j += i)
			{
				prime[j] = 1;
			}
		}
	}
	return;
}
int main()
{
	int prime[10001],i,n,ans;
	createprimenumber(prime);
	while (cin >> n && n)
	{
		ans = 0;
		for (i = 2;i < n / 2;i++)
		{
			if ((!prime[i]) && (!prime[n - i]))
			{
				ans ++;
			}
		}
		printf("%d\n",ans);
	}
}