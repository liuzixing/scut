#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int n,i,ans;
	while (cin >> n)
	{
		ans = 0;
		for (i = 1;i <= n;i++)
		{
			if (n  %  i == 0)
			{
				ans ^= 1;
			}
		}
		printf("%d\n",ans);
	}
}