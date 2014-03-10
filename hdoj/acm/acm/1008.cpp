#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n,a[101],i,ans;
	while (cin >> n && n!= 0)
	{
		a[0] = 0;
		ans = n * 5;
		for (i = 1;i <= n;i++)
		{
			scanf("%d",&a[i]);
			if (a[i] > a[i - 1])
			{
			    ans += 6 * (a[i] - a[i - 1]);
			}
			else
			{
				ans += 4 * (a[i - 1] - a[i]);
			}
		}
		printf("%d\n",ans);
	}
}