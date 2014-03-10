#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main()
{
	bool hash[32768];
	int t,n,i,j,cn;
	cin >> t;
	while (t--)
	{
		scanf("%d",&n);
		memset(hash,0,sizeof(hash));
		for(i = 2;i <= n / 2;i++)
		{
			if (n % i == 0 && hash[i] == 0)
			{
				for (j = i;j < n;j += i)
				{
					hash[j] = true;
				}
			}
		}
		int ans = 0;
		for (i = 2;i < n;i++)
		{
			if (hash[i] == false)
			{
				ans++;
			}
		}
		printf("%d\n",ans + 1);
	}
	
}