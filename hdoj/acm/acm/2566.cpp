#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int i,j,k,m,n,t;
	cin >> t;
	while (t--)
	{
		scanf("%d %d",&n,&m);
		int ans = 0;
		for (i = 0;i <= n;i ++)
		{
			for (j = 0;j <= n;j++)
			{
				for (k = 0;k <= n;k++)
				{
					if (i + j * 2 + k * 5 == m && i + j + k == n)
					{
						ans++;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
}