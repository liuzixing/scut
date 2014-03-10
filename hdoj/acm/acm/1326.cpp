#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int n,a[101],i,sum,ans,c = 0;
	while (cin >> n && n)
	{

		c++;
		sum = 0;
		ans = 0;
		for (i = 0 ;i < n;i++)
		{
			scanf("%d",&a[i]);
			sum += a[i];
		}
		sum /= n;
		for (i = 0 ;i < n;i++)
		{
			if (a[i] - sum > 0)
			{
				ans +=a[i] - sum;
			}
		}
		printf("Set #%d\nThe minimum number of moves is %d.\n\n",c,ans);
	}
}