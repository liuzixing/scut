#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int i,j,n;
	int a[1001];
	while (cin >> n)
	{
		int ans = 0;
		for (i = 0;i < n;i++)
		{
			scanf("%d",a + i);
		}
		for (i = 0; i < n;i++)
		{
			for (j = 1;j < n - i;j++)
			{
				if (a[j] < a[j - 1])
				{
					swap(a[j],a[j - 1]);
					ans ++;
				}
			}
		}
		printf("%d\n",ans);
	}
}